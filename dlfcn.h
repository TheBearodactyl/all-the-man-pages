dlfcn.h(0P)                                                                              POSIX Programmer's Manual                                                                             dlfcn.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or
       the interface may not be implemented on Linux.

NAME
       dlfcn.h — dynamic linking

SYNOPSIS
       #include <dlfcn.h>

DESCRIPTION
       The <dlfcn.h> header shall define at least the following symbolic constants for use in the construction of a dlopen() mode argument:

       RTLD_LAZY     Relocations are performed at an implementation-defined time.

       RTLD_NOW      Relocations are performed when the object is loaded.

       RTLD_GLOBAL   All symbols are available for relocation processing of other modules.

       RTLD_LOCAL    All symbols are not made available for relocation processing by other modules.

       The following shall be declared as functions and may also be defined as macros. Function prototypes shall be provided.

           int    dlclose(void *);
           char  *dlerror(void);
           void  *dlopen(const char *, int);
           void  *dlsym(void *restrict, const char *restrict);

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       The System Interfaces volume of POSIX.1‐2017, dlclose(), dlerror(), dlopen(), dlsym()

COPYRIGHT
       Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group
       Base  Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.  In the event of any discrepancy between this ver‐
       sion and the original IEEE and The Open Group Standard, the original IEEE and The Open Group Standard is the referee document. The original Standard can be  obtained  online  at  http://www.open‐
       group.org/unix/online.html .

       Any  typographical  or  formatting errors that appear in this page are most likely to have been introduced during the conversion of the source files to man page format. To report such errors, see
       https://www.kernel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                                                                                2017                                                                                        dlfcn.h(0P)
