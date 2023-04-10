JOURNAL-REMOTE.CONF(5)                                                                      journal-remote.conf                                                                     JOURNAL-REMOTE.CONF(5)

NAME
       journal-remote.conf, journal-remote.conf.d - Configuration files for the service accepting remote journal uploads

SYNOPSIS
       /etc/systemd/journal-remote.conf

       /etc/systemd/journal-remote.conf.d/*.conf

       /run/systemd/journal-remote.conf.d/*.conf

       /usr/lib/systemd/journal-remote.conf.d/*.conf

DESCRIPTION
       These files configure various parameters of systemd-journal-remote.service(8). See systemd.syntax(7) for a general description of the syntax.

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
       All options are configured in the [Remote] section:

       Seal=
           Periodically sign the data in the journal using Forward Secure Sealing.

       SplitMode=
           One of "host" or "none".

       ServerKeyFile=
           SSL key in PEM format.

       ServerCertificateFile=
           SSL certificate in PEM format.

       TrustedCertificateFile=
           SSL CA certificate.

       MaxUse=, KeepFree=, MaxFileSize=, MaxFiles=
           These are analogous to SystemMaxUse=, SystemKeepFree=, SystemMaxFileSize= and SystemMaxFiles= in journald.conf(5).

           MaxUse= controls how much disk space the systemd-journal-remote may use up at most.  KeepFree= controls how much disk space systemd-journal-remote shall leave free for other uses.
           systemd-journal-remote will respect both limits and use the smaller of the two values.

           MaxFiles= controls how many individual journal files to keep at most. Note that only archived files are deleted to reduce the number of files until this limit is reached; active files will
           stay around. This means that, in effect, there might still be more journal files around in total than this limit after a vacuuming operation is complete.

SEE ALSO
       journald.conf(5), systemd(1), systemd-journal-remote.service(8), systemd-journald.service(8)

systemd 253                                                                                                                                                                         JOURNAL-REMOTE.CONF(5)
