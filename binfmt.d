BINFMT.D(5)                        binfmt.d                        BINFMT.D(5)

NAME
       binfmt.d - Configure additional binary formats for executables at boot

SYNOPSIS
       /etc/binfmt.d/*.conf

       /run/binfmt.d/*.conf

       /usr/lib/binfmt.d/*.conf

DESCRIPTION
       At boot, systemd-binfmt.service(8) reads configuration files from the
       above directories to register in the kernel additional binary formats
       for executables.

CONFIGURATION FORMAT
       Each file contains a list of binfmt_misc kernel binary format rules.
       Consult the kernel's Kernel Support for miscellaneous Binary Formats
       (binfmt_misc)[1] documentation file for more information on
       registration of additional binary formats and how to write rules.

       Empty lines and lines beginning with ";" and "#" are ignored. Note that
       this means you may not use those symbols as the delimiter in binary
       format rules.

CONFIGURATION DIRECTORIES AND PRECEDENCE
       Configuration files are read from directories in /etc/, /run/,
       /usr/local/lib/, and /usr/lib/, in order of precedence, as listed in
       the SYNOPSIS section above. Files must have the ".conf" extension.
       Files in /etc/ override files with the same name in /run/,
       /usr/local/lib/, and /usr/lib/. Files in /run/ override files with the
       same name under /usr/.

       All configuration files are sorted by their filename in lexicographic
       order, regardless of which of the directories they reside in. If
       multiple files specify the same option, the entry in the file with the
       lexicographically latest name will take precedence. Thus, the
       configuration in a certain file may either be replaced completely (by
       placing a file with the same name in a directory with higher priority),
       or individual settings might be changed (by specifying additional
       settings in a file with a different name that is ordered later).

       Packages should install their configuration files in /usr/lib/
       (distribution packages) or /usr/local/lib/ (local installs). Files in
       /etc/ are reserved for the local administrator, who may use this logic
       to override the configuration files installed by vendor packages. It is
       recommended to prefix all filenames with a two-digit number and a dash,
       to simplify the ordering of the files.

       If the administrator wants to disable a configuration file supplied by
       the vendor, the recommended way is to place a symlink to /dev/null in
       the configuration directory in /etc/, with the same filename as the
       vendor configuration file. If the vendor configuration file is included
       in the initrd image, the image has to be regenerated.

EXAMPLE
       Example 1. /etc/binfmt.d/wine.conf example:

           # Start WINE on Windows executables
           :DOSWin:M::MZ::/usr/bin/wine:

SEE ALSO
       systemd(1), systemd-binfmt.service(8), systemd-delta(1), wine(8)

NOTES
        1. Kernel Support for miscellaneous Binary Formats (binfmt_misc)
           https://docs.kernel.org/admin-guide/binfmt-misc.html

systemd 253                                                        BINFMT.D(5)
