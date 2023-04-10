GDBINIT(5)                                                                                 GNU Development Tools                                                                                GDBINIT(5)

NAME
       gdbinit - GDB initialization scripts

SYNOPSIS
       ~/.config/gdb/gdbinit

       ~/.gdbinit

       ./.gdbinit

DESCRIPTION
       These files contain GDB commands to automatically execute during GDB startup.  The lines of contents are canned sequences of commands, described in the GDB manual in node "Sequences" -- shell
       command "info -f gdb -n Sequences".

       Please read more in the GDB manual in node "Startup" -- shell command "info -f gdb -n Startup".

       (not enabled with "--with-system-gdbinit" during compilation)
           System-wide initialization file.  It is executed unless user specified GDB option "-nx" or "-n".  See more in the GDB manual in node "System-wide configuration" -- shell command "info -f gdb
           -n 'System-wide configuration'".

       (not enabled with "--with-system-gdbinit-dir" during compilation)
           System-wide initialization directory.  All files in this directory are executed on startup unless user specified GDB option "-nx" or "-n", as long as they have a recognized file extension.
           See more in the GDB manual in node "System-wide configuration" -- shell command "info -f gdb -n 'System-wide configuration'".

       ~/.config/gdb/gdbinit or ~/.gdbinit
           User initialization file.  It is executed unless user specified GDB options "-nx", "-n" or "-nh".

       .gdbinit
           Initialization file for current directory.  It may need to be enabled with GDB security command "set auto-load local-gdbinit".  See more in the GDB manual in node "Init File in the Current
           Directory" -- shell command "info -f gdb -n 'Init File in the Current Directory'".

OPTIONS
SEE ALSO
       gdb(1), "info -f gdb -n Startup"

       The full documentation for GDB is maintained as a Texinfo manual.  If the "info" and "gdb" programs and GDB's Texinfo documentation are properly installed at your site, the command

               info gdb

       should give you access to the complete manual.

       Using GDB: A Guide to the GNU Source-Level Debugger, Richard M. Stallman and Roland H. Pesch, July 1991.

COPYRIGHT
       Copyright (c) 1988-2023 Free Software Foundation, Inc.

       Permission is granted to copy, distribute and/or modify this document under the terms of the GNU Free Documentation License, Version 1.3 or any later version published by the Free Software
       Foundation; with the Invariant Sections being "Free Software" and "Free Software Needs Free Documentation", with the Front-Cover Texts being "A GNU Manual," and with the Back-Cover Texts as in
       (a) below.

       (a) The FSF's Back-Cover Text is: "You are free to copy and modify this GNU Manual.  Buying copies from GNU Press supports the FSF in developing GNU and promoting software freedom."

gdb-13.1                                                                                        2023-02-19                                                                                      GDBINIT(5)
