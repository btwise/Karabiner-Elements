#include "components_manager.hpp"
#include "constants.hpp"
#include "dispatcher_utility.hpp"
#include "filesystem.hpp"
#include "karabiner_version.h"
#include "logger.hpp"
#include "process_utility.hpp"
#include "spdlog_utility.hpp"
#include <iostream>
#include <sstream>
#include <unistd.h>

int main(int argc, const char* argv[]) {
  krbn::dispatcher_utility::initialize_dispatchers();

  if (getuid() != 0) {
    std::cerr << "fatal: karabiner_observer 需要root权限。" << std::endl;
    exit(1);
  }

  signal(SIGUSR1, SIG_IGN);
  signal(SIGUSR2, SIG_IGN);

  // Setup logger

  krbn::logger::set_async_rotating_logger("observer",
                                          "/var/log/karabiner/observer.log",
                                          0755);

  krbn::logger::get_logger().info("version {0}", karabiner_version);

  // Check another process

  {
    std::string pid_file_path = krbn::constants::get_pid_directory() + "/karabiner_observer.pid";
    if (!krbn::process_utility::lock_single_application(pid_file_path)) {
      auto message = "退出，因为另一个进程正在运行.";
      krbn::logger::get_logger().info(message);
      std::cerr << message << std::endl;
      exit(1);
    }
  }

  // Run components_manager

  auto components_manager = std::make_unique<krbn::components_manager>();

  CFRunLoopRun();

  components_manager = nullptr;

  krbn::logger::get_logger().info("karabiner_observer 被终止.");

  krbn::dispatcher_utility::terminate_dispatchers();

  return 0;
}
