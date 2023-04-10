PKG.M4(7)            BSD Miscellaneous Information Manual            PKG.M4(7)

NAME
     pkg.m4 — autoconf macros for using pkgconf

SYNOPSIS
     PKG_PREREQ
     PKG_PROG_PKG_CONFIG
     PKG_CHECK_MODULES
     PKG_CHECK_MODULES_STATIC
     PKG_INSTALLDIR
     PKG_NOARCH_INSTALLDIR
     PKG_CHECK_VAR
     PKG_WITH_MODULES
     PKG_HAVE_WITH_MODULES
     PKG_HAVE_DEFINE_WITH_MODULES

DESCRIPTION
     pkg.m4 is a collection of autoconf macros which help to configure com‐
     piler and linker flags for development libraries.  This allows build sys‐
     tems to detect other dependencies and use them with the system toolchain.

AUTOCONF MACROS
   PKG_PREREQ(MIN-VERSION)
     Checks that the version of the pkg.m4 autoconf macros in use is at least
     MIN-VERSION.  This can be used to ensure a particular pkg.m4 macro will
     be available.

   PKG_PROG_PKG_CONFIG([MIN-VERSION])
     Checks for an implementation of pkg-config which is at least MIN-VERSION
     or newer.

   PKG_CHECK_MODULES(VARIABLE-PREFIX, MODULES [,ACTION-IF-FOUND [,ACTION-IF-
     NOT-FOUND]])
   PKG_CHECK_MODULES_STATIC(VARIABLE-PREFIX, MODULES [,ACTION-IF-FOUND
     [,ACTION-IF-NOT-FOUND]])
     Checks whether a given module set exists, and if so, defines CFLAGS and
     LIBS variables prefixed by VARIABLE-PREFIX with the output from --cflags
     and --libs respectively.

     The optional ACTION-IF-FOUND and ACTION-IF-NOT-FOUND arguments are shell
     fragments that should be executed if the module set is found or not
     found.

     If $PKG_CONFIG is not defined, the PKG_PROG_PKG_CONFIG macro will be exe‐
     cuted to locate a pkg-config implementation.

     The PKG_CHECK_MODULES_STATIC macro provides the same behaviour as
     PKG_CHECK_MODULES with static linking enabled via the --static flag.

   PKG_INSTALLDIR(DIRECTORY)
     Defines the variable $pkgconfigdir as the location where a package should
     install pkg-config .pc files.

     By default the directory is $libdir/pkgconfig, but the default can be
     changed by passing the DIRECTORY parameter.

     This value can be overridden with the --with-pkgconfigdir configure pa‐
     rameter.

   PKG_NOARCH_INSTALLDIR(DIRECTORY)
     Defines the variable $noarch_pkgconfigdir as the location where a package
     should install pkg-config .pc files.

     By default the directory is $datadir/pkgconfig, but the default can be
     changed by passing the DIRECTORY parameter.

     This value can be overridden with the --with-noarch-pkgconfigdir config‐
     ure parameter.

   PKG_CHECK_VAR(VARIABLE, MODULE, CONFIG-VARIABLE, [ACTION-IF-FOUND],
     [ACTION-IF-NOT-FOUND])
     Retrieves the value of the pkg-config variable CONFIG-VARIABLE from
     MODULE and stores it in the VARIABLE variable.

     Note that repeated usage of VARIABLE is not recommended as the check will
     be skipped if the variable is already set.

   PKG_WITH_MODULES(VARIABLE-PREFIX, MODULES, [ACTION-IF-FOUND],[ACTION-IF-
     NOT-FOUND], [DESCRIPTION], [DEFAULT])
     Prepares a "--with-" configure option using the lowercase VARIABLE-PREFIX
     name, merging the behaviour of AC_ARG_WITH and PKG_CHECK_MODULES in a
     single macro.

   PKG_HAVE_WITH_MODULES(VARIABLE-PREFIX, MODULES, [DESCRIPTION], [DEFAULT])
     Convenience macro to trigger AM_CONDITIONAL after a PKG_WITH_MODULES
     check. VARIABLE-PREFIX is exported as a make variable.

   PKG_HAVE_DEFINE_WITH_MODULES(VARIABLE-PREFIX, MODULES, [DESCRIPTION],
     [DEFAULT])
     Convenience macro to trigger AM_CONDITIONAL and AC_DEFINE after a
     PKG_WITH_MODULES check. VARIABLE-PREFIX is exported as a make variable.

BSD                            December 5, 2017                            BSD
