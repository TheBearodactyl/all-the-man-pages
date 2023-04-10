ftw.h(0P)                                                                                POSIX Programmer's Manual                                                                               ftw.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or
       the interface may not be implemented on Linux.

NAME
       ftw.h — file tree traversal

SYNOPSIS
       #include <ftw.h>

DESCRIPTION
       The <ftw.h> header shall define the FTW structure, which shall include at least the following members:

           int  base
           int  level

       The <ftw.h> header shall define the following symbolic constants for use as values of the third argument to the application-supplied function that is passed as the second argument  to  ftw()  and
       nftw():

       FTW_F         Non-directory file.

       FTW_D         Directory.

       FTW_DNR       Directory without read permission.

       FTW_DP        Directory with subdirectories visited.

       FTW_NS        Unknown type; stat() failed.

       FTW_SL        Symbolic link.

       FTW_SLN       Symbolic link that names a nonexistent file.

       The <ftw.h> header shall define the following symbolic constants for use as values of the fourth argument to nftw():

       FTW_PHYS      Physical walk, does not follow symbolic links. Otherwise, nftw() follows links but does not walk down any path that crosses itself.

       FTW_MOUNT     The walk does not cross a mount point.

       FTW_DEPTH     All subdirectories are visited before the directory itself.

       FTW_CHDIR     The walk changes to each directory before reading it.

       The following shall be declared as functions and may also be defined as macros. Function prototypes shall be provided.

           int ftw(const char *, int (*)(const char *, const struct stat *,
               int), int);
           int nftw(const char *, int (*)(const char *, const struct stat *,
               int, struct FTW *), int, int);

       The <ftw.h> header shall define the stat structure and the symbolic names for st_mode and the file type test macros as described in <sys/stat.h>.

       Inclusion of the <ftw.h> header may also make visible all symbols from <sys/stat.h>.

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <sys_stat.h>

       The System Interfaces volume of POSIX.1‐2017, ftw(), nftw()

COPYRIGHT
       Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group
       Base Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.  In the event of any discrepancy between this  ver‐
       sion  and  the  original  IEEE and The Open Group Standard, the original IEEE and The Open Group Standard is the referee document. The original Standard can be obtained online at http://www.open‐
       group.org/unix/online.html .

       Any typographical or formatting errors that appear in this page are most likely to have been introduced during the conversion of the source files to man page format. To report  such  errors,  see
       https://www.kernel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                                                                                2017                                                                                          ftw.h(0P)
