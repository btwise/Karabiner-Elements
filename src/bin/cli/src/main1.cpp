#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include "cxxopts/cxxopts.hpp"
#pragma clang diagnostic pop

#include "constants.hpp"
#include "dispatcher_utility.hpp"
#include "logger.hpp"
#include "monitor/configuration_monitor.hpp"
#include <iostream>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace {
void select_profile(const std::string& name) {
  auto wait = pqrs::dispatcher::make_wait();
  krbn::configuration_monitor monitor(krbn::constants::get_user_core_configuration_file_path());

  monitor.core_configuration_updated.connect([name, wait](auto&& weak_core_configuration) {
    if (auto core_configuration = weak_core_configuration.lock()) {
      auto& profiles = core_configuration->get_profiles();
      for (size_t i = 0; i < profiles.size(); ++i) {
        if (profiles[i].get_name() == name) {
          core_configuration->select_profile(i);
          core_configuration->sync_save_to_file();
          goto finish;
        }
      }
      krbn::logger::get_logger().error("`{0}` is not found.", name);
    }

  finish:
    wait->notify();
  });

  monitor.async_start();

  wait->wait_notice();
}

int copy_current_profile_to_system_default_profile(void) {
  krbn::filesystem::create_directory_with_intermediate_directories(krbn::constants::get_system_configuration_directory(), 0755);
  krbn::filesystem::copy(krbn::constants::get_user_core_configuration_file_path(),
                         krbn::constants::get_system_core_configuration_file_path());
  return 0;
}

int remove_system_default_profile(void) {
  if (!krbn::filesystem::exists(krbn::constants::get_system_core_configuration_file_path())) {
    krbn::logger::get_logger().error("{0} is not found.", krbn::constants::get_system_core_configuration_file_path());
    return 1;
  }
  if (unlink(krbn::constants::get_system_core_configuration_file_path()) != 0) {
    krbn::logger::get_logger().error("Failed to unlink {0}.");
    return 1;
  }
  return 0;
}
} // namespace

int main(int argc, const char** argv) {
  int exit_code = 0;

  krbn::dispatcher_utility::initialize_dispatchers();

  {
    auto l = spdlog::stdout_color_mt("karabiner_cli");
    l->set_pattern("[%l] %v");
    l->set_level(spdlog::level::err);
    krbn::logger::set_logger(l);
  }

  cxxopts::Options options("karabiner_cli", "Karabiner-Elements的命令行实用程序.");

  options.add_options()("select-profile", "按名称选择配置文件.", cxxopts::value<std::string>());
  options.add_options()("copy-current-profile-to-system-default-profile", "将当前配置文件复制到系统默认配置文件.");
  options.add_options()("remove-system-default-profile", "删除系统默认配置文件.");
  options.add_options()("help", "打印帮助.");

  try {
    auto parse_result = options.parse(argc, argv);

    {
      std::string key = "select-profile";
      if (parse_result.count(key)) {
        select_profile(parse_result[key].as<std::string>());
        goto finish;
      }
    }

    {
      std::string key = "copy-current-profile-to-system-default-profile";
      if (parse_result.count(key)) {
        if (getuid() != 0) {
          krbn::logger::get_logger().error("--{0} 需要root权限.", key);
          exit_code = 1;
          goto finish;
        }
        exit_code = copy_current_profile_to_system_default_profile();
        goto finish;
      }
    }

    {
      std::string key = "remove-system-default-profile";
      if (parse_result.count(key)) {
        if (getuid() != 0) {
          krbn::logger::get_logger().error("--{0} 需要root权限.", key);
          exit_code = 1;
          goto finish;
        }
        exit_code = remove_system_default_profile();
        goto finish;
      }
    }

  } catch (const cxxopts::OptionException& e) {
    std::cout << "error parsing options: " << e.what() << std::endl;
    exit_code = 2;
    goto finish;
  }

  std::cout << options.help() << std::endl;
  std::cout << "Examples:" << std::endl;
  std::cout << "  karabiner_cli --select-profile 'Default profile'" << std::endl;
  std::cout << std::endl;

  exit_code = 1;

finish:
  krbn::dispatcher_utility::terminate_dispatchers();

  return exit_code;
}
