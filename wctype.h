wctype.h(0P)                                                                             POSIX Programmer's Manual                                                                            wctype.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or
       the interface may not be implemented on Linux.

NAME
       wctype.h — wide-character classification and mapping utilities

SYNOPSIS
       #include <wctype.h>

DESCRIPTION
       Some of the functionality described on this reference page extends the ISO C standard. Applications shall define  the  appropriate  feature  test  macro  (see  the  System  Interfaces  volume  of
       POSIX.1‐2017, Section 2.2, The Compilation Environment) to enable the visibility of these symbols in this header.

       The <wctype.h> header shall define the following types:

       wint_t      As described in <wchar.h>.

       wctrans_t   A scalar type that can hold values which represent locale-specific character mappings.

       wctype_t    As described in <wchar.h>.

       The <wctype.h> header shall define the locale_t type as described in <locale.h>.

       The <wctype.h> header shall define the following macro:

       WEOF        As described in <wchar.h>.

       For  all  functions described in this header that accept an argument of type wint_t, the value is representable as a wchar_t or equals the value of WEOF. If this argument has any other value, the
       behavior is undefined.

       The behavior of these functions shall be affected by the LC_CTYPE category of the current locale.

       Inclusion of the <wctype.h> header may make visible all symbols from the headers <ctype.h>, <stdarg.h>, <stddef.h>, <stdio.h>, <stdlib.h>, <string.h>, <time.h>, and <wchar.h>.

       The following shall be declared as functions and may also be defined as macros. Function prototypes shall be provided for use with ISO C standard compilers.

           int       iswalnum(wint_t);
           int       iswalnum_l(wint_t, locale_t);
           int       iswalpha(wint_t);
           int       iswalpha_l(wint_t, locale_t);
           int       iswblank(wint_t);
           int       iswblank_l(wint_t, locale_t);
           int       iswcntrl(wint_t);
           int       iswcntrl_l(wint_t, locale_t);
           int       iswctype(wint_t, wctype_t);
           int       iswctype_l(wint_t, wctype_t, locale_t);
           int       iswdigit(wint_t);
           int       iswdigit_l(wint_t, locale_t);
           int       iswgraph(wint_t);
           int       iswgraph_l(wint_t, locale_t);
           int       iswlower(wint_t);
           int       iswlower_l(wint_t, locale_t);
           int       iswprint(wint_t);
           int       iswprint_l(wint_t, locale_t);
           int       iswpunct(wint_t);
           int       iswpunct_l(wint_t, locale_t);
           int       iswspace(wint_t);
           int       iswspace_l(wint_t, locale_t);
           int       iswupper(wint_t);
           int       iswupper_l(wint_t, locale_t);
           int       iswxdigit(wint_t);
           int       iswxdigit_l(wint_t, locale_t);
           wint_t    towctrans(wint_t, wctrans_t);
           wint_t    towctrans_l(wint_t, wctrans_t, locale_t);
           wint_t    towlower(wint_t);
           wint_t    towlower_l(wint_t, locale_t);
           wint_t    towupper(wint_t);
           wint_t    towupper_l(wint_t, locale_t);
           wctrans_t wctrans(const char *);
           wctrans_t wctrans_l(const char *, locale_t);
           wctype_t  wctype(const char *);
           wctype_t  wctype_l(const char *, locale_t);

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <ctype.h>, <locale.h>, <stdarg.h>, <stddef.h>, <stdio.h>, <stdlib.h>, <string.h>, <time.h>, <wchar.h>

       The System Interfaces volume of POSIX.1‐2017, Section 2.2, The Compilation Environment, iswalnum(), iswalpha(), iswblank(), iswcntrl(), iswctype(), iswdigit(), iswgraph(), iswlower(), iswprint(),
       iswpunct(), iswspace(), iswupper(), iswxdigit(), setlocale(), towctrans(), towlower(), towupper(), wctrans(), wctype()

COPYRIGHT
       Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group
       Base Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.  In the event of any discrepancy between this  ver‐
       sion  and  the  original  IEEE and The Open Group Standard, the original IEEE and The Open Group Standard is the referee document. The original Standard can be obtained online at http://www.open‐
       group.org/unix/online.html .

       Any typographical or formatting errors that appear in this page are most likely to have been introduced during the conversion of the source files to man page format. To report  such  errors,  see
       https://www.kernel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                                                                                2017                                                                                       wctype.h(0P)
