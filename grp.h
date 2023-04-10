grp.h(0P)                                                                                POSIX Programmer's Manual                                                                               grp.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or
       the interface may not be implemented on Linux.

NAME
       grp.h — group structure

SYNOPSIS
       #include <grp.h>

DESCRIPTION
       The <grp.h> header shall declare the group structure, which shall include the following members:

           char   *gr_name The name of the group.
           gid_t   gr_gid  Numerical group ID.
           char  **gr_mem  Pointer to a null-terminated array of character
                           pointers to member names.

       The <grp.h> header shall define the gid_t and size_t types as described in <sys/types.h>.

       The following shall be declared as functions and may also be defined as macros. Function prototypes shall be provided.

           void           endgrent(void);
           struct group  *getgrent(void);
           struct group  *getgrgid(gid_t);
           int            getgrgid_r(gid_t, struct group *, char *,
                              size_t, struct group **);
           struct group  *getgrnam(const char *);
           int            getgrnam_r(const char *, struct group *, char *,
                              size_t , struct group **);
           void           setgrent(void);

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <sys_types.h>

       The System Interfaces volume of POSIX.1‐2017, endgrent(), getgrgid(), getgrnam()

COPYRIGHT
       Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group
       Base  Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.  In the event of any discrepancy between this ver‐
       sion and the original IEEE and The Open Group Standard, the original IEEE and The Open Group Standard is the referee document. The original Standard can be  obtained  online  at  http://www.open‐
       group.org/unix/online.html .

       Any  typographical  or  formatting errors that appear in this page are most likely to have been introduced during the conversion of the source files to man page format. To report such errors, see
       https://www.kernel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                                                                                2017                                                                                          grp.h(0P)
