poll.h(0P)                 POSIX Programmer's Manual                poll.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux
       implementation of this interface may differ (consult the  corresponding
       Linux  manual page for details of Linux behavior), or the interface may
       not be implemented on Linux.

NAME
       poll.h — definitions for the poll() function

SYNOPSIS
       #include <poll.h>

DESCRIPTION
       The <poll.h> header shall define the pollfd structure, which shall  in‐
       clude at least the following members:

           int    fd       The following descriptor being polled.
           short  events   The input event flags (see below).
           short  revents  The output event flags (see below).

       The <poll.h> header shall define the following type through typedef:

       nfds_t        An  unsigned integer type used for the number of file de‐
                     scriptors.

       The implementation shall support one or more  programming  environments
       in which the width of nfds_t is no greater than the width of type long.
       The names of these programming environments can be obtained  using  the
       confstr() function or the getconf utility.

       The <poll.h> header shall define the following symbolic constants, zero
       or more of which may be OR'ed together to form the  events  or  revents
       members in the pollfd structure:

       POLLIN        Data  other  than  high-priority data may be read without
                     blocking.

       POLLRDNORM    Normal data may be read without blocking.

       POLLRDBAND    Priority data may be read without blocking.

       POLLPRI       High priority data may be read without blocking.

       POLLOUT       Normal data may be written without blocking.

       POLLWRNORM    Equivalent to POLLOUT.

       POLLWRBAND    Priority data may be written.

       POLLERR       An error has occurred (revents only).

       POLLHUP       Device has been disconnected (revents only).

       POLLNVAL      Invalid fd member (revents only).

       The significance and semantics of normal, priority,  and  high-priority
       data are file and device-specific.

       The  following  shall be declared as a function and may also be defined
       as a macro. A function prototype shall be provided.

           int   poll(struct pollfd [], nfds_t, int);

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       The System Interfaces volume of POSIX.1‐2017, confstr(), poll()

       The Shell and Utilities volume of POSIX.1‐2017, getconf

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

IEEE/The Open Group                  2017                           poll.h(0P)
