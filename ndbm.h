ndbm.h(0P)                                                                               POSIX Programmer's Manual                                                                              ndbm.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or
       the interface may not be implemented on Linux.

NAME
       ndbm.h — definitions for ndbm database operations

SYNOPSIS
       #include <ndbm.h>

DESCRIPTION
       The <ndbm.h> header shall define the datum type as a structure, which shall include at least the following members:

           void   *dptr  A pointer to the application's data.
           size_t  dsize The size of the object pointed to by dptr.

       The <ndbm.h> header shall define the size_t type as described in <stddef.h>.

       The <ndbm.h> header shall define the DBM type.

       The <ndbm.h> header shall define the following symbolic constants as possible values for the store_mode argument to dbm_store():

       DBM_INSERT    Insertion of new entries only.

       DBM_REPLACE   Allow replacing existing entries.

       The following shall be declared as functions and may also be defined as macros. Function prototypes shall be provided.

           int     dbm_clearerr(DBM *);
           void    dbm_close(DBM *);
           int     dbm_delete(DBM *, datum);
           int     dbm_error(DBM *);
           datum   dbm_fetch(DBM *, datum);
           datum   dbm_firstkey(DBM *);
           datum   dbm_nextkey(DBM *);
           DBM    *dbm_open(const char *, int, mode_t);
           int     dbm_store(DBM *, datum, datum, int);

       The <ndbm.h> header shall define the mode_t type through typedef, as described in <sys/types.h>.

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <stddef.h>, <sys_types.h>

       The System Interfaces volume of POSIX.1‐2017, dbm_clearerr()

COPYRIGHT
       Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group
       Base  Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.  In the event of any discrepancy between this ver‐
       sion and the original IEEE and The Open Group Standard, the original IEEE and The Open Group Standard is the referee document. The original Standard can be  obtained  online  at  http://www.open‐
       group.org/unix/online.html .

       Any  typographical  or  formatting errors that appear in this page are most likely to have been introduced during the conversion of the source files to man page format. To report such errors, see
       https://www.kernel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                                                                                2017                                                                                         ndbm.h(0P)
