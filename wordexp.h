wordexp.h(0P)                                                                            POSIX Programmer's Manual                                                                           wordexp.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or
       the interface may not be implemented on Linux.

NAME
       wordexp.h — word-expansion types

SYNOPSIS
       #include <wordexp.h>

DESCRIPTION
       The <wordexp.h> header shall define the structures and symbolic constants used by the wordexp() and wordfree() functions.

       The <wordexp.h> header shall define the wordexp_t structure type, which shall include at least the following members:

           size_t   we_wordc  Count of words matched by words.
           char   **we_wordv  Pointer to list of expanded words.
           size_t   we_offs   Slots to reserve at the beginning of we_wordv.

       The <wordexp.h> header shall define the following symbolic constants for use as flags for the wordexp() function:

       WRDE_APPEND   Append words to those previously generated.

       WRDE_DOOFFS   Number of null pointers to prepend to we_wordv.

       WRDE_NOCMD    Fail if command substitution is requested.

       WRDE_REUSE    The pwordexp argument was passed to a previous successful call to wordexp(), and has not been passed to wordfree().  The result is the same as if the application  had  called  word‐
                     free() and then called wordexp() without WRDE_REUSE.

       WRDE_SHOWERR  Do not redirect stderr to /dev/null.

       WRDE_UNDEF    Report error on an attempt to expand an undefined shell variable.

       The <wordexp.h> header shall define the following symbolic constants as error return values:

       WRDE_BADCHAR  One of the unquoted characters—<newline>, '|', '&', ';', '<', '>', '(', ')', '{', '}'—appears in words in an inappropriate context.

       WRDE_BADVAL   Reference to undefined shell variable when WRDE_UNDEF is set in flags.

       WRDE_CMDSUB   Command substitution requested when WRDE_NOCMD was set in flags.

       WRDE_NOSPACE  Attempt to allocate memory failed.

       WRDE_SYNTAX   Shell syntax error, such as unbalanced parentheses or unterminated string.

       The <wordexp.h> header shall define the size_t type as described in <stddef.h>.

       The following shall be declared as functions and may also be defined as macros. Function prototypes shall be provided.

           int  wordexp(const char *restrict, wordexp_t *restrict, int);
           void wordfree(wordexp_t *);

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <stddef.h>

       The System Interfaces volume of POSIX.1‐2017, Section 2.6, Word Expansions

COPYRIGHT
       Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group
       Base Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.  In the event of any discrepancy between this  ver‐
       sion  and  the  original  IEEE and The Open Group Standard, the original IEEE and The Open Group Standard is the referee document. The original Standard can be obtained online at http://www.open‐
       group.org/unix/online.html .

       Any typographical or formatting errors that appear in this page are most likely to have been introduced during the conversion of the source files to man page format. To report  such  errors,  see
       https://www.kernel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                                                                                2017                                                                                      wordexp.h(0P)
