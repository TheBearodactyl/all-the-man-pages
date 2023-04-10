cpio.h(0P)                                                                               POSIX Programmer's Manual                                                                              cpio.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or
       the interface may not be implemented on Linux.

NAME
       cpio.h — cpio archive values

SYNOPSIS
       #include <cpio.h>

DESCRIPTION
       The <cpio.h> header shall define the symbolic constants needed by the c_mode field of the cpio archive format, with the names and values given in the following table:

                                                                     ┌─────────┬───────────────────────────────────────────┬───────────────┐
                                                                     │  Name   │                Description                │ Value (Octal) │
                                                                     ├─────────┼───────────────────────────────────────────┼───────────────┤
                                                                     │C_IRUSR  │ Read by owner.                            │    0000400    │
                                                                     │C_IWUSR  │ Write by owner.                           │    0000200    │
                                                                     │C_IXUSR  │ Execute by owner.                         │    0000100    │
                                                                     │C_IRGRP  │ Read by group.                            │    0000040    │
                                                                     │C_IWGRP  │ Write by group.                           │    0000020    │
                                                                     │C_IXGRP  │ Execute by group.                         │    0000010    │
                                                                     │C_IROTH  │ Read by others.                           │    0000004    │
                                                                     │C_IWOTH  │ Write by others.                          │    0000002    │
                                                                     │C_IXOTH  │ Execute by others.                        │    0000001    │
                                                                     │C_ISUID  │ Set user ID.                              │    0004000    │
                                                                     │C_ISGID  │ Set group ID.                             │    0002000    │
                                                                     │C_ISVTX  │ On directories, restricted deletion flag. │    0001000    │
                                                                     │C_ISDIR  │ Directory.                                │    0040000    │
                                                                     │C_ISFIFO │ FIFO.                                     │    0010000    │
                                                                     │C_ISREG  │ Regular file.                             │    0100000    │
                                                                     │C_ISBLK  │ Block special.                            │    0060000    │
                                                                     │C_ISCHR  │ Character special.                        │    0020000    │
                                                                     │C_ISCTG  │ Reserved.                                 │    0110000    │
                                                                     │C_ISLNK  │ Symbolic link.                            │    0120000    │
                                                                     │C_ISSOCK │ Socket.                                   │    0140000    │
                                                                     └─────────┴───────────────────────────────────────────┴───────────────┘
       The <cpio.h> header shall define the following symbolic constant as a string:

           MAGIC    "070707"

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       The Shell and Utilities volume of POSIX.1‐2017, pax

COPYRIGHT
       Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group
       Base  Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.  In the event of any discrepancy between this ver‐
       sion and the original IEEE and The Open Group Standard, the original IEEE and The Open Group Standard is the referee document. The original Standard can be  obtained  online  at  http://www.open‐
       group.org/unix/online.html .

       Any  typographical  or  formatting errors that appear in this page are most likely to have been introduced during the conversion of the source files to man page format. To report such errors, see
       https://www.kernel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                                                                                2017                                                                                         cpio.h(0P)
