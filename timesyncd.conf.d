TIMESYNCD.CONF(5)                                                                             timesyncd.conf                                                                             TIMESYNCD.CONF(5)

NAME
       timesyncd.conf, timesyncd.conf.d - Network Time Synchronization configuration files

SYNOPSIS
       /etc/systemd/timesyncd.conf

       /etc/systemd/timesyncd.conf.d/*.conf

       /run/systemd/timesyncd.conf.d/*.conf

       /usr/lib/systemd/timesyncd.conf.d/*.conf

DESCRIPTION
       These configuration files control NTP network time synchronization. See systemd.syntax(7) for a general description of the syntax.

CONFIGURATION DIRECTORIES AND PRECEDENCE
       The default configuration is set during compilation, so configuration is only needed when it is necessary to deviate from those defaults. Initially, the main configuration file in /etc/systemd/
       contains commented out entries showing the defaults as a guide to the administrator. Local overrides can be created by editing this file or by creating drop-ins, as described below. Using
       drop-ins for local configuration is recommended over modifications to the main configuration file.

       In addition to the "main" configuration file, drop-in configuration snippets are read from /usr/lib/systemd/*.conf.d/, /usr/local/lib/systemd/*.conf.d/, and /etc/systemd/*.conf.d/. Those drop-ins
       have higher precedence and override the main configuration file. Files in the *.conf.d/ configuration subdirectories are sorted by their filename in lexicographic order, regardless of in which of
       the subdirectories they reside. When multiple files specify the same option, for options which accept just a single value, the entry in the file sorted last takes precedence, and for options
       which accept a list of values, entries are collected as they occur in the sorted files.

       When packages need to customize the configuration, they can install drop-ins under /usr/. Files in /etc/ are reserved for the local administrator, who may use this logic to override the
       configuration files installed by vendor packages. Drop-ins have to be used to override package drop-ins, since the main configuration file has lower precedence. It is recommended to prefix all
       filenames in those subdirectories with a two-digit number and a dash, to simplify the ordering of the files.

       To disable a configuration file supplied by the vendor, the recommended way is to place a symlink to /dev/null in the configuration directory in /etc/, with the same filename as the vendor
       configuration file.

OPTIONS
       The following settings are configured in the [Time] section:

       NTP=
           A space-separated list of NTP server host names or IP addresses. During runtime this list is combined with any per-interface NTP servers acquired from systemd-networkd.service(8).
           systemd-timesyncd will contact all configured system or per-interface servers in turn, until one responds. When the empty string is assigned, the list of NTP servers is reset, and all prior
           assignments will have no effect. This setting defaults to an empty list.

       FallbackNTP=
           A space-separated list of NTP server host names or IP addresses to be used as the fallback NTP servers. Any per-interface NTP servers obtained from systemd-networkd.service(8) take precedence
           over this setting, as do any servers set via NTP= above. This setting is hence only relevant if no other NTP server information is known. When the empty string is assigned, the list of NTP
           servers is reset, and all prior assignments will have no effect. If this option is not given, a compiled-in list of NTP servers is used.

       RootDistanceMaxSec=
           Maximum acceptable root distance, i.e. the maximum estimated time required for a packet to travel to the server we are connected to from the server with the reference clock. If the current
           server does not satisfy this limit, systemd-timesyncd will switch to a different server.

           Takes a time span value. The default unit is seconds, but other units may be specified, see systemd.time(5). Defaults to 5 seconds.

       PollIntervalMinSec=, PollIntervalMaxSec=
           The minimum and maximum poll intervals for NTP messages. Polling starts at the minimum poll interval, and is adjusted within the specified limits in response to received packets.

           Each setting takes a time span value. The default unit is seconds, but other units may be specified, see systemd.time(5).  PollIntervalMinSec= defaults to 32 seconds and must not be smaller
           than 16 seconds.  PollIntervalMaxSec= defaults to 34 min 8 s (2048 seconds) and must be larger than PollIntervalMinSec=.

       ConnectionRetrySec=
           Specifies the minimum delay before subsequent attempts to contact a new NTP server are made.

           Takes a time span value. The default unit is seconds, but other units may be specified, see systemd.time(5). Defaults to 30 seconds and must not be smaller than 1 second.

       SaveIntervalSec=
           The interval at which the current time is periodically saved to disk, in the absence of any recent synchronisation from an NTP server. This is especially useful for offline systems with no
           local RTC, as it will guarantee that the system clock remains roughly monotonic across reboots.

           Takes a time interval value. The default unit is seconds, but other units may be specified, see systemd.time(5). Defaults to 60 seconds.

SEE ALSO
       systemd(1), systemd-timesyncd.service(8), systemd-networkd.service(8)

systemd 253                                                                                                                                                                              TIMESYNCD.CONF(5)
