stdbool.h(0P)              POSIX Programmer's Manual             stdbool.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux
       implementation of this interface may differ (consult the  corresponding
       Linux  manual page for details of Linux behavior), or the interface may
       not be implemented on Linux.

NAME
       stdbool.h — boolean type and values

SYNOPSIS
       #include <stdbool.h>

DESCRIPTION
       The functionality described on this reference page is aligned with  the
       ISO C  standard.  Any  conflict between the requirements described here
       and the ISO C standard is unintentional. This  volume  of  POSIX.1‐2017
       defers to the ISO C standard.

       The <stdbool.h> header shall define the following macros:

       bool    Expands to _Bool.

       true    Expands to the integer constant 1.

       false   Expands to the integer constant 0.

       __bool_true_false_are_defined
               Expands to the integer constant 1.

       An application may undefine and then possibly redefine the macros bool,
       true, and false.

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       The ability to undefine and redefine the macros bool, true,  and  false
       is an obsolescent feature and may be removed in a future version.

SEE ALSO
       None.

COPYRIGHT
       Portions  of  this text are reprinted and reproduced in electronic form
       from IEEE Std 1003.1-2017, Standard for Information Technology --  Por‐
       table  Operating System Interface (POSIX), The Open Group Base Specifi‐
       cations Issue 7, 2018 Edition, Copyright (C) 2018 by the  Institute  of
       Electrical  and  Electronics Engineers, Inc and The Open Group.  In the
       event of any discrepancy between this version and the original IEEE and
       The  Open Group Standard, the original IEEE and The Open Group Standard
       is the referee document. The original Standard can be  obtained  online
       at http://www.opengroup.org/unix/online.html .

       Any  typographical  or  formatting  errors that appear in this page are
       most likely to have been introduced during the conversion of the source
       files  to  man page format. To report such errors, see https://www.ker‐
       nel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                  2017                        stdbool.h(0P)
