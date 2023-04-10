aio.h(0P)                                                                                POSIX Programmer's Manual                                                                               aio.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or
       the interface may not be implemented on Linux.

NAME
       aio.h — asynchronous input and output

SYNOPSIS
       #include <aio.h>

DESCRIPTION
       The <aio.h> header shall define the aiocb structure, which shall include at least the following members:

           int             aio_fildes     File descriptor.
           off_t           aio_offset     File offset.
           volatile void  *aio_buf        Location of buffer.
           size_t          aio_nbytes     Length of transfer.
           int             aio_reqprio    Request priority offset.
           struct sigevent aio_sigevent   Signal number and value.
           int             aio_lio_opcode Operation to be performed.

       The <aio.h> header shall define the off_t, pthread_attr_t, size_t, and ssize_t types as described in <sys/types.h>.

       The <aio.h> header shall define the struct timespec structure as described in <time.h>.

       The <aio.h> header shall define the sigevent structure and sigval union as described in <signal.h>.

       The <aio.h> header shall define the following symbolic constants:

       AIO_ALLDONE   A return value indicating that none of the requested operations could be canceled since they are already complete.

       AIO_CANCELED  A return value indicating that all requested operations have been canceled.

       AIO_NOTCANCELED
                     A return value indicating that some of the requested operations could not be canceled since they are in progress.

       LIO_NOP       A lio_listio() element operation option indicating that no transfer is requested.

       LIO_NOWAIT    A lio_listio() synchronization operation indicating that the calling thread is to continue execution while the lio_listio() operation is being  performed,  and  no  notification  is
                     given when the operation is complete.

       LIO_READ      A lio_listio() element operation option requesting a read.

       LIO_WAIT      A lio_listio() synchronization operation indicating that the calling thread is to suspend until the lio_listio() operation is complete.

       LIO_WRITE     A lio_listio() element operation option requesting a write.

       The following shall be declared as functions and may also be defined as macros. Function prototypes shall be provided.

           int      aio_cancel(int, struct aiocb *);
           int      aio_error(const struct aiocb *);
           int      aio_fsync(int, struct aiocb *);
           int      aio_read(struct aiocb *);
           ssize_t  aio_return(struct aiocb *);
           int      aio_suspend(const struct aiocb *const [], int,
                        const struct timespec *);
           int      aio_write(struct aiocb *);
           int      lio_listio(int, struct aiocb *restrict const [restrict], int,
                        struct sigevent *restrict);

       Inclusion of the <aio.h> header may make visible symbols defined in the headers <fcntl.h>, <signal.h>, and <time.h>.

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <fcntl.h>, <signal.h>, <sys_types.h>, <time.h>

       The System Interfaces volume of POSIX.1‐2017, aio_cancel(), aio_error(), aio_fsync(), aio_read(), aio_return(), aio_suspend(), aio_write(), fsync(), lio_listio(), lseek(), read(), write()

COPYRIGHT
       Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group
       Base Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.  In the event of any discrepancy between this  ver‐
       sion  and  the  original  IEEE and The Open Group Standard, the original IEEE and The Open Group Standard is the referee document. The original Standard can be obtained online at http://www.open‐
       group.org/unix/online.html .

       Any typographical or formatting errors that appear in this page are most likely to have been introduced during the conversion of the source files to man page format. To report  such  errors,  see
       https://www.kernel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                                                                                2017                                                                                          aio.h(0P)
