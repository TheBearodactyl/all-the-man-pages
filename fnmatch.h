fnmatch.h(0P)                                                                            POSIX Programmer's Manual                                                                           fnmatch.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or
       the interface may not be implemented on Linux.

NAME
       fnmatch.h — filename-matching types

SYNOPSIS
       #include <fnmatch.h>

DESCRIPTION
       The <fnmatch.h> header shall define the following symbolic constants:

       FNM_NOMATCH   The string does not match the specified pattern.

       FNM_PATHNAME  <slash> in string only matches <slash> in pattern.

       FNM_PERIOD    Leading <period> in string must be exactly matched by <period> in pattern.

       FNM_NOESCAPE  Disable backslash escaping.

       The following shall be declared as a function and may also be defined as a macro. A function prototype shall be provided.

           int fnmatch(const char *, const char *, int);

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       The System Interfaces volume of POSIX.1‐2017, fnmatch()

COPYRIGHT
       Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group
       Base  Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.  In the event of any discrepancy between this ver‐
       sion and the original IEEE and The Open Group Standard, the original IEEE and The Open Group Standard is the referee document. The original Standard can be  obtained  online  at  http://www.open‐
       group.org/unix/online.html .

       Any  typographical  or  formatting errors that appear in this page are most likely to have been introduced during the conversion of the source files to man page format. To report such errors, see
       https://www.kernel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                                                                                2017                                                                                      fnmatch.h(0P)
