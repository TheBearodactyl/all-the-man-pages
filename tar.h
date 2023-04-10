tar.h(0P)                                                                                POSIX Programmer's Manual                                                                               tar.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or
       the interface may not be implemented on Linux.

NAME
       tar.h — extended tar definitions

SYNOPSIS
       #include <tar.h>

DESCRIPTION
       The <tar.h> header shall define the following symbolic constants with the indicated values.

       General definitions:

       ┌───────────┬────────────┬────────────────────────────────────────┐
       │   Name    │   Value    │              Description               │
       ├───────────┼────────────┼────────────────────────────────────────┤
       │TMAGIC     │  "ustar"   │ Used in the magic field in  the  ustar │
       │           │            │ header  block,  including the trailing │
       │           │            │ null byte.                             │
       │TMAGLEN    │     6      │ Length in octets of the magic field.   │
       │TVERSION   │    "00"    │ Used in the version field in the ustar │
       │           │            │ header  block,  excluding the trailing │
       │           │            │ null byte.                             │
       │TVERSLEN   │     2      │ Length in octets of the version field. │
       └───────────┴────────────┴────────────────────────────────────────┘
       Typeflag field definitions:

       ┌───────────┬────────────┬────────────────────────────────┐
       │   Name    │   Value    │          Description           │
       ├───────────┼────────────┼────────────────────────────────┤
       │REGTYPE    │    '0'     │ Regular file.                  │
       │AREGTYPE   │    '\0'    │ Regular file.                  │
       │LNKTYPE    │    '1'     │ Link.                          │
       │SYMTYPE    │    '2'     │ Symbolic link.                 │
       │CHRTYPE    │    '3'     │ Character special.             │
       │BLKTYPE    │    '4'     │ Block special.                 │
       │DIRTYPE    │    '5'     │ Directory.                     │
       │FIFOTYPE   │    '6'     │ FIFO special.                  │
       │CONTTYPE   │    '7'     │ Reserved.                      │
       └───────────┴────────────┴────────────────────────────────┘
       Mode field bit definitions (octal):

       ┌───────────┬────────────┬──────────────────────────────────────────────┐
       │   Name    │   Value    │                 Description                  │
       ├───────────┼────────────┼──────────────────────────────────────────────┤
       │TSUID      │   04000    │ Set UID on execution.                        │
       │TSGID      │   02000    │ Set GID on execution.                        │
       │TSVTX      │   01000    │ On directories, restricted deletion flag.    │
       │TUREAD     │   00400    │ Read by owner.                               │
       │TUWRITE    │   00200    │ Write by owner special.                      │
       │TUEXEC     │   00100    │ Execute/search by owner.                     │
       │TGREAD     │   00040    │ Read by group.                               │
       │TGWRITE    │   00020    │ Write by group.                              │
       │TGEXEC     │   00010    │ Execute/search by group.                     │
       │TOREAD     │   00004    │ Read by other.                               │
       │TOWRITE    │   00002    │ Write by other.                              │
       │TOEXEC     │   00001    │ Execute/search by other.                     │
       └───────────┴────────────┴──────────────────────────────────────────────┘
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

IEEE/The Open Group                                                                                2017                                                                                          tar.h(0P)
