mqueue.h(0P)                                                                             POSIX Programmer's Manual                                                                            mqueue.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or
       the interface may not be implemented on Linux.

NAME
       mqueue.h — message queues (REALTIME)

SYNOPSIS
       #include <mqueue.h>

DESCRIPTION
       The <mqueue.h> header shall define the mqd_t type, which is used for message queue descriptors. This is not an array type.

       The <mqueue.h> header shall define the pthread_attr_t, size_t, and ssize_t types as described in <sys/types.h>.

       The <mqueue.h> header shall define the struct timespec structure as described in <time.h>.

       The tag sigevent shall be declared as naming an incomplete structure type, the contents of which are described in the <signal.h> header.

       The <mqueue.h> header shall define the mq_attr structure, which is used in getting and setting the attributes of a message queue. Attributes are initially set when the message queue  is  created.
       An mq_attr structure shall have at least the following fields:

           long    mq_flags    Message queue flags.
           long    mq_maxmsg   Maximum number of messages.
           long    mq_msgsize  Maximum message size.
           long    mq_curmsgs  Number of messages currently queued.

       The following shall be declared as functions and may also be defined as macros. Function prototypes shall be provided.

           int      mq_close(mqd_t);
           int      mq_getattr(mqd_t, struct mq_attr *);
           int      mq_notify(mqd_t, const struct sigevent *);
           mqd_t    mq_open(const char *, int, ...);
           ssize_t  mq_receive(mqd_t, char *, size_t, unsigned *);
           int      mq_send(mqd_t, const char *, size_t, unsigned);
           int      mq_setattr(mqd_t, const struct mq_attr *restrict,
                        struct mq_attr *restrict);
           ssize_t  mq_timedreceive(mqd_t, char *restrict, size_t,
                        unsigned *restrict, const struct timespec *restrict);
           int      mq_timedsend(mqd_t, const char *, size_t, unsigned,
                        const struct timespec *);
           int      mq_unlink(const char *);

       Inclusion of the <mqueue.h> header may make visible symbols defined in the headers <fcntl.h>, <signal.h>, and <time.h>.

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <fcntl.h>, <signal.h>, <sys_types.h>, <time.h>

       The System Interfaces volume of POSIX.1‐2017, mq_close(), mq_getattr(), mq_notify(), mq_open(), mq_receive(), mq_send(), mq_setattr(), mq_unlink()

COPYRIGHT
       Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group
       Base Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.  In the event of any discrepancy between this  ver‐
       sion  and  the  original  IEEE and The Open Group Standard, the original IEEE and The Open Group Standard is the referee document. The original Standard can be obtained online at http://www.open‐
       group.org/unix/online.html .

       Any typographical or formatting errors that appear in this page are most likely to have been introduced during the conversion of the source files to man page format. To report  such  errors,  see
       https://www.kernel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                                                                                2017                                                                                       mqueue.h(0P)
