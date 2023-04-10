stddef.h(0P)               POSIX Programmer's Manual              stddef.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux
       implementation of this interface may differ (consult the  corresponding
       Linux  manual page for details of Linux behavior), or the interface may
       not be implemented on Linux.

NAME
       stddef.h — standard type definitions

SYNOPSIS
       #include <stddef.h>

DESCRIPTION
       The functionality described on this reference page is aligned with  the
       ISO C  standard.  Any  conflict between the requirements described here
       and the ISO C standard is unintentional. This  volume  of  POSIX.1‐2017
       defers to the ISO C standard.

       The <stddef.h> header shall define the following macros:

       NULL      Null  pointer constant.  The macro shall expand to an integer
                 constant expression with the value 0 cast to type void *.

       offsetof(type, member-designator)
                 Integer constant expression of  type  size_t,  the  value  of
                 which is the offset in bytes to the structure member (member-
                 designator), from the beginning of its structure (type).

       The <stddef.h> header shall define the following types:

       ptrdiff_t Signed integer type of the result of subtracting  two  point‐
                 ers.

       wchar_t   Integer  type  whose  range  of values can represent distinct
                 codes for all members of the largest extended  character  set
                 specified  among  the  supported  locales; the null character
                 shall have the code value zero.  Each  member  of  the  basic
                 character set shall have a code value equal to its value when
                 used as the lone character in an integer  character  constant
                 if      an      implementation      does      not      define
                 __STDC_MB_MIGHT_NEQ_WC__.

       size_t    Unsigned integer type of the result of the sizeof operator.

       The implementation shall support one or more  programming  environments
       in  which  the  widths of ptrdiff_t, size_t, and wchar_t are no greater
       than the width of type long.  The names of these  programming  environ‐
       ments can be obtained using the confstr() function or the getconf util‐
       ity.

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       The ISO C standard does not require the NULL macro to include the  cast
       to  type void * and specifies that the NULL macro be implementation-de‐
       fined. POSIX.1‐2008 requires the cast and therefore need not be  imple‐
       mentation-defined.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <sys_types.h>, <wchar.h>

       The System Interfaces volume of POSIX.1‐2017, confstr()

       The Shell and Utilities volume of POSIX.1‐2017, getconf

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

IEEE/The Open Group                  2017                         stddef.h(0P)
