HOMED.CONF(5)                                                                                   homed.conf                                                                                   HOMED.CONF(5)

NAME
       homed.conf, homed.conf.d - Home area/user account manager configuration files

SYNOPSIS
       /etc/systemd/homed.conf

       /etc/systemd/homed.conf.d/*.conf

       /run/systemd/homed.conf.d/*.conf

       /usr/lib/systemd/homed.conf.d/*.conf

DESCRIPTION
       These configuration files control default parameters for home areas/user accounts created and managed by systemd-homed.service(8).

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
       The following options are available in the [Home] section:

       DefaultStorage=
           The default storage to use for home areas. Takes one of "luks", "fscrypt", "directory", "subvolume", "cifs". For details about these options, see homectl(1). If not configured or assigned the
           empty string, the default storage is automatically determined: if not running in a container environment and /home/ is not itself encrypted, defaults to "luks". Otherwise defaults to
           "subvolume" if /home/ is on a btrfs file system, and "directory" otherwise. Note that the storage selected on the homectl command line always takes precedence.

       DefaultFileSystemType=
           When using "luks" as storage (see above), selects the default file system to use inside the user's LUKS volume. Takes one of "btrfs", "ext4" or "xfs". If not specified defaults to "btrfs".
           This setting has no effect if a different storage mechanism is used. The file system type selected on the homectl command line always takes precedence.

SEE ALSO
       systemd(1), systemd-homed.service(8)

systemd 253                                                                                                                                                                                  HOMED.CONF(5)
