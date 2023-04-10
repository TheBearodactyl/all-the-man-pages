search.h(0P)               POSIX Programmer's Manual              search.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux
       implementation of this interface may differ (consult the  corresponding
       Linux  manual page for details of Linux behavior), or the interface may
       not be implemented on Linux.

NAME
       search.h — search tables

SYNOPSIS
       #include <search.h>

DESCRIPTION
       The <search.h> header shall define the ENTRY type for  structure  entry
       which shall include the following members:

           char    *key
           void    *data

       and  shall  define  ACTION  and VISIT as enumeration data types through
       type definitions as follows:

           enum { FIND, ENTER } ACTION;
           enum { preorder, postorder, endorder, leaf } VISIT;

       The <search.h> header shall define the  size_t  type  as  described  in
       <sys/types.h>.

       The following shall be declared as functions and may also be defined as
       macros. Function prototypes shall be provided.

           int    hcreate(size_t);
           void   hdestroy(void);
           ENTRY *hsearch(ENTRY, ACTION);
           void   insque(void *, void *);
           void  *lfind(const void *, const void *, size_t *,
                     size_t, int (*)(const void *, const void *));
           void  *lsearch(const void *, void *, size_t *,
                     size_t, int (*)(const void *, const void *));
           void   remque(void *);
           void  *tdelete(const void *restrict, void **restrict,
                     int(*)(const void *, const void *));
           void  *tfind(const void *, void *const *,
                     int(*)(const void *, const void *));
           void  *tsearch(const void *, void **,
                     int(*)(const void *, const void *));
           void   twalk(const void *,
                     void (*)(const void *, VISIT, int ));

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <sys_types.h>

       The System Interfaces  volume  of  POSIX.1‐2017,  hcreate(),  insque(),
       lsearch(), tdelete()

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

IEEE/The Open Group                  2017                         search.h(0P)
