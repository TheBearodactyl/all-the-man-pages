pwd.h(0P)                  POSIX Programmer's Manual                 pwd.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux
       implementation of this interface may differ (consult the  corresponding
       Linux  manual page for details of Linux behavior), or the interface may
       not be implemented on Linux.

NAME
       pwd.h — password structure

SYNOPSIS
       #include <pwd.h>

DESCRIPTION
       The <pwd.h> header shall define the  struct  passwd,  structure,  which
       shall include at least the following members:

           char    *pw_name   User's login name.
           uid_t    pw_uid    Numerical user ID.
           gid_t    pw_gid    Numerical group ID.
           char    *pw_dir    Initial working directory.
           char    *pw_shell  Program to use as shell.

       The  <pwd.h>  header shall define the gid_t, uid_t, and size_t types as
       described in <sys/types.h>.

       The following shall be declared as functions and may also be defined as
       macros. Function prototypes shall be provided.

           void           endpwent(void);
           struct passwd *getpwent(void);
           struct passwd *getpwnam(const char *);
           int            getpwnam_r(const char *, struct passwd *, char *,
                              size_t, struct passwd **);
           struct passwd *getpwuid(uid_t);
           int            getpwuid_r(uid_t, struct passwd *, char *,
                              size_t, struct passwd **);
           void           setpwent(void);

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <sys_types.h>

       The  System  Interfaces volume of POSIX.1‐2017, endpwent(), getpwnam(),
       getpwuid()

COPYRIGHT
       Portions of this text are reprinted and reproduced in  electronic  form
       from  IEEE Std 1003.1-2017, Standard for Information Technology -- Por‐
       table Operating System Interface (POSIX), The Open Group Base  Specifi‐
       cations  Issue  7, 2018 Edition, Copyright (C) 2018 by the Institute of
       Electrical and Electronics Engineers, Inc and The Open Group.   In  the
       event of any discrepancy between this version and the original IEEE and
       The Open Group Standard, the original IEEE and The Open Group  Standard
       is  the  referee document. The original Standard can be obtained online
       at http://www.opengroup.org/unix/online.html .

       Any typographical or formatting errors that appear  in  this  page  are
       most likely to have been introduced during the conversion of the source
       files to man page format. To report such errors,  see  https://www.ker‐
       nel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                  2017                            pwd.h(0P)
