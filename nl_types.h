nl_types.h(0P)                                                                           POSIX Programmer's Manual                                                                          nl_types.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or
       the interface may not be implemented on Linux.

NAME
       nl_types.h — data types

SYNOPSIS
       #include <nl_types.h>

DESCRIPTION
       The <nl_types.h> header shall define at least the following types:

       nl_catd       Used by the message catalog functions catopen(), catgets(), and catclose() to identify a catalog descriptor.

       nl_item       Used by nl_langinfo() to identify items of langinfo data. Values of objects of type nl_item are defined in <langinfo.h>.

       The <nl_types.h> header shall define at least the following symbolic constants:

       NL_SETD       Used by gencat when no $set directive is specified in a message text source file. This constant can be passed as the value of set_id on subsequent calls to catgets()  (that  is,  to
                     retrieve messages from the default message set). The value of NL_SETD is implementation-defined.

       NL_CAT_LOCALE Value  that  must  be passed as the oflag argument to catopen() to ensure that message catalog selection depends on the LC_MESSAGES locale category, rather than directly on the LANG
                     environment variable.

       The following shall be declared as functions and may also be defined as macros. Function prototypes shall be provided.

           int       catclose(nl_catd);
           char     *catgets(nl_catd, int, int, const char *);
           nl_catd   catopen(const char *, int);

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <langinfo.h>

       The System Interfaces volume of POSIX.1‐2017, catclose(), catgets(), catopen(), nl_langinfo()

       The Shell and Utilities volume of POSIX.1‐2017, gencat

COPYRIGHT
       Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group
       Base  Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.  In the event of any discrepancy between this ver‐
       sion and the original IEEE and The Open Group Standard, the original IEEE and The Open Group Standard is the referee document. The original Standard can be  obtained  online  at  http://www.open‐
       group.org/unix/online.html .

       Any  typographical  or  formatting errors that appear in this page are most likely to have been introduced during the conversion of the source files to man page format. To report such errors, see
       https://www.kernel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                                                                                2017                                                                                     nl_types.h(0P)
