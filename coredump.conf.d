COREDUMP.CONF(5)                                                                               coredump.conf                                                                              COREDUMP.CONF(5)

NAME
       coredump.conf, coredump.conf.d - Core dump storage configuration files

SYNOPSIS
       /etc/systemd/coredump.conf

       /etc/systemd/coredump.conf.d/*.conf

       /run/systemd/coredump.conf.d/*.conf

       /usr/lib/systemd/coredump.conf.d/*.conf

DESCRIPTION
       These files configure the behavior of systemd-coredump(8), a handler for core dumps invoked by the kernel. Whether systemd-coredump is used is determined by the kernel's kernel.core_pattern
       sysctl(8) setting. See systemd-coredump(8) and core(5) pages for the details.

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
       All options are configured in the [Coredump] section:

       Storage=
           Controls where to store cores. One of "none", "external", and "journal". When "none", the core dumps may be logged (including the backtrace if possible), but not stored permanently. When
           "external" (the default), cores will be stored in /var/lib/systemd/coredump/. When "journal", cores will be stored in the journal and rotated following normal journal rotation patterns.

           When cores are stored in the journal, they might be compressed following journal compression settings, see journald.conf(5). When cores are stored externally, they will be compressed by
           default, see below.

       Compress=
           Controls compression for external storage. Takes a boolean argument, which defaults to "yes".

       ProcessSizeMax=
           The maximum size in bytes of a core which will be processed. Core dumps exceeding this size may be stored, but the backtrace will not be generated. Like other sizes in this same config file,
           the usual suffixes to the base of 1024 are allowed (B, K, M, G, T, P, and E). Defaults to 1G on 32bit systems, 32G on 64bit systems.

           Setting Storage=none and ProcessSizeMax=0 disables all coredump handling except for a log entry.

       ExternalSizeMax=, JournalSizeMax=
           The maximum (compressed or uncompressed) size in bytes of a core to be saved in separate files on disk (default: 1G on 32bit, 32G on 64bit systems) or in the journal (default: 10M). Unit
           suffixes are allowed just as in ProcessSizeMax=.

           ExternalSizeMax=infinity sets the core size to unlimited.

       MaxUse=, KeepFree=
           Enforce limits on the disk space, specified in bytes, taken up by externally stored core dumps. Unit suffixes are allowed just as in ProcessSizeMax=.  MaxUse= makes sure that old core dumps
           are removed as soon as the total disk space taken up by core dumps grows beyond this limit (defaults to 10% of the total disk size).  KeepFree= controls how much disk space to keep free at
           least (defaults to 15% of the total disk size). Note that the disk space used by core dumps might temporarily exceed these limits while core dumps are processed. Note that old core dumps are
           also removed based on time via systemd-tmpfiles(8). Set either value to 0 to turn off size-based cleanup.

       The defaults for all values are listed as comments in the template /etc/systemd/coredump.conf file that is installed by default.

SEE ALSO
       systemd-journald.service(8), coredumpctl(1), systemd-tmpfiles(8)

systemd 253                                                                                                                                                                               COREDUMP.CONF(5)
