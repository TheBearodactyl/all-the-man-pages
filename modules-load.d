MODULES-LOAD.D(5)                                                                             modules-load.d                                                                             MODULES-LOAD.D(5)

NAME
       modules-load.d - Configure kernel modules to load at boot

SYNOPSIS
       /etc/modules-load.d/*.conf

       /run/modules-load.d/*.conf

       /usr/lib/modules-load.d/*.conf

DESCRIPTION
       systemd-modules-load.service(8) reads files from the above directories which contain kernel modules to load during boot in a static list. Each configuration file is named in the style of
       /etc/modules-load.d/program.conf. Note that it is usually a better idea to rely on the automatic module loading by PCI IDs, USB IDs, DMI IDs or similar triggers encoded in the kernel modules
       themselves instead of static configuration like this. In fact, most modern kernel modules are prepared for automatic loading already.

CONFIGURATION FORMAT
       The configuration files should simply contain a list of kernel module names to load, separated by newlines. Empty lines and lines whose first non-whitespace character is # or ; are ignored.

CONFIGURATION DIRECTORIES AND PRECEDENCE
       Configuration files are read from directories in /etc/, /run/, /usr/local/lib/, and /usr/lib/, in order of precedence, as listed in the SYNOPSIS section above. Files must have the ".conf"
       extension. Files in /etc/ override files with the same name in /run/, /usr/local/lib/, and /usr/lib/. Files in /run/ override files with the same name under /usr/.

       All configuration files are sorted by their filename in lexicographic order, regardless of which of the directories they reside in. If multiple files specify the same option, the entry in the
       file with the lexicographically latest name will take precedence. Thus, the configuration in a certain file may either be replaced completely (by placing a file with the same name in a directory
       with higher priority), or individual settings might be changed (by specifying additional settings in a file with a different name that is ordered later).

       Packages should install their configuration files in /usr/lib/ (distribution packages) or /usr/local/lib/ (local installs). Files in /etc/ are reserved for the local administrator, who may use
       this logic to override the configuration files installed by vendor packages. It is recommended to prefix all filenames with a two-digit number and a dash, to simplify the ordering of the files.

       If the administrator wants to disable a configuration file supplied by the vendor, the recommended way is to place a symlink to /dev/null in the configuration directory in /etc/, with the same
       filename as the vendor configuration file. If the vendor configuration file is included in the initrd image, the image has to be regenerated.

EXAMPLE
       Example 1. /etc/modules-load.d/virtio-net.conf example:

           # Load virtio-net.ko at boot
           virtio-net

SEE ALSO
       systemd(1), systemd-modules-load.service(8), systemd-delta(1), modprobe(8)

systemd 253                                                                                                                                                                              MODULES-LOAD.D(5)
