PSTORE.CONF(5)                    pstore.conf                   PSTORE.CONF(5)

NAME
       pstore.conf, pstore.conf.d - PStore configuration file

SYNOPSIS
       /etc/systemd/pstore.conf /etc/systemd/pstore.conf.d/*

DESCRIPTION
       This file configures the behavior of systemd-pstore(8), a tool for
       archiving the contents of the persistent storage filesystem, pstore[1].

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
       All options are configured in the [PStore] section:

       Storage=
           Controls where to archive (i.e. copy) files from the pstore
           filesystem. One of "none", "external", and "journal". When "none",
           the tool exits without processing files in the pstore filesystem.
           When "external" (the default), files are archived into
           /var/lib/systemd/pstore/, and logged into the journal. When
           "journal", pstore file contents are logged only in the journal.

       Unlink=
           Controls whether or not files are removed from pstore after
           processing. Takes a boolean value. When true, a pstore file is
           removed from the pstore once it has been archived (either to disk
           or into the journal). When false, processing of pstore files occurs
           normally, but the files remain in the pstore. The default is true
           in order to maintain the pstore in a nearly empty state, so that
           the pstore has storage available for the next kernel error event.

       The defaults for all values are listed as comments in the template
       /etc/systemd/pstore.conf file that is installed by default.

SEE ALSO
       systemd-journald.service(8)

NOTES
        1. pstore
           https://docs.kernel.org/admin-guide/abi-testing.html#abi-sys-fs-pstore

systemd 253                                                     PSTORE.CONF(5)
