JOURNAL-UPLOAD.CONF(5)                                                                      journal-upload.conf                                                                     JOURNAL-UPLOAD.CONF(5)

NAME
       journal-upload.conf, journal-upload.conf.d - Configuration files for the journal upload service

SYNOPSIS
       /etc/systemd/journal-upload.conf

       /etc/systemd/journal-upload.conf.d/*.conf

       /run/systemd/journal-upload.conf.d/*.conf

       /usr/lib/systemd/journal-upload.conf.d/*.conf

DESCRIPTION
       These files configure various parameters of systemd-journal-upload.service(8). See systemd.syntax(7) for a general description of the syntax.

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
       All options are configured in the [Upload] section:

       URL=
           The URL to upload the journal entries to. See the description of --url= option in systemd-journal-upload(8) for the description of possible values. There is no default value, so either this
           option or the command-line option must be always present to make an upload.

       ServerKeyFile=
           SSL key in PEM format.

       ServerCertificateFile=
           SSL CA certificate in PEM format.

       TrustedCertificateFile=
           SSL CA certificate.

       NetworkTimeoutSec=
           When network connectivity to the server is lost, this option configures the time to wait for the connectivity to get restored. If the server is not reachable over the network for the
           configured time, systemd-journal-upload exits. Takes a value in seconds (or in other time units if suffixed with "ms", "min", "h", etc). For details, see systemd.time(5).

SEE ALSO
       systemd-journal-upload.service(8), systemd(1), systemd-journald.service(8)

systemd 253                                                                                                                                                                         JOURNAL-UPLOAD.CONF(5)
