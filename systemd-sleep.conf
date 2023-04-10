SYSTEMD-SLEEP.CONF(5)         systemd-sleep.conf         SYSTEMD-SLEEP.CONF(5)

NAME
       systemd-sleep.conf, sleep.conf.d - Suspend and hibernation
       configuration file

SYNOPSIS
       /etc/systemd/sleep.conf

       /etc/systemd/sleep.conf.d/*.conf

       /run/systemd/sleep.conf.d/*.conf

       /usr/lib/systemd/sleep.conf.d/*.conf

DESCRIPTION
       systemd supports four general power-saving modes:

       suspend
           a low-power state where execution of the OS is paused, and complete
           power loss might result in lost data, and which is fast to enter
           and exit. This corresponds to suspend, standby, or freeze states as
           understood by the kernel.

       hibernate
           a low-power state where execution of the OS is paused, and complete
           power loss does not result in lost data, and which might be slow to
           enter and exit. This corresponds to the hibernation as understood
           by the kernel.

       hybrid-sleep
           a low-power state where execution of the OS is paused, which might
           be slow to enter, and on complete power loss does not result in
           lost data but might be slower to exit in that case. This mode is
           called suspend-to-both by the kernel.

       suspend-then-hibernate
           A low power state where the system is initially suspended (the
           state is stored in RAM). If the system supports low-battery alarms
           (ACPI _BTP), then the system will be woken up by the ACPI
           low-battery signal and hibernated (the state is then stored on
           disk). Also, if not interrupted within the timespan specified by
           HibernateDelaySec= or the estimated timespan until the system
           battery charge level goes down to 5%, then the system will be woken
           up by the RTC alarm and hibernated. The estimated timespan is
           calculated from the change of the battery capacity level after the
           time specified by SuspendEstimationSec= or when the system is woken
           up from the suspend.

       Settings in these files determine what strings will be written to
       /sys/power/disk and /sys/power/state by systemd-sleep(8) when
       systemd(1) attempts to suspend or hibernate the machine. See
       systemd.syntax(7) for a general description of the syntax.

CONFIGURATION DIRECTORIES AND PRECEDENCE
       The default configuration is set during compilation, so configuration
       is only needed when it is necessary to deviate from those defaults.
       Initially, the main configuration file in /etc/systemd/ contains
       commented out entries showing the defaults as a guide to the
       administrator. Local overrides can be created by editing this file or
       by creating drop-ins, as described below. Using drop-ins for local
       configuration is recommended over modifications to the main
       configuration file.

       In addition to the "main" configuration file, drop-in configuration
       snippets are read from /usr/lib/systemd/*.conf.d/,
       /usr/local/lib/systemd/*.conf.d/, and /etc/systemd/*.conf.d/. Those
       drop-ins have higher precedence and override the main configuration
       file. Files in the *.conf.d/ configuration subdirectories are sorted by
       their filename in lexicographic order, regardless of in which of the
       subdirectories they reside. When multiple files specify the same
       option, for options which accept just a single value, the entry in the
       file sorted last takes precedence, and for options which accept a list
       of values, entries are collected as they occur in the sorted files.

       When packages need to customize the configuration, they can install
       drop-ins under /usr/. Files in /etc/ are reserved for the local
       administrator, who may use this logic to override the configuration
       files installed by vendor packages. Drop-ins have to be used to
       override package drop-ins, since the main configuration file has lower
       precedence. It is recommended to prefix all filenames in those
       subdirectories with a two-digit number and a dash, to simplify the
       ordering of the files.

       To disable a configuration file supplied by the vendor, the recommended
       way is to place a symlink to /dev/null in the configuration directory
       in /etc/, with the same filename as the vendor configuration file.

OPTIONS
       The following options can be configured in the [Sleep] section of
       /etc/systemd/sleep.conf or a sleep.conf.d file:

       AllowSuspend=, AllowHibernation=, AllowSuspendThenHibernate=,
       AllowHybridSleep=
           By default any power-saving mode is advertised if possible (i.e.
           the kernel supports that mode, the necessary resources are
           available). Those switches can be used to disable specific modes.

           If AllowHibernation=no or AllowSuspend=no is used, this implies
           AllowSuspendThenHibernate=no and AllowHybridSleep=no, since those
           methods use both suspend and hibernation internally.
           AllowSuspendThenHibernate=yes and AllowHybridSleep=yes can be used
           to override and enable those specific modes.

       SuspendMode=, HibernateMode=, HybridSleepMode=
           The string to be written to /sys/power/disk by, respectively,
           systemd-suspend.service(8), systemd-hibernate.service(8), or
           systemd-hybrid-sleep.service(8). More than one value can be
           specified by separating multiple values with whitespace. They will
           be tried in turn, until one is written without error. If neither
           succeeds, the operation will be aborted.

           systemd-suspend-then-hibernate.service(8) uses the value of
           SuspendMode= when suspending and the value of HibernateMode= when
           hibernating.

       SuspendState=, HibernateState=, HybridSleepState=
           The string to be written to /sys/power/state by, respectively,
           systemd-suspend.service(8), systemd-hibernate.service(8), or
           systemd-hybrid-sleep.service(8). More than one value can be
           specified by separating multiple values with whitespace. They will
           be tried in turn, until one is written without error. If neither
           succeeds, the operation will be aborted.

           systemd-suspend-then-hibernate.service(8) uses the value of
           SuspendState= when suspending and the value of HibernateState= when
           hibernating.

       HibernateDelaySec=
           The amount of time the system spends in suspend mode before the
           system is automatically put into hibernate mode. Only used by
           systemd-suspend-then-hibernate.service(8). If the system has a
           battery, then defaults to the estimated timespan until the system
           battery charge level goes down to 5%. If the system has no battery,
           then defaults to 2h.

       SuspendEstimationSec=
           The RTC alarm will wake the system after the specified timespan to
           measure the system battery capacity level and estimate battery
           discharging rate, which is used for estimating timespan until the
           system battery charge level goes down to 5%. Only used by systemd-
           suspend-then-hibernate.service(8). Defaults to 1h.

EXAMPLE: FREEZE
       Example: to exploit the “freeze” mode added in Linux 3.9, one can use
       systemctl suspend with

           [Sleep]
           SuspendState=freeze

SEE ALSO
       systemd-sleep(8), systemd-suspend.service(8), systemd-
       hibernate.service(8), systemd-hybrid-sleep.service(8), systemd-suspend-
       then-hibernate.service(8), systemd(1), systemd.directives(7)

systemd 253                                              SYSTEMD-SLEEP.CONF(5)
