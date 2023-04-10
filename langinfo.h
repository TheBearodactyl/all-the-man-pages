langinfo.h(0P)                                                                           POSIX Programmer's Manual                                                                          langinfo.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or
       the interface may not be implemented on Linux.

NAME
       langinfo.h — language information constants

SYNOPSIS
       #include <langinfo.h>

DESCRIPTION
       The <langinfo.h> header shall define the symbolic constants used to identify items of langinfo data (see nl_langinfo()).

       The <langinfo.h> header shall define the locale_t type as described in <locale.h>.

       The <langinfo.h> header shall define the nl_item type as described in <nl_types.h>.

       The <langinfo.h> header shall define the following symbolic constants with type nl_item.  The entries under Category indicate in which setlocale() category each item is defined.

                                                              ┌───────────┬───────────┬───────────────────────────────────────────────────────────┐
                                                              │ Constant  │ Category  │                         Meaning                           │
                                                              ├───────────┼───────────┼───────────────────────────────────────────────────────────┤
                                                              │CODESET    │LC_CTYPE   │Codeset name.                                              │
                                                              │D_T_FMT    │LC_TIME    │String for formatting date and time.                       │
                                                              │D_FMT      │LC_TIME    │Date format string.                                        │
                                                              │T_FMT      │LC_TIME    │Time format string.                                        │
                                                              │T_FMT_AMPM │LC_TIME    │a.m. or p.m. time format string.                           │
                                                              │AM_STR     │LC_TIME    │Ante-meridiem affix.                                       │
                                                              │PM_STR     │LC_TIME    │Post-meridiem affix.                                       │
                                                              │DAY_1      │LC_TIME    │Name of the first day of the week (for example, Sunday).   │
                                                              │DAY_2      │LC_TIME    │Name of the second day of the week (for example, Monday).  │
                                                              │DAY_3      │LC_TIME    │Name of the third day of the week (for example, Tuesday).  │
                                                              │DAY_4      │LC_TIME    │Name of the fourth day of the week                         │
                                                              │           │           │(for example, Wednesday).                                  │
                                                              │DAY_5      │LC_TIME    │Name of the fifth day of the week (for example, Thursday). │
                                                              │DAY_6      │LC_TIME    │Name of the sixth day of the week (for example, Friday).   │
                                                              │DAY_7      │LC_TIME    │Name of the seventh day of the week                        │
                                                              │           │           │(for example, Saturday).                                   │
                                                              │ABDAY_1    │LC_TIME    │Abbreviated name of the first day of the week.             │
                                                              │ABDAY_2    │LC_TIME    │Abbreviated name of the second day of the week.            │
                                                              │ABDAY_3    │LC_TIME    │Abbreviated name of the third day of the week.             │
                                                              │ABDAY_4    │LC_TIME    │Abbreviated name of the fourth day of the week.            │
                                                              │ABDAY_5    │LC_TIME    │Abbreviated name of the fifth day of the week.             │
                                                              │ABDAY_6    │LC_TIME    │Abbreviated name of the sixth day of the week.             │
                                                              │ABDAY_7    │LC_TIME    │Abbreviated name of the seventh day of the week.           │
                                                              │MON_1      │LC_TIME    │Name of the first month of the year.                       │
                                                              │MON_2      │LC_TIME    │Name of the second month.                                  │
                                                              │MON_3      │LC_TIME    │Name of the third month.                                   │
                                                              │MON_4      │LC_TIME    │Name of the fourth month.                                  │
                                                              │MON_5      │LC_TIME    │Name of the fifth month.                                   │
                                                              │MON_6      │LC_TIME    │Name of the sixth month.                                   │
                                                              │MON_7      │LC_TIME    │Name of the seventh month.                                 │
                                                              │MON_8      │LC_TIME    │Name of the eighth month.                                  │
                                                              │MON_9      │LC_TIME    │Name of the ninth month.                                   │
                                                              │MON_10     │LC_TIME    │Name of the tenth month.                                   │
                                                              │MON_11     │LC_TIME    │Name of the eleventh month.                                │
                                                              │MON_12     │LC_TIME    │Name of the twelfth month.                                 │
                                                              │ABMON_1    │LC_TIME    │Abbreviated name of the first month.                       │
                                                              │ABMON_2    │LC_TIME    │Abbreviated name of the second month.                      │
                                                              │ABMON_3    │LC_TIME    │Abbreviated name of the third month.                       │
                                                              │ABMON_4    │LC_TIME    │Abbreviated name of the fourth month.                      │
                                                              │ABMON_5    │LC_TIME    │Abbreviated name of the fifth month.                       │
                                                              │ABMON_6    │LC_TIME    │Abbreviated name of the sixth month.                       │
                                                              │ABMON_7    │LC_TIME    │Abbreviated name of the seventh month.                     │
                                                              │ABMON_8    │LC_TIME    │Abbreviated name of the eighth month.                      │
                                                              │ABMON_9    │LC_TIME    │Abbreviated name of the ninth month.                       │
                                                              │ABMON_10   │LC_TIME    │Abbreviated name of the tenth month.                       │
                                                              │ABMON_11   │LC_TIME    │Abbreviated name of the eleventh month.                    │
                                                              │ABMON_12   │LC_TIME    │Abbreviated name of the twelfth month.                     │
                                                              │ERA        │LC_TIME    │Era description segments.                                  │
                                                              │ERA_D_FMT  │LC_TIME    │Era date format string.                                    │
                                                              │ERA_D_T_FMT│LC_TIME    │Era date and time format string.                           │
                                                              │ERA_T_FMT  │LC_TIME    │Era time format string.                                    │
                                                              │ALT_DIGITS │LC_TIME    │Alternative symbols for digits.                            │
                                                              │RADIXCHAR  │LC_NUMERIC │Radix character.                                           │
                                                              │THOUSEP    │LC_NUMERIC │Separator for thousands.                                   │
                                                              │YESEXPR    │LC_MESSAGES│Affirmative response expression.                           │
                                                              │NOEXPR     │LC_MESSAGES│Negative response expression.                              │
                                                              │CRNCYSTR   │LC_MONETARY│Local currency symbol,  preceded  by  '-'  if  the  symbol │
                                                              │           │           │should  appear  before the value, '+' if the symbol should │
                                                              │           │           │appear after the value, or '.'  if the symbol  should  re‐ │
                                                              │           │           │place the radix character. If the local currency symbol is │
                                                              │           │           │the empty string, implementations  may  return  the  empty │
                                                              │           │           │string ("").                                               │
                                                              └───────────┴───────────┴───────────────────────────────────────────────────────────┘
       If the locale's values for p_cs_precedes and n_cs_precedes do not match, the value of nl_langinfo(CRNCYSTR) and nl_langinfo_l(CRNCYSTR,loc) is unspecified.

       The following shall be declared as a function and may also be defined as a macro. A function prototype shall be provided.

           char *nl_langinfo(nl_item);
           char *nl_langinfo_l(nl_item, locale_t);

       Inclusion of the <langinfo.h> header may also make visible all symbols from <nl_types.h>.

       The following sections are informative.

APPLICATION USAGE
       Wherever possible, users are advised to use functions compatible with those in the ISO C standard to access items of langinfo data. In particular, the strftime() function should be used to access
       date and time information defined in category LC_TIME.  The localeconv() function should be used to access information corresponding to RADIXCHAR, THOUSEP, and CRNCYSTR.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       Chapter 7, Locale, <locale.h>, <nl_types.h>

       The System Interfaces volume of POSIX.1‐2017, nl_langinfo(), localeconv(), strfmon(), strftime()

COPYRIGHT
       Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group
       Base  Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.  In the event of any discrepancy between this ver‐
       sion and the original IEEE and The Open Group Standard, the original IEEE and The Open Group Standard is the referee document. The original Standard can be  obtained  online  at  http://www.open‐
       group.org/unix/online.html .

       Any  typographical  or  formatting errors that appear in this page are most likely to have been introduced during the conversion of the source files to man page format. To report such errors, see
       https://www.kernel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                                                                                2017                                                                                     langinfo.h(0P)
