monetary.h(0P)                                                                           POSIX Programmer's Manual                                                                          monetary.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or
       the interface may not be implemented on Linux.

NAME
       monetary.h — monetary types

SYNOPSIS
       #include <monetary.h>

DESCRIPTION
       The <monetary.h> header shall define the locale_t type as described in <locale.h>.

       The <monetary.h> header shall define the size_t type as described in <stddef.h>.

       The <monetary.h> header shall define the ssize_t type as described in <sys/types.h>.

       The following shall be declared as functions and may also be defined as macros. Function prototypes shall be provided for use with ISO C standard compilers.

           ssize_t  strfmon(char *restrict, size_t, const char *restrict, ...);
           ssize_t  strfmon_l(char *restrict, size_t, locale_t,
                        const char *restrict, ...);

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <locale.h>, <stddef.h>, <sys_types.h>

       The System Interfaces volume of POSIX.1‐2017, strfmon()

COPYRIGHT
       Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group
       Base  Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.  In the event of any discrepancy between this ver‐
       sion and the original IEEE and The Open Group Standard, the original IEEE and The Open Group Standard is the referee document. The original Standard can be  obtained  online  at  http://www.open‐
       group.org/unix/online.html .

       Any  typographical  or  formatting errors that appear in this page are most likely to have been introduced during the conversion of the source files to man page format. To report such errors, see
       https://www.kernel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                                                                                2017                                                                                     monetary.h(0P)
