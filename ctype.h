ctype.h(0P)                                                                              POSIX Programmer's Manual                                                                             ctype.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or
       the interface may not be implemented on Linux.

NAME
       ctype.h — character types

SYNOPSIS
       #include <ctype.h>

DESCRIPTION
       Some of the functionality described on this reference page extends the ISO C standard. Applications shall define  the  appropriate  feature  test  macro  (see  the  System  Interfaces  volume  of
       POSIX.1‐2017, Section 2.2, The Compilation Environment) to enable the visibility of these symbols in this header.

       The <ctype.h> header shall define the locale_t type as described in <locale.h>, representing a locale object.

       The following shall be declared as functions and may also be defined as macros. Function prototypes shall be provided for use with ISO C standard compilers.

           int   isalnum(int);
           int   isalnum_l(int, locale_t);
           int   isalpha(int);
           int   isalpha_l(int, locale_t);
           int   isascii(int);
           int   isblank(int);
           int   isblank_l(int, locale_t);
           int   iscntrl(int);
           int   iscntrl_l(int, locale_t);
           int   isdigit(int);
           int   isdigit_l(int, locale_t);
           int   isgraph(int);
           int   isgraph_l(int, locale_t);
           int   islower(int);
           int   islower_l(int, locale_t);
           int   isprint(int);
           int   isprint_l(int, locale_t);
           int   ispunct(int);
           int   ispunct_l(int, locale_t);
           int   isspace(int);
           int   isspace_l(int, locale_t);
           int   isupper(int);
           int   isupper_l(int, locale_t);
           int   isxdigit(int);
           int   isxdigit_l(int, locale_t);
           int   toascii(int);
           int   tolower(int);
           int   tolower_l(int, locale_t);
           int   toupper(int);
           int   toupper_l(int, locale_t);

       The <ctype.h> header shall define the following as macros:

           int   _toupper(int);
           int   _tolower(int);

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <locale.h>

       The  System  Interfaces  volume  of  POSIX.1‐2017, Section 2.2, The Compilation Environment, isalnum(), isalpha(), isascii(), isblank(), iscntrl(), isdigit(), isgraph(), islower(), isprint(), is‐
       punct(), isspace(), isupper(), isxdigit(), mblen(), mbstowcs(), mbtowc(), setlocale(), toascii(), tolower(), _tolower(), toupper(), _toupper(), wcstombs(), wctomb()

COPYRIGHT
       Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group
       Base  Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.  In the event of any discrepancy between this ver‐
       sion and the original IEEE and The Open Group Standard, the original IEEE and The Open Group Standard is the referee document. The original Standard can be  obtained  online  at  http://www.open‐
       group.org/unix/online.html .

       Any  typographical  or  formatting errors that appear in this page are most likely to have been introduced during the conversion of the source files to man page format. To report such errors, see
       https://www.kernel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                                                                                2017                                                                                        ctype.h(0P)
