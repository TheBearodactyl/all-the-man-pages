LUA(1)                                                                                    General Commands Manual                                                                                   LUA(1)

NAME
       lua - Lua interpreter

SYNOPSIS
       lua [ options ] [ script [ args ] ]

DESCRIPTION
       lua  is  the  standalone Lua interpreter.  It loads and executes Lua programs, either in textual source form or in precompiled binary form.  (Precompiled binaries are output by luac, the Lua com‐
       piler.)  lua can be used as a batch interpreter and also interactively.

       After handling the options, the Lua program in file script is loaded and executed.  The args are available to script as strings in a global table named arg and also as arguments to its main func‐
       tion.  When called without arguments, lua behaves as lua -v -i if the standard input is a terminal, and as lua - otherwise.

       In  interactive mode, lua prompts the user, reads lines from the standard input, and executes them as they are read.  If the line contains an expression, then the line is evaluated and the result
       is printed.  If a line does not contain a complete statement, then a secondary prompt is displayed and lines are read until a complete statement is formed or a syntax error is found.

       Before handling command line options and scripts, lua checks the contents of the environment variables LUA_INIT_5_4 and LUA_INIT, in that order.  If the contents are of the form '@filename', then
       filename is executed.  Otherwise, the contents are assumed to be a Lua statement and is executed.  When LUA_INIT_5_4 is defined, LUA_INIT is ignored.

OPTIONS
       -e stat
              execute statement stat.

       -i     enter interactive mode after executing script.

       -l name
              require library name into global name.

       -v     show version information.

       -E     ignore environment variables.

       -W     turn warnings on.

       --     stop handling options.

       -      stop handling options and execute the standard input as a file.

ENVIRONMENT VARIABLES
       The following environment variables affect the execution of lua.  When defined, the version-specific variants take priority and the version-neutral variants are ignored.

       LUA_INIT, LUA_INIT_5_4
              Code to be executed before command line options and scripts.

       LUA_PATH, LUA_PATH_5_4
              Initial value of package.cpath, the path used by require to search for Lua loaders.

       LUA_CPATH, LUA_CPATH_5_4
              Initial value of package.cpath, the path used by require to search for C loaders.

EXIT STATUS
       If  a  script calls os.exit, then lua exits with the given exit status.  Otherwise, lua exits with EXIT_SUCCESS (0 on POSIX systems) if there were no errors and with EXIT_FAILURE (1 on POSIX sys‐
       tems) if there were errors.  Errors raised in interactive mode do not cause exits.

DIAGNOSTICS
       Error messages should be self explanatory.

SEE ALSO
       luac(1)
       The documentation at lua.org, especially section 7 of the reference manual.

AUTHORS
       R. Ierusalimschy, L. H. de Figueiredo, W. Celes

                                                                                       $Date: 2020/05/21 19:31:21 $                                                                                 LUA(1)
