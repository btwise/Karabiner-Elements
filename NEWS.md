# Changelog

## Beta

-   ⚡️ Improvements
    -   Added a workaround for non-dismissible `Device is ignored temporarily` alert
        which is caused by some devices that sends abnormal input events.

## Karabiner-Elements 12.8.0

-   ✨ New Features
    -   Add `--show-current-profile-name` option into `karabiner_cli`.
    -   Add `--list-profile-names` option into `karabiner_cli`.
-   🐛 Bug Fixes
    -   Fixed an issue that Karabiner-Elements stops working after switching user on macOS Catalina.
    -   Fixed an issue that Caps Lock LED is always manipulated even `Manipulate LED` setting is off.
    -   Fixed an issue that MultitouchExtension does not handle ignored area properly when a finger is touched ignored area repeatedly.

## Karabiner-Elements 12.7.0

-   📅 Release date
    -   Sep 12, 2019
-   ✨ New Features
    -   MultitouchExtension app has been added.
        -   Documentation:
            -   [Usage](https://pqrs.org/osx/karabiner/document.html#multitouch-extension)
            -   [How to integrate MultitouchExtension to your complex modifications](https://pqrs.org/osx/karabiner/json.html#multitouch-extension)
    -   Dark Mode has been supported.
    -   Added `--set-variables` option into `karabiner_cli`.
-   🐛 Bug Fixes
    -   Fixed an issue that Karabiner-Elements might stop working after sleep on macOS Catalina.

## Karabiner-Elements 12.6.0

-   📅 Release date
    -   Aug 16, 2019
-   ✨ New Features
    -   Support macOS Catalina.<br/>
        (You need [an extra configuration](https://pqrs.org/osx/karabiner/document.html#usage-catalina) on macOS Catalina.)
-   🐛 Bug Fixes
    -   Fixed an issue that Karabiner-Elements fails to grab a device in rare cases.
-   ⚡️ Improvements
    -   Introduced karabiner_kextd.
        (kext loading function was separated from karabiner_grabber.)
    -   Improved EventViewer to show modifier flags of key events.
    -   Suppressed unnecessary log messages.

## Karabiner-Elements 12.5.0

-   📅 Release date
    -   Jun 10, 2019
-   ✨ New Features
    -   Add `Delay before open device` configuration into `Karabiner-Elements Preferences > Devices > Advanced` tab.
    -   Added `Show key code in hexadecimal format` option into EventViewer.
-   🐛 Bug Fixes
    -   Fixed a key stuck issue which occurs when the key is released,
        and at the exact same moment Karabiner-Elements opens the device.
    -   Fixed an issue which Karabiner-Elements mistakes a remote user for a current console user
        if another user is logged in from Screen Sharing while console is used.
-   ⚡️ Improvements
    -   Improved `XXX is ignored temporarily until YYY is pressed again` behavior.
    -   Move `Disable the built-in keyboard while one of the following selected devices is connected` configuration
        into `Karabiner-Elements Preferences > Devices > Advanced` tab.

## Karabiner-Elements 12.4.0

-   📅 Release date
    -   May 14, 2019
-   ✨ New Features
    -   Add `Mouse Key XY speed` configuration into `Karabiner-Elements Preferences > Virtual Keyboard` tab.
    -   `Device is ignored temporarily` alert has been introduced.<br/>
        This alert will be shown if you hold keys or buttons down before Karabiner-Elements opens the device.<br/>
        Please press the described key or button again to dismiss the alert.<br/>
        <img src="https://pqrs.org/osx/karabiner/img/news/v12.4.0_0.png" alt="alert" style="width: 420px" />
-   🐛 Bug Fixes
    -   Fixed a key stuck issue which occurs when the key is held down before Karabiner-Elements opens the device.
-   ⚡️ Improvements
    -   Event code format on EventViewer changed to decimal number from hex.

## Karabiner-Elements 12.3.0

-   📅 Release date
    -   Apr 24, 2019
-   💥 Breaking changes
    -   complex modifications json will be checked strictly since this release.<br/>
        Please check [error messages](https://pqrs.org/osx/karabiner/json.html#location) if your complex modifications do not work after upgrade.
-   ✨ New Features
    -   Added [Change mouse motion to scroll](https://pqrs.org/osx/karabiner/complex_modifications/#mouse_motion_to_scroll) feature.<br/>
        -   Note: You have to enable your mice on [Devices tab](https://pqrs.org/osx/karabiner/document.html#configuration-devices) when you want to use this feature.
    -   Added `--lint-complex-modifications` option into `karabiner_cli`.
        It allows you checks a complex-modifications json file.
-   ⚡️ Improvements
    -   Set Karabiner-Elements.app and Karabiner-EventViewer.app immutable
        in order to ensure unremovable them except built-in uninstaller.
        Please use the [uninstaller](https://pqrs.org/osx/karabiner/document.html#uninstall) when you want to remove Karabiner-Elements.
    -   Added a wait before grabbing device in order to avoid an macOS issue that device will be unusable after Karabiner-Elements is quit.
    -   Changes for users who write their own json.
        -   `to` and `to_*` support single object, e.g., `"to": { "key_code": "spacebar" }`.
        -   New modifier aliases are added: `left_alt`, `left_gui`, `right_alt`, `right_gui`.
        -   `key_code`, `consumer_key_code` and `pointing_button` supports a number value, e.g., `"from": {"key_code": 175}`.

## Karabiner-Elements 12.2.0

-   📅 Release date
    -   Feb 1, 2019
-   ✨ New Features
    -   Karabiner-Elements makes a backup file of karabiner.json before updating it if the backup file does not exists.
        (~/.config/karabiner/automatic_backups/karabiner_YYYYMMDD.json)
-   🐛 Bug Fixes
    -   Fixed an issue that Caps Lock LED does not work on macOS Mojave.
-   ⚡️ Improvements
    -   `shell_command` string max length has been expanded. (256 byte -> 32 KB)
    -   A device grabbing process has been improved. (Observing device state by a separated `karabiner_observer` process.)
    -   The event processing has been improved and the latency has been reduced by using [pqrs::dispatcher](https://github.com/pqrs-org/cpp-dispatcher).

## Karabiner-Elements 12.1.0

-   📅 Release date
    -   May 30, 2018
-   💥 Breaking changes
    -   Changed the order of `to_if_alone` and `to_after_key_up` event handling.<br />
        `to_if_alone` will be handled before `to_after_key_up`.
-   ✨ New Features
    -   Added new items into `simultaneous_options`:
        -   `simultaneous_options.detect_key_down_uninterruptedly`
        -   `simultaneous_options.key_up_when`
    -   Added new parameters into `to event definition`:
        -   `hold_down_milliseconds`
        -   `halt`
-   🐛 Bug Fixes
    -   Fixed an issue that random key repeat happen at extremely high system CPU usage.
-   ⚡️ Improvements
    -   Increased rollover limit of virtual keyboard. (6 -&gt; 32)<br />
        This change mainly improves usability when you are using multiple keyboards at the same time.
    -   Improved modifier flags handling in `to_after_key_up` and `to_if_alone`.

## Karabiner-Elements 12.0.0

-   📅 Release date
    -   Apr 12, 2018
-   💥 Breaking changes
    -   macOS 10.11 support has been dropped.<br />
        Karabiner-Elements works on macOS 10.12 (Sierra) or later.
    -   `Keyboard type` in the virtual keyboard preferences has been removed. (Adverse effect of virtual keyboard improvement.)<br />
        Please change the keyboard type from `System Preferences > Keyboard > Change Keyboard Type...`.
        <img src="https://pqrs.org/osx/karabiner/img/news/v12.0.0_0.png" alt="Keyboard Preferences" style="width: 668px" />
    -   `Caps Lock Delay` in the virtual keyboard preferences has been removed. (Adverse effect of virtual keyboard improvement.)
    -   Changed `simultaneous` behaviour to post key_up events when any key is released.
    -   Changed `to_after_key_up` and `to_if_alone` behaviour as mandatory modifiers are removed from these events.
-   ✨ New Features
    -   Added `simultaneous_options.key_down_order`, `simultaneous_options.key_up_order` and `simultaneous_options.to_after_key_up`.
-   🐛 Bug Fixes
    -   Fixed an issue that `to_if_alone`, `to_if_held_down` and `to_delayed_action` does not work properly with `simultaneous`.
-   ⚡️ Improvements
    -   The virtual keyboard compatibility has been improved.
    -   EventViewer has been improved showing the correct key name for PC keyboard keys and international keys.
    -   Improved keyboard repeat handling with `simultaneous`.

## Karabiner-Elements 11.6.0

-   📅 Release date
    -   Feb 20, 2018
-   ✨ New Features
    -   Simultaneous key presses has been supported in complex modifications.
        -   [json example](https://pqrs.org/osx/karabiner/json.html#typical-complex_modifications-examples-simultaneous-equal-delete-to-forward-delete)
        -   [Document](https://pqrs.org/osx/karabiner/json.html#simultaneous)
-   ⚡️ Improvements
    -   Improved Mouse key scroll wheel direction referring `System Preferences > Mouse > Scroll direction`.
    -   Improved modifier flags handling around pointing button manipulations.
    -   Mouse keys have been added into Simple Modifications.
        <img src="https://pqrs.org/osx/karabiner/img/news/v11.6.0_0.png" alt="mouse keys in Simple Modifications" style="width: 1000px" />
    -   The eject key has been added into the from key of Simple Modifications.
    -   The Vendor ID and Product ID of virtual devices has been changed. (0x0,0x0 -> 0x16c0,0x27db and 0x16c0,0x27da)

## Karabiner-Elements 11.5.0

-   📅 Release date
    -   Dec 30, 2017
-   ✨ New Features
    -   `to_if_held_down` has been added.
        -   Examples:
            -   [Open Alfred 3 if escape is held down](https://pqrs.org/osx/karabiner/json.html#typical-complex_modifications-examples-open-alfred-when-escape-is-held-down)
            -   [Quit application by holding command-q](https://pqrs.org/osx/karabiner/complex_modifications/#command_q)
-   🐛 Bug Fixes
    -   Avoided a VMware Remote Console issue that mouse pointer does not work properly on VMRC when Karabiner-Elements grabs the pointing device.
    -   Fixed an issue that `to_if_alone` does not work properly when `to` is empty.
-   ⚡️ Improvements
    -   Improved modifier flags handling in `to events`.
    -   Improved a way to save karabiner.json.

## Karabiner-Elements 11.4.0

-   📅 Release date
    -   Dec 7, 2017
-   ✨ New Features
    -   `mouse_key` has been added.
        -   Examples:
            -   Mouse keys (simple):
                [json](https://github.com/pqrs-org/KE-complex_modifications/blob/master/docs/json/mouse_keys_simple.json)
                [(src)](https://github.com/pqrs-org/KE-complex_modifications/blob/master/src/json/mouse_keys_simple.json.erb)
            -   Mouse keys (full)
                [json](https://github.com/pqrs-org/KE-complex_modifications/blob/master/docs/json/mouse_keys_full.json)
                [(src)](https://github.com/pqrs-org/KE-complex_modifications/blob/master/src/json/mouse_keys_full.json.erb)
    -   `location_id` has been added to `device_if` and `device_unless`.
-   🐛 Bug Fixes
    -   Fixed an issue that the checkbox in `Preferences > Devices` is disabled for keyboards which do not have their own vendor id.

## Karabiner-Elements 11.3.0

-   📅 Release date
    -   Nov 12, 2017
-   🐛 Bug Fixes
    -   Fixed an issue that Karabiner-11.2.0 does not work properly on some environments due to a possibility of macOS kernel extension cache problem.

## Karabiner-Elements 11.2.0

-   📅 Release date
    -   Nov 9, 2017
-   ✨ New Features
    -   Mouse button modifications has been added.<br />
        Note:
        -   You have to enable your Mouse manually in Preferences &gt; Devices tab.
        -   Karabiner-Elements cannot modify Apple's pointing devices.
    -   `to_delayed_action` has been added.
        -   Examples:
            -   Quit application by pressing command-q twice
                [json](https://github.com/pqrs-org/KE-complex_modifications/blob/master/docs/json/command_q.json)
                [(src)](https://github.com/pqrs-org/KE-complex_modifications/blob/master/src/json/command_q.json.erb)
            -   Emacs key bindings (C-x key strokes)
                [json](https://github.com/pqrs-org/KE-complex_modifications/blob/master/docs/json/emacs_key_bindings.json)
                [(src)](https://github.com/pqrs-org/KE-complex_modifications/blob/master/src/json/emacs_key_bindings.json.rb)
    -   `input_source_if` and `input_source_unless` has been added to `conditions`.
        -   [Document](https://pqrs.org/osx/karabiner/json.html#condition-definition-input-source)
        -   Example:
            -   [example_input_source.json](https://github.com/pqrs-org/KE-complex_modifications/blob/master/docs/json/example_input_source.json)
    -   `select_input_source` has been added.
        -   [Document](https://pqrs.org/osx/karabiner/json.html#to-event-definition)
        -   Example:
            -   [example_select_input_source.json](https://github.com/pqrs-org/KE-complex_modifications/blob/master/docs/json/example_select_input_source.json)
    -   `keyboard_type_if` and `keyboard_type_unless` has been added to `conditions`.
        -   Example
            -   Change control-[ to escape
                [json](https://github.com/pqrs-org/KE-complex_modifications/blob/master/docs/json/example_keyboard_type.json)
                [(src)](https://github.com/pqrs-org/KE-complex_modifications/blob/master/src/json/example_keyboard_type.json.erb)
    -   The caps lock LED manipulation has been disabled with non Apple keyboards until it is enabled manually.
        <img src="https://pqrs.org/osx/karabiner/img/news/v11.1.16_0.png" alt="has caps lock led" style="width: 1000px" />
-   ⚡️ Improvements
    -   The virtual keyboard handling has been improved.

## Karabiner-Elements 11.1.0

-   📅 Release date
    -   Oct 4, 2017
-   🐛 Bug Fixes
    -   Fixed an issue that modifier flags becomes improperly state by mouse events.

## Karabiner-Elements 11.0.0

-   📅 Release date
    -   Sep 18, 2017
-   ✨ New Features
    -   The first stable release of Karabiner-Elements.
        (There is no changes from Karabiner-Elements 0.91.16.)

## Karabiner-Elements 0.91.16

-   Karabiner-Elements waits grabbing device until all modifier keys are released in order to avoid modifier flags stuck issue in mouse events.
-   Support consumer keys (e.g., media key events in Logitech keyboards.)

## Karabiner-Elements 0.91.13

-   Add per device support in `Simple Modifications` and `Fn Function Keys`.
    ![Simple Modifications](https://pqrs.org/osx/karabiner/img/news/v0.91.13_0.png)
-   The modifier flag event handling has been improved.

## Karabiner-Elements 0.91.12

-   `device_if` and `device_unless` has been added to `conditions`.
    -   An example: <https://github.com/pqrs-org/KE-complex_modifications/blob/master/docs/json/example_device.json>

## Karabiner-Elements 0.91.11

-   Fixed an issue that modifier flags might become improperly state in complex_modifications.
    (In complex_modifications rules which changes modifier+modifier to modifier.)

## Karabiner-Elements 0.91.10

-   macOS 10.13 (High Sierra) support has been improved.

## Karabiner-Elements 0.91.9

-   `variable_if` and `variable_unless` has been added to `conditions`.
    You can use `set_variable` to change the variables.
    -   An example: <https://github.com/pqrs-org/KE-complex_modifications/blob/ef8074892e5fff8a4781a898869f8d341b5a815a/docs/json/personal_tekezo.json>
-   `to_after_key_up` has been added to `complex_modifications > basic`.
-   `"from": { "any": "key_code" }` has been added to `complex_modifications > basic`.
    You can use this to disable untargeted keys in your mode. (e.g., disable untargeted keys in Launcher Mode.)
    -   An example: <https://github.com/pqrs-org/KE-complex_modifications/blob/ef8074892e5fff8a4781a898869f8d341b5a815a/docs/json/personal_tekezo.json#L818-L844>
-   `Variables` tab has been added into `EventViewer`.
    You can confirm the `set_variable` result in `Variables` tab.

## Karabiner-Elements 0.91.8

-   Fixed an issue that karabiner_grabber might be crashed when frontmost application is changed.

## Karabiner-Elements 0.91.7

-   Shell command execution has been supported. (e.g., Launch apps in <https://pqrs.org/osx/karabiner/complex_modifications/> )

## Karabiner-Elements 0.91.6

-   The conditional event manipulation has been supported. (`frontmost_application_if` and `frontmost_application_unless`)

## Karabiner-Elements 0.91.5

-   GUI for complex_modifications has been added. <https://github.com/pqrs-org/Karabiner-Elements/tree/master/usage#how-to-use-complex-modifications>
-   Syntax of `complex_modifications > parameters` has been changed.

## Karabiner-Elements 0.91.4

-   The modifier flag event handling has been improved.
-   Show warning and error logs by colored text in Log tab.

## Karabiner-Elements 0.91.3

-   Add timeout to `to_if_alone`.

## Karabiner-Elements 0.91.2

-   Initial support of `complex_modifications > basic > to_if_alone`.

## Karabiner-Elements 0.91.1

-   Fixed an issue that Karabiner-Elements stops working after user switching.
-   Initial support of `complex_modifications` (No GUI yet).

## Karabiner-Elements 0.91.0

-   event manipulation has been changed to `src/core/grabber/include/manipulator/details/basic.hpp`.
