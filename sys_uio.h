sys_uio.h(0P)              POSIX Programmer's Manual             sys_uio.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux
       implementation of this interface may differ (consult the  corresponding
       Linux  manual page for details of Linux behavior), or the interface may
       not be implemented on Linux.

NAME
       sys/uio.h — definitions for vector I/O operations

SYNOPSIS
       #include <sys/uio.h>

DESCRIPTION
       The <sys/uio.h> header shall define the iovec  structure,  which  shall
       include at least the following members:

           void   *iov_base  Base address of a memory region for input or output.
           size_t  iov_len   The size of the memory pointed to by iov_base.

       The <sys/uio.h> header uses the iovec structure for scatter/gather I/O.

       The <sys/uio.h> header shall define the ssize_t and size_t types as de‐
       scribed in <sys/types.h>.

       The following shall be declared as functions and may also be defined as
       macros. Function prototypes shall be provided.

           ssize_t readv(int, const struct iovec *, int);
           ssize_t writev(int, const struct iovec *, int);

       The following sections are informative.

APPLICATION USAGE
       The implementation can put a limit on the number of scatter/gather ele‐
       ments which can be processed in one call. The symbol {IOV_MAX}  defined
       in  <limits.h>  should always be used to learn about the limits instead
       of assuming a fixed value.

RATIONALE
       Traditionally, the maximum number of scatter/gather elements the system
       can  process in one call were described by the symbolic value {UIO_MAX‐
       IOV}.  In IEEE Std 1003.1‐2001 this value is replaced by  the  constant
       {IOV_MAX} which can be found in <limits.h>.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <limits.h>, <sys_types.h>

       The System Interfaces volume of POSIX.1‐2017, read(), readv(), write(),
       writev()

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

IEEE/The Open Group                  2017                        sys_uio.h(0P)
