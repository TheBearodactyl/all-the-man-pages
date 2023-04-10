locale.h(0P)                                                                             POSIX Programmer's Manual                                                                            locale.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or
       the interface may not be implemented on Linux.

NAME
       locale.h — category macros

SYNOPSIS
       #include <locale.h>

DESCRIPTION
       Some of the functionality described on this reference page extends the ISO C standard. Applications shall define  the  appropriate  feature  test  macro  (see  the  System  Interfaces  volume  of
       POSIX.1‐2017, Section 2.2, The Compilation Environment) to enable the visibility of these symbols in this header.

       The  <locale.h>  header shall define the lconv structure, which shall include at least the following members.  (See the definitions of LC_MONETARY in Section 7.3.3, LC_MONETARY and Section 7.3.4,
       LC_NUMERIC.)

           char    *currency_symbol
           char    *decimal_point
           char     frac_digits
           char    *grouping
           char    *int_curr_symbol
           char     int_frac_digits
           char     int_n_cs_precedes
           char     int_n_sep_by_space
           char     int_n_sign_posn
           char     int_p_cs_precedes
           char     int_p_sep_by_space
           char     int_p_sign_posn
           char    *mon_decimal_point
           char    *mon_grouping
           char    *mon_thousands_sep
           char    *negative_sign
           char     n_cs_precedes
           char     n_sep_by_space
           char     n_sign_posn
           char    *positive_sign
           char     p_cs_precedes
           char     p_sep_by_space
           char     p_sign_posn
           char    *thousands_sep

       The <locale.h> header shall define NULL (as described in <stddef.h>) and at least the following as macros:

       LC_ALL
       LC_COLLATE
       LC_CTYPE
       LC_MESSAGES
       LC_MONETARY
       LC_NUMERIC
       LC_TIME

       which shall expand to integer constant expressions with distinct values for use as the first argument to the setlocale() function.

       Additional macro definitions, beginning with the characters LC_ and an uppercase letter, may also be specified by the implementation.

       The <locale.h> header shall contain at least the following macros representing bitmasks for use with the newlocale() function for each supported  locale  category:  LC_COLLATE_MASK  LC_CTYPE_MASK
       LC_MESSAGES_MASK LC_MONETARY_MASK LC_NUMERIC_MASK LC_TIME_MASK

       In addition, a macro to set the bits for all categories set shall be defined: LC_ALL_MASK

       The <locale.h> header shall define LC_GLOBAL_LOCALE, a special locale object descriptor used by the duplocale() and uselocale() functions.

       The <locale.h> header shall define the locale_t type, representing a locale object.

       The following shall be declared as functions and may also be defined as macros. Function prototypes shall be provided for use with ISO C standard compilers.

           locale_t      duplocale(locale_t);
           void          freelocale(locale_t);
           struct lconv *localeconv(void);
           locale_t      newlocale(int, const char *, locale_t);
           char         *setlocale(int, const char *);
           locale_t      uselocale (locale_t);

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       It is suggested that each category macro name for use in setlocale() have a corresponding macro name ending in _MASK for use in newlocale().

FUTURE DIRECTIONS
       None.

SEE ALSO
       Chapter 8, Environment Variables, <stddef.h>

       The System Interfaces volume of POSIX.1‐2017, duplocale(), freelocale(), localeconv(), newlocale(), setlocale(), uselocale()

COPYRIGHT
       Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group
       Base Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.  In the event of any discrepancy between this  ver‐
       sion  and  the  original  IEEE and The Open Group Standard, the original IEEE and The Open Group Standard is the referee document. The original Standard can be obtained online at http://www.open‐
       group.org/unix/online.html .

       Any typographical or formatting errors that appear in this page are most likely to have been introduced during the conversion of the source files to man page format. To report  such  errors,  see
       https://www.kernel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                                                                                2017                                                                                       locale.h(0P)
