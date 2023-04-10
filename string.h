string.h(0P)               POSIX Programmer's Manual              string.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux
       implementation of this interface may differ (consult the  corresponding
       Linux  manual page for details of Linux behavior), or the interface may
       not be implemented on Linux.

NAME
       string.h — string operations

SYNOPSIS
       #include <string.h>

DESCRIPTION
       Some of the functionality described on this reference page extends  the
       ISO C  standard. Applications shall define the appropriate feature test
       macro (see the System Interfaces volume of POSIX.1‐2017,  Section  2.2,
       The  Compilation Environment) to enable the visibility of these symbols
       in this header.

       The <string.h> header shall define NULL  and  size_t  as  described  in
       <stddef.h>.

       The  <string.h>  header  shall define the locale_t type as described in
       <locale.h>.

       The following shall be declared as functions and may also be defined as
       macros.  Function prototypes shall be provided for use with ISO C stan‐
       dard compilers.

           void    *memccpy(void *restrict, const void *restrict, int, size_t);
           void    *memchr(const void *, int, size_t);
           int      memcmp(const void *, const void *, size_t);
           void    *memcpy(void *restrict, const void *restrict, size_t);
           void    *memmove(void *, const void *, size_t);
           void    *memset(void *, int, size_t);
           char    *stpcpy(char *restrict, const char *restrict);
           char    *stpncpy(char *restrict, const char *restrict, size_t);
           char    *strcat(char *restrict, const char *restrict);
           char    *strchr(const char *, int);
           int      strcmp(const char *, const char *);
           int      strcoll(const char *, const char *);
           int      strcoll_l(const char *, const char *, locale_t);
           char    *strcpy(char *restrict, const char *restrict);
           size_t   strcspn(const char *, const char *);
           char    *strdup(const char *);
           char    *strerror(int);
           char    *strerror_l(int, locale_t);
           int      strerror_r(int, char *, size_t);
           size_t   strlen(const char *);
           char    *strncat(char *restrict, const char *restrict, size_t);
           int      strncmp(const char *, const char *, size_t);
           char    *strncpy(char *restrict, const char *restrict, size_t);
           char    *strndup(const char *, size_t);
           size_t   strnlen(const char *, size_t);
           char    *strpbrk(const char *, const char *);
           char    *strrchr(const char *, int);
           char    *strsignal(int);
           size_t   strspn(const char *, const char *);
           char    *strstr(const char *, const char *);
           char    *strtok(char *restrict, const char *restrict);
           char    *strtok_r(char *restrict, const char *restrict, char **restrict);
           size_t   strxfrm(char *restrict, const char *restrict, size_t);
           size_t   strxfrm_l(char *restrict, const char *restrict,
                        size_t, locale_t);

       Inclusion of the <string.h> header may also make  visible  all  symbols
       from <stddef.h>.

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <locale.h>, <stddef.h>, <sys_types.h>

       The System Interfaces volume of POSIX.1‐2017, Section 2.2, The Compila‐
       tion Environment, memccpy(), memchr(), memcmp(), memcpy(), memmove(),
       memset(), strcat(), strchr(), strcmp(), strcoll(), strcpy(), strcspn(),
       strdup(), strerror(), strlen(), strncat(), strncmp(), strncpy(), strp‐
       brk(), strrchr(), strsignal(), strspn(), strstr(), strtok(), strxfrm()

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

IEEE/The Open Group                  2017                         string.h(0P)
