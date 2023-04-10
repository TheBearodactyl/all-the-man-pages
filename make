MAKE(1)                                                                                        User Commands                                                                                       MAKE(1)

NAME
       make - GNU Make utility to maintain groups of programs

SYNOPSIS
       make [OPTION]... [TARGET]...

DESCRIPTION
       The  make  utility  will  determine  automatically which pieces of a large program need to be recompiled, and issue the commands to recompile them.  The manual describes the GNU implementation of
       make, which was written by Richard Stallman and Roland McGrath, and is currently maintained by Paul Smith.  Our examples show C programs, since they are very common, but you can use make with any
       programming language whose compiler can be run with a shell command.  In fact, make is not limited to programs.  You can use it to describe any task where some files must be updated automatically
       from others whenever the others change.

       To prepare to use make, you must write a file called the makefile that describes the relationships among files in your program, and provides commands for updating each file.  In a program,  typi‐
       cally the executable file is updated from object files, which are in turn made by compiling source files.

       Once a suitable makefile exists, each time you change some source files, this simple shell command:

              make

       suffices  to  perform  all  necessary recompilations.  The make program uses the makefile description and the last-modification times of the files to decide which of the files need to be updated.
       For each of those files, it issues the commands recorded in the makefile.

       make executes commands in the makefile to update one or more targets, where target is typically a program.  If no -f option is present, make will look for the makefiles GNUmakefile, makefile, and
       Makefile, in that order.

       Normally  you  should  call your makefile either makefile or Makefile.  (We recommend Makefile because it appears prominently near the beginning of a directory listing, right near other important
       files such as README.)  The first name checked, GNUmakefile, is not recommended for most makefiles.  You should use this name if you have a makefile that is specific to GNU Make, and will not  be
       understood by other versions of make.  If makefile is '-', the standard input is read.

       make updates a target if it depends on prerequisite files that have been modified since the target was last modified, or if the target does not exist.

OPTIONS
       -b, -m
            These options are ignored for compatibility with other versions of make.

       -B, --always-make
            Unconditionally make all targets.

       -C dir, --directory=dir
            Change  to  directory dir before reading the makefiles or doing anything else.  If multiple -C options are specified, each is interpreted relative to the previous one: -C / -C etc is equiva‐
            lent to -C /etc.  This is typically used with recursive invocations of make.

       -d   Print debugging information in addition to normal processing.  The debugging information says which files are being considered for remaking, which file-times are being compared and with what
            results, which files actually need to be remade, which implicit rules are considered and which are applied---everything interesting about how make decides what to do.

       --debug[=FLAGS]
            Print  debugging  information  in  addition  to  normal processing.  If the FLAGS are omitted, then the behavior is the same as if -d was specified.  FLAGS may be any or all of the following
            names, comma- or space-separated.  Only the first character is significant: the rest may be omitted: all for all debugging output (same as using -d), basic for basic debugging,  verbose  for
            more  verbose  basic debugging, implicit for showing implicit rule search operations, jobs for details on invocation of commands, makefile for debugging while remaking makefiles, print shows
            all recipes that are run even if they are silent, and why shows the reason make decided to rebuild each target.  Use none to disable all previous debugging flags.

       -e, --environment-overrides
            Give variables taken from the environment precedence over variables from makefiles.

       -E string, --eval string
            Interpret string using the eval function, before parsing any makefiles.

       -f file, --file=file, --makefile=FILE
            Use file as a makefile.

       -i, --ignore-errors
            Ignore all errors in commands executed to remake files.

       -I dir, --include-dir=dir
            Specifies a directory dir to search for included makefiles.  If several -I options are used to specify several directories, the directories are searched in the order specified.   Unlike  the
            arguments  to other flags of make, directories given with -I flags may come directly after the flag: -Idir is allowed, as well as -I dir.  This syntax is allowed for compatibility with the C
            preprocessor's -I flag.

       -j [jobs], --jobs[=jobs]
            Specifies the number of jobs (commands) to run simultaneously.  If there is more than one -j option, the last one is effective.  If the -j option is given without an argument, make will  not
            limit the number of jobs that can run simultaneously.

       --jobserver-style=style
            The style of jobserver to use.  The style may be one of fifo, pipe, or sem (Windows only).

       -k, --keep-going
            Continue  as  much  as possible after an error.  While the target that failed, and those that depend on it, cannot be remade, the other dependencies of these targets can be processed all the
            same.

       -l [load], --load-average[=load]
            Specifies that no new jobs (commands) should be started if there are others jobs running and the load average is at least load (a floating-point number).  With no argument, removes a  previ‐
            ous load limit.

       -L, --check-symlink-times
            Use the latest mtime between symlinks and target.

       -n, --just-print, --dry-run, --recon
            Print the commands that would be executed, but do not execute them (except in certain circumstances).

       -o file, --old-file=file, --assume-old=file
            Do  not  remake  the file file even if it is older than its dependencies, and do not remake anything on account of changes in file.  Essentially the file is treated as very old and its rules
            are ignored.

       -O[type], --output-sync[=type]
            When running multiple jobs in parallel with -j, ensure the output of each job is collected together rather than interspersed with output from other jobs.  If type is not specified or is tar‐
            get  the output from the entire recipe for each target is grouped together.  If type is line the output from each command line within a recipe is grouped together.  If type is recurse output
            from an entire recursive make is grouped together.  If type is none output synchronization is disabled.

       -p, --print-data-base
            Print the data base (rules and variable values) that results from reading the makefiles; then execute as usual or as otherwise specified.  This also prints the version information  given  by
            the -v switch (see below).  To print the data base without trying to remake any files, use make -p -f/dev/null.

       -q, --question
            ``Question mode''.  Do not run any commands, or print anything; just return an exit status that is zero if the specified targets are already up to date, nonzero otherwise.

       -r, --no-builtin-rules
            Eliminate use of the built-in implicit rules.  Also clear out the default list of suffixes for suffix rules.

       -R, --no-builtin-variables
            Don't define any built-in variables.

       -s, --silent, --quiet
            Silent operation; do not print the commands as they are executed.

       --no-silent
            Cancel the effect of the -s option.

       -S, --no-keep-going, --stop
            Cancel the effect of the -k option.

       -t, --touch
            Touch  files  (mark them up to date without really changing them) instead of running their commands.  This is used to pretend that the commands were done, in order to fool future invocations
            of make.

       --trace
            Information about the disposition of each target is printed (why the target is being rebuilt and what commands are run to rebuild it).

       -v, --version
            Print the version of the make program plus a copyright, a list of authors and a notice that there is no warranty.

       -w, --print-directory
            Print a message containing the working directory before and after other processing.  This may be useful for tracking down errors from complicated nests of recursive make commands.

       --no-print-directory
            Turn off -w, even if it was turned on implicitly.

       --shuffle[=MODE]
            Enable shuffling of goal and prerequisite ordering.  MODE is one of none to disable shuffle mode, random to shuffle prerequisites in random order, reverse to consider  prerequisites  in  re‐
            verse order, or an integer <seed> which enables random mode with a specific seed value.  If MODE is omitted the default is random.

       -W file, --what-if=file, --new-file=file, --assume-new=file
            Pretend that the target file has just been modified.  When used with the -n flag, this shows you what would happen if you were to modify that file.  Without -n, it is almost the same as run‐
            ning a touch command on the given file before running make, except that the modification time is changed only in the imagination of make.

       --warn-undefined-variables
            Warn when an undefined variable is referenced.

EXIT STATUS
       GNU Make exits with a status of zero if all makefiles were successfully parsed and no targets that were built failed.  A status of one will be returned if the -q flag was used and make determines
       that a target needs to be rebuilt.  A status of two will be returned if any errors were encountered.

SEE ALSO
       The full documentation for make is maintained as a Texinfo manual.  If the info and make programs are properly installed at your site, the command

              info make

       should give you access to the complete manual.

BUGS
       See the chapter ``Problems and Bugs'' in The GNU Make Manual.

AUTHOR
       This manual page contributed by Dennis Morse of Stanford University.  Further updates contributed by Mike Frysinger.  It has been reworked by Roland McGrath.  Maintained by Paul Smith.

COPYRIGHT
       Copyright © 1992-1993, 1996-2023 Free Software Foundation, Inc.  This file is part of GNU Make.

       GNU  Make  is  free  software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the Li‐
       cense, or (at your option) any later version.

       GNU Make is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  GNU  Gen‐
       eral Public License for more details.

       You should have received a copy of the GNU General Public License along with this program.  If not, see https://www.gnu.org/licenses/.

GNU                                                                                             26 May 2023                                                                                        MAKE(1)
MAKE(1P)                                                                                 POSIX Programmer's Manual                                                                                MAKE(1P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or
       the interface may not be implemented on Linux.

NAME
       make — maintain, update, and regenerate groups of programs (DEVELOPMENT)

SYNOPSIS
       make [-einpqrst] [-f makefile]... [-k|-S] [macro=value...]
           [target_name...]

DESCRIPTION
       The make utility shall update files that are derived from other files. A typical case is one where object files are derived from the corresponding source files. The make utility examines time re‐
       lationships  and shall update those derived files (called targets) that have modified times earlier than the modified times of the files (called prerequisites) from which they are derived.  A de‐
       scription file (makefile) contains a description of the relationships between files, and the commands that need to be executed to update the targets to reflect  changes  in  their  prerequisites.
       Each specification, or rule, shall consist of a target, optional prerequisites, and optional commands to be executed when a prerequisite is newer than the target. There are two types of rule:

        1. Inference rules, which have one target name with at least one <period> ('.')  and no <slash> ('/')

        2. Target rules, which can have more than one target name

       In addition, make shall have a collection of built-in macros and inference rules that infer prerequisite relationships to simplify maintenance of programs.

       To receive exactly the behavior described in this section, the user shall ensure that a portable makefile shall:

        *  Include the special target .POSIX

        *  Omit any special target reserved for implementations (a leading period followed by uppercase letters) that has not been specified by this section

       The behavior of make is unspecified if either or both of these conditions are not met.

OPTIONS
       The make utility shall conform to the Base Definitions volume of POSIX.1‐2017, Section 12.2, Utility Syntax Guidelines, except for Guideline 9.

       The following options shall be supported:

       -e        Cause environment variables, including those with null values, to override macro assignments within makefiles.

       -f makefile
                 Specify  a  different makefile. The argument makefile is a pathname of a description file, which is also referred to as the makefile.  A pathname of '-' shall denote the standard input.
                 There can be multiple instances of this option, and they shall be processed in the order specified. The effect of specifying the same option-argument more than once is unspecified.

       -i        Ignore error codes returned by invoked commands. This mode is the same as if the special target .IGNORE were specified without prerequisites.

       -k        Continue to update other targets that do not depend on the current target if a non-ignored error occurs while executing the commands to bring a target up-to-date.

       -n        Write commands that would be executed on standard output, but do not execute them. However, lines with a <plus-sign> ('+') prefix shall be executed. In this mode, lines with an  at-sign
                 ('@') character prefix shall be written to standard output.

       -p        Write to standard output the complete set of macro definitions and target descriptions. The output format is unspecified.

       -q        Return  a  zero  exit value if the target file is up-to-date; otherwise, return an exit value of 1. Targets shall not be updated if this option is specified. However, a makefile command
                 line (associated with the targets) with a <plus-sign> ('+') prefix shall be executed.

       -r        Clear the suffix list and do not use the built-in rules.

       -S        Terminate make if an error occurs while executing the commands to bring a target up-to-date. This shall be the default and the opposite of -k.

       -s        Do not write makefile command lines or touch messages (see -t) to standard output before executing. This mode shall be the same as if the special target .SILENT were  specified  without
                 prerequisites.

       -t        Update  the  modification  time of each target as though a touch target had been executed. Targets that have prerequisites but no commands (see Target Rules), or that are already up-to-
                 date, shall not be touched in this manner.  Write messages to standard output for each target file indicating the name of the file and that it was touched. Normally, the  makefile  com‐
                 mand lines associated with each target are not executed. However, a command line with a <plus-sign> ('+') prefix shall be executed.

       Any  options  specified  in the MAKEFLAGS environment variable shall be evaluated before any options specified on the make utility command line. If the -k and -S options are both specified on the
       make utility command line or by the MAKEFLAGS environment variable, the last option specified shall take precedence.  If the -f or -p options appear in the MAKEFLAGS environment variable, the re‐
       sult is undefined.

OPERANDS
       The following operands shall be supported:

       target_name
                 Target names, as defined in the EXTENDED DESCRIPTION section. If no target is specified, while make is processing the makefiles, the first target that make encounters that is not a spe‐
                 cial target or an inference rule shall be used.

       macro=value
                 Macro definitions, as defined in Macros.

       If the target_name and macro=value operands are intermixed on the make utility command line, the results are unspecified.

STDIN
       The standard input shall be used only if the makefile option-argument is '-'.  See the INPUT FILES section.

INPUT FILES
       The input file, otherwise known as the makefile, is a text file containing rules, macro definitions, include lines, and comments.  See the EXTENDED DESCRIPTION section.

ENVIRONMENT VARIABLES
       The following environment variables shall affect the execution of make:

       LANG      Provide a default value for the internationalization variables that are unset or null. (See the Base Definitions volume of POSIX.1‐2017, Section 8.2, Internationalization Variables  for
                 the precedence of internationalization variables used to determine the values of locale categories.)

       LC_ALL    If set to a non-empty string value, override the values of all the other internationalization variables.

       LC_CTYPE  Determine the locale for the interpretation of sequences of bytes of text data as characters (for example, single-byte as opposed to multi-byte characters in arguments and input files).

       LC_MESSAGES
                 Determine the locale that should be used to affect the format and contents of diagnostic messages written to standard error.

       MAKEFLAGS
                 This  variable  shall be interpreted as a character string representing a series of option characters to be used as the default options. The implementation shall accept both of the fol‐
                 lowing formats (but need not accept them when intermixed):

                  *  The characters are option letters without the leading <hyphen-minus> characters or <blank> separation used on a make utility command line.

                  *  The characters are formatted in a manner similar to a portion of the make utility command line: options are preceded by <hyphen-minus> characters and <blank>-separated as  described
                     in  the Base Definitions volume of POSIX.1‐2017, Section 12.2, Utility Syntax Guidelines.  The macro=value macro definition operands can also be included. The difference between the
                     contents of MAKEFLAGS and the make utility command line is that the contents of the variable shall not be subjected to the word expansions (see Section 2.6, Word Expansions) associ‐
                     ated with parsing the command line values.

       NLSPATH   Determine the location of message catalogs for the processing of LC_MESSAGES.

       PROJECTDIR
                 Provide a directory to be used to search for SCCS files not found in the current directory. In all of the following cases, the search for SCCS files is made in the directory SCCS in the
                 identified directory. If the value of PROJECTDIR begins with a <slash>, it shall be considered an absolute pathname; otherwise, the value of PROJECTDIR is treated as  a  user  name  and
                 that  user's  initial  working  directory shall be examined for a subdirectory src or source.  If such a directory is found, it shall be used. Otherwise, the value is used as a relative
                 pathname.

                 If PROJECTDIR is not set or has a null value, the search for SCCS files shall be made in the directory SCCS in the current directory.

                 The setting of PROJECTDIR affects all files listed in the remainder of this utility description for files with a component named SCCS.

       The value of the SHELL environment variable shall not be used as a macro and shall not be modified by defining the SHELL macro in a makefile or on the command line. All  other  environment  vari‐
       ables, including those with null values, shall be used as macros, as defined in Macros.

ASYNCHRONOUS EVENTS
       If  not  already ignored, make shall trap SIGHUP, SIGTERM, SIGINT, and SIGQUIT and remove the current target unless the target is a directory or the target is a prerequisite of the special target
       .PRECIOUS or unless one of the -n, -p, or -q options was specified. Any targets removed in this manner shall be reported in diagnostic messages of unspecified format, written to  standard  error.
       After this cleanup process, if any, make shall take the standard action for all other signals.

STDOUT
       The  make  utility shall write all commands to be executed to standard output unless the -s option was specified, the command is prefixed with an at-sign, or the special target .SILENT has either
       the current target as a prerequisite or has no prerequisites. If make is invoked without any work needing to be done, it shall write a message to standard output indicating  that  no  action  was
       taken.  If  the -t option is present and a file is touched, make shall write to standard output a message of unspecified format indicating that the file was touched, including the filename of the
       file.

STDERR
       The standard error shall be used only for diagnostic messages.

OUTPUT FILES
       Files can be created when the -t option is present. Additional files can also be created by the utilities invoked by make.

EXTENDED DESCRIPTION
       The make utility attempts to perform the actions required to ensure that the specified targets are up-to-date. A target shall be considered up-to-date if it exists and is newer than  all  of  its
       dependencies,  or  if it has already been made up-to-date by the current invocation of make (regardless of the target's existence or age). A target may also be considered up-to-date if it exists,
       is the same age as one or more of its prerequisites, and is newer than the remaining prerequisites (if any).  The make utility shall treat all prerequisites as targets themselves and  recursively
       ensure  that  they are up-to-date, processing them in the order in which they appear in the rule. The make utility shall use the modification times of files to determine whether the corresponding
       targets are out-of-date.

       To ensure that a target is up-to-date, make shall ensure that all of the prerequisites of a target are up-to-date, then check to see if the target itself is up-to-date. If the target is  not  up-
       to-date,  the  target  shall be made up-to-date by executing the rule's commands (if any). If the target does not exist after the target has been successfully made up-to-date, the target shall be
       treated as being newer than any target for which it is a prerequisite.

       If a target exists and there is neither a target rule nor an inference rule for the target, the target shall be considered up-to-date. It shall be an error if make attempts to ensure that a  tar‐
       get is up-to-date but the target does not exist and there is neither a target rule nor an inference rule for the target.

   Makefile Syntax
       A makefile can contain rules, macro definitions (see Macros), include lines, and comments. There are two kinds of rules: inference rules and target rules.  The make utility shall contain a set of
       built-in inference rules. If the -r option is present, the built-in rules shall not be used and the suffix list shall be cleared. Additional rules of both types can be specified in a makefile. If
       a  rule  is  defined  more  than once, the value of the rule shall be that of the last one specified. Macros can also be defined more than once, and the value of the macro is specified in Macros.
       There are three kinds of comments: blank lines, empty lines, and a <number-sign> ('#') and all following characters up to the first unescaped <newline> character. Blank lines,  empty  lines,  and
       lines with <number-sign> ('#') as the first character on the line are also known as comment lines.

       By  default,  the  following files shall be tried in sequence: ./makefile and ./Makefile.  If neither ./makefile or ./Makefile are found, other implementation-defined files may also be tried.  On
       XSI-conformant systems, the additional files ./s.makefile, SCCS/s.makefile, ./s.Makefile, and SCCS/s.Makefile shall also be tried.

       The -f option shall direct make to ignore any of these default files and use the specified argument as a makefile instead. If the '-' argument is specified, standard input shall be used.

       The term makefile is used to refer to any rules provided by the user, whether in ./makefile or its variants, or specified by the -f option.

       The rules in makefiles shall consist of the following types of lines: target rules, including special targets (see Target Rules), inference rules (see Inference  Rules),  macro  definitions  (see
       Macros), and comments.

       Target and Inference Rules may contain command lines.  Command lines can have a prefix that shall be removed before execution (see Makefile Execution).

       When an escaped <newline> (one preceded by a <backslash>) is found anywhere in the makefile except in a command line, an include line, or a line immediately preceding an include line, it shall be
       replaced, along with any leading white space on the following line, with a single <space>.  When an escaped <newline> is found in a command line in a makefile, the command line shall contain  the
       <backslash>,  the  <newline>, and the next line, except that the first character of the next line shall not be included if it is a <tab>.  When an escaped <newline> is found in an include line or
       in a line immediately preceding an include line, the behavior is unspecified.

   Include Lines
       If the word include appears at the beginning of a line and is followed by one or more <blank> characters, the string formed by the remainder of the line shall be processed as follows to produce a
       pathname:

        *  The  trailing <newline>, any <blank> characters immediately preceding a comment, and any comment shall be discarded. If the resulting string contains any double-quote characters ('"') the be‐
           havior is unspecified.

        *  The resulting string shall be processed for macro expansion (see Macros).

        *  Any <blank> characters that appear after the first non-<blank> shall be used as separators to divide the macro-expanded string into fields. It is unspecified  whether  any  other  white-space
           characters are also used as separators. It is unspecified whether pathname expansion (see Section 2.13, Pattern Matching Notation) is also performed.

        *  If the processing of separators and optional pathname expansion results in either zero or two or more non-empty fields, the behavior is unspecified. If it results in one non-empty field, that
           field is taken as the pathname.

       If the pathname does not begin with a '/' it shall be treated as relative to the current working directory of the process, not relative to the directory containing the makefile.  If the file does
       not exist in this location, it is unspecified whether additional directories are searched.

       The contents of the file specified by the pathname shall be read and processed as if they appeared in the makefile in place of the include line. If the file ends with an escaped <newline> the be‐
       havior is unspecified.

       The file may itself contain further include lines. Implementations shall support nesting of include files up to a depth of at least 16.

   Makefile Execution
       Makefile command lines shall be processed one at a time.

       Makefile command lines can have one or more of the following prefixes: a <hyphen-minus> ('-'), an at-sign ('@'), or a <plus-sign> ('+').  These shall modify the way in which  make  processes  the
       command.

       -     If  the command prefix contains a <hyphen-minus>, or the -i option is present, or the special target .IGNORE has either the current target as a prerequisite or has no prerequisites, any er‐
             ror found while executing the command shall be ignored.

       @     If the command prefix contains an at-sign and the make utility command line -n option is not specified, or the -s option is present, or the special target .SILENT  has  either  the  current
             target as a prerequisite or has no prerequisites, the command shall not be written to standard output before it is executed.

       +     If the command prefix contains a <plus-sign>, this indicates a makefile command line that shall be executed even if -n, -q, or -t is specified.

       An  execution  line is built from the command line by removing any prefix characters. Except as described under the at-sign prefix, the execution line shall be written to the standard output, op‐
       tionally preceded by a <tab>.  The execution line shall then be executed by a shell as if it were passed as the argument to the system() interface, except that if errors  are  not  being  ignored
       then  the  shell -e option shall also be in effect. If errors are being ignored for the command (as a result of the -i option, a '-' command prefix, or a .IGNORE special target), the shell -e op‐
       tion shall not be in effect. The environment for the command being executed shall contain all of the variables in the environment of make.

       By default, when make receives a non-zero status from the execution of a command, it shall terminate with an error message to standard error.

   Target Rules
       Target rules are formatted as follows:

           target [target...]: [prerequisite...][;command]
           [<tab>command
           <tab>command
           ...]

           line that does not begin with <tab>

       Target entries are specified by a <blank>-separated, non-null list of targets, then a <colon>, then a <blank>-separated, possibly empty list of prerequisites. Text  following  a  <semicolon>,  if
       any,  and all following lines that begin with a <tab>, are makefile command lines to be executed to update the target. The first non-empty line that does not begin with a <tab> or '#' shall begin
       a new entry. Any comment line may begin a new entry.

       Applications shall select target names from the set of characters consisting solely of periods, underscores, digits, and alphabetics from the portable character set (see the Base Definitions vol‐
       ume  of  POSIX.1‐2017, Section 6.1, Portable Character Set).  Implementations may allow other characters in target names as extensions. The interpretation of targets containing the characters '%'
       and '"' is implementation-defined.

       A target that has prerequisites, but does not have any commands, can be used to add to the prerequisite list for that target. Only one target rule for any given target can contain commands.

       Lines that begin with one of the following are called special targets and control the operation of make:

       .DEFAULT  If the makefile uses this special target, the application shall ensure that it is specified with commands, but without prerequisites. The commands shall be used by make if there are  no
                 other rules available to build a target.

       .IGNORE   Prerequisites  of  this special target are targets themselves; this shall cause errors from commands associated with them to be ignored in the same manner as specified by the -i option.
                 Subsequent occurrences of .IGNORE shall add to the list of targets ignoring command errors. If no prerequisites are specified, make shall behave as if the -i option had  been  specified
                 and errors from all commands associated with all targets shall be ignored.

       .POSIX    The application shall ensure that this special target is specified without prerequisites or commands. If it appears as the first non-comment line in the makefile, make shall process the
                 makefile as specified by this section; otherwise, the behavior of make is unspecified.

       .PRECIOUS Prerequisites of this special target shall not be removed if make receives one of the asynchronous events explicitly described in the ASYNCHRONOUS EVENTS section. Subsequent occurrences
                 of .PRECIOUS shall add to the list of precious files. If no prerequisites are specified, all targets in the makefile shall be treated as if specified with .PRECIOUS.

       .SCCS_GET The application shall ensure that this special target is specified without prerequisites. If this special target is included in a makefile, the commands specified with this target shall
                 replace the default commands associated with this special target (see Default Rules).  The commands specified with this target are used to get all SCCS files that are not found  in  the
                 current directory.

                 When  source files are named in a dependency list, make shall treat them just like any other target. Because the source file is presumed to be present in the directory, there is no need
                 to add an entry for it to the makefile. When a target has no dependencies, but is present in the directory, make shall assume that that file is up-to-date. If,  however,  an  SCCS  file
                 named SCCS/s.source_file is found for a target source_file, make compares the timestamp of the target file with that of the SCCS/s.source_file to ensure the target is up-to-date. If the
                 target is missing, or if the SCCS file is newer, make shall automatically issue the commands specified for the .SCCS_GET special target to retrieve the most recent version. However,  if
                 the target is writable by anyone, make shall not retrieve a new version.

       .SILENT   Prerequisites of this special target are targets themselves; this shall cause commands associated with them not to be written to the standard output before they are executed. Subsequent
                 occurrences of .SILENT shall add to the list of targets with silent commands. If no prerequisites are specified, make shall behave as if the -s option had been specified and no commands
                 or touch messages associated with any target shall be written to standard output.

       .SUFFIXES Prerequisites  of  .SUFFIXES  shall be appended to the list of known suffixes and are used in conjunction with the inference rules (see Inference Rules).  If .SUFFIXES does not have any
                 prerequisites, the list of known suffixes shall be cleared.

       The special targets .IGNORE, .POSIX, .PRECIOUS, .SILENT, and .SUFFIXES shall be specified without commands.

       Targets with names consisting of a leading <period> followed by the uppercase letters "POSIX" and then any other characters are reserved for future standardization.  Targets with names consisting
       of a leading <period> followed by one or more uppercase letters are reserved for implementation extensions.

   Macros
       Macro definitions are in the form:

           string1 = [string2]

       The  macro  named  string1  is defined as having the value of string2, where string2 is defined as all characters, if any, after the <equals-sign>, up to a comment character ('#') or an unescaped
       <newline>.  Any <blank> characters immediately before or after the <equals-sign> shall be ignored.

       Applications shall select macro names from the set of characters consisting solely of periods, underscores, digits, and alphabetics from the portable character set (see the Base Definitions  vol‐
       ume of POSIX.1‐2017, Section 6.1, Portable Character Set).  A macro name shall not contain an <equals-sign>.  Implementations may allow other characters in macro names as extensions.

       Macros can appear anywhere in the makefile. Macro expansions using the forms $(string1) or ${string1} shall be replaced by string2, as follows:

        *  Macros in target lines shall be evaluated when the target line is read.

        *  Macros in makefile command lines shall be evaluated when the command is executed.

        *  Macros in the string before the <equals-sign> in a macro definition shall be evaluated when the macro assignment is made.

        *  Macros after the <equals-sign> in a macro definition shall not be evaluated until the defined macro is used in a rule or command, or before the <equals-sign> in a macro definition.

       The  parentheses  or braces are optional if string1 is a single character. The macro $$ shall be replaced by the single character '$'.  If string1 in a macro expansion contains a macro expansion,
       the results are unspecified.

       Macro expansions using the forms $(string1[:subst1=[subst2]]) or ${string1[:subst1=[subst2]]} can be used to replace all occurrences of subst1 with subst2 when  the  macro  substitution  is  per‐
       formed.  The  subst1 to be replaced shall be recognized when it is a suffix at the end of a word in string1 (where a word, in this context, is defined to be a string delimited by the beginning of
       the line, a <blank>, or a <newline>).  If string1 in a macro expansion contains a macro expansion, the results are unspecified. If a <percent-sign> character appears as part of subst1  or  subst2
       after any macros have been recursively expanded, the results are unspecified.

       Macro  expansions  in string1 of macro definition lines shall be evaluated when read. Macro expansions in string2 of macro definition lines shall be performed when the macro identified by string1
       is expanded in a rule or command.

       Macro definitions shall be taken from the following sources, in the following logical order, before the makefile(s) are read.

        1. Macros specified on the make utility command line, in the order specified on the command line. It is unspecified whether the internal macros defined in Internal Macros are accepted from  this
           source.

        2. Macros defined by the MAKEFLAGS environment variable, in the order specified in the environment variable. It is unspecified whether the internal macros defined in Internal Macros are accepted
           from this source.

        3. The contents of the environment, excluding the MAKEFLAGS and SHELL variables and including the variables with null values.

        4. Macros defined in the inference rules built into make.

       Macro definitions from these sources shall not override macro definitions from a lower-numbered source. Macro definitions from a single source (for example, the make  utility  command  line,  the
       MAKEFLAGS environment variable, or the other environment variables) shall override previous macro definitions from the same source.

       Macros defined in the makefile(s) shall override macro definitions that occur before them in the makefile(s) and macro definitions from source 4. If the -e option is not specified, macros defined
       in the makefile(s) shall override macro definitions from source 3. Macros defined in the makefile(s) shall not override macro definitions from source 1 or source 2.

       Before the makefile(s) are read, all of the make utility command line options (except -f and -p) and make utility command line macro definitions (except any for the MAKEFLAGS macro), not  already
       included  in  the  MAKEFLAGS macro, shall be added to the MAKEFLAGS macro, quoted in an implementation-defined manner such that when MAKEFLAGS is read by another instance of the make command, the
       original macro's value is recovered. Other implementation-defined options and macros may also be added to the MAKEFLAGS macro. If this modifies the value of the MAKEFLAGS macro, or, if the  MAKE‐
       FLAGS macro is modified at any subsequent time, the MAKEFLAGS environment variable shall be modified to match the new value of the MAKEFLAGS macro. The result of setting MAKEFLAGS in the Makefile
       is unspecified.

       Before the makefile(s) are read, all of the make utility command line macro definitions (except the MAKEFLAGS macro or the SHELL macro) shall be added to the environment of make.  Other implemen‐
       tation-defined  variables may also be added to the environment of make.  Macros defined by the MAKEFLAGS environment variable and macros defined in the makefile(s) shall not be added to the envi‐
       ronment of make if they are not already in its environment. With the exception of SHELL (see below), it is unspecified whether macros defined in these ways update  the  value  of  an  environment
       variable that already exists in the environment of make.

       The  SHELL macro shall be treated specially. It shall be provided by make and set to the pathname of the shell command language interpreter (see sh).  The SHELL environment variable shall not af‐
       fect the value of the SHELL macro. If SHELL is defined in the makefile or is specified on the command line, it shall replace the original value of the SHELL macro, but shall not affect the  SHELL
       environment variable. Other effects of defining SHELL in the makefile or on the command line are implementation-defined.

   Inference Rules
       Inference rules are formatted as follows:

           target:
           <tab>command
           [<tab>command]
           ...

           line that does not begin with <tab> or #

       The  application  shall ensure that the target portion is a valid target name (see Target Rules) of the form .s2 or .s1.s2 (where .s1 and .s2 are suffixes that have been given as prerequisites of
       the .SUFFIXES special target and s1 and s2 do not contain any <slash> or <period> characters.) If there is only one <period> in the target, it is a single-suffix inference rule. Targets with  two
       periods are double-suffix inference rules. Inference rules can have only one target before the <colon>.

       The  application  shall  ensure  that the makefile does not specify prerequisites for inference rules; no characters other than white space shall follow the <colon> in the first line, except when
       creating the empty rule, described below. Prerequisites are inferred, as described below.

       Inference rules can be redefined. A target that matches an existing inference rule shall overwrite the old inference rule. An empty rule can be created with  a  command  consisting  of  simply  a
       <semicolon> (that is, the rule still exists and is found during inference rule search, but since it is empty, execution has no effect). The empty rule can also be formatted as follows:

           rule: ;

       where zero or more <blank> characters separate the <colon> and <semicolon>.

       The make utility uses the suffixes of targets and their prerequisites to infer how a target can be made up-to-date. A list of inference rules defines the commands to be executed. By default, make
       contains a built-in set of inference rules. Additional rules can be specified in the makefile.

       The special target .SUFFIXES contains as its prerequisites a list of suffixes that shall be used by the inference rules. The order in which the suffixes are specified defines the order  in  which
       the  inference  rules  for the suffixes are used. New suffixes shall be appended to the current list by specifying a .SUFFIXES special target in the makefile. A .SUFFIXES target with no prerequi‐
       sites shall clear the list of suffixes. An empty .SUFFIXES target followed by a new .SUFFIXES list is required to change the order of the suffixes.

       Normally, the user would provide an inference rule for each suffix.  The inference rule to update a target with a suffix .s1 from a prerequisite with a suffix .s2 is specified as a target .s2.s1.
       The internal macros provide the means to specify general inference rules (see Internal Macros).

       When  no  target  rule is found to update a target, the inference rules shall be checked. The suffix of the target (.s1) to be built is compared to the list of suffixes specified by the .SUFFIXES
       special targets. If the .s1 suffix is found in .SUFFIXES, the inference rules shall be searched in the order defined for the first .s2.s1 rule whose prerequisite file ($*.s2) exists. If the  tar‐
       get is out-of-date with respect to this prerequisite, the commands for that inference rule shall be executed.

       If  the target to be built does not contain a suffix and there is no rule for the target, the single suffix inference rules shall be checked. The single-suffix inference rules define how to build
       a target if a file is found with a name that matches the target name with one of the single suffixes appended. A rule with one suffix .s2 is the definition of how to build target from  target.s2.
       The other suffix (.s1) is treated as null.

       A  <tilde> ('~') in the above rules refers to an SCCS file in the current directory.  Thus, the rule .c~.o would transform an SCCS C-language source file into an object file (.o).  Because the s.
       of the SCCS files is a prefix, it is incompatible with make's suffix point of view. Hence, the '~' is a way of changing any file reference into an SCCS file reference.

   Libraries
       If a target or prerequisite contains parentheses, it shall be treated as a member of an archive library. For the lib(member.o) expression lib refers to the name of the archive  library  and  mem‐
       ber.o  to  the  member  name. The application shall ensure that the member is an object file with the .o suffix. The modification time of the expression is the modification time for the member as
       kept in the archive library; see ar.  The .a suffix shall refer to an archive library. The .s2.a rule shall be used to update a member in the library from a file with a suffix .s2.

   Internal Macros
       The make utility shall maintain five internal macros that can be used in target and inference rules. In order to clearly define the meaning of these macros, some clarification of the terms target
       rule, inference rule, target, and prerequisite is necessary.

       Target  rules are specified by the user in a makefile for a particular target. Inference rules are user-specified or make-specified rules for a particular class of target name. Explicit prerequi‐
       sites are those prerequisites specified in a makefile on target lines.  Implicit prerequisites are those prerequisites that are generated when inference rules are used. Inference  rules  are  ap‐
       plied to implicit prerequisites or to explicit prerequisites that do not have target rules defined for them in the makefile. Target rules are applied to targets specified in the makefile.

       Before any target in the makefile is updated, each of its prerequisites (both explicit and implicit) shall be updated. This shall be accomplished by recursively processing each prerequisite. Upon
       recursion, each prerequisite shall become a target itself. Its prerequisites in turn shall be processed recursively until a target is found that has no prerequisites, or further  recursion  would
       require  applying two inference rules one immediately after the other, at which point the recursion shall stop. As an extension, implementations may continue recursion when two or more successive
       inference rules need to be applied; however, if there are multiple different chains of such rules that could be used to create the target, it is unspecified which chain  is  used.  The  recursion
       shall then back up, updating each target as it goes.

       In the definitions that follow, the word target refers to one of:

        *  A target specified in the makefile

        *  An explicit prerequisite specified in the makefile that becomes the target when make processes it during recursion

        *  An implicit prerequisite that becomes a target when make processes it during recursion

       In the definitions that follow, the word prerequisite refers to one of the following:

        *  An explicit prerequisite specified in the makefile for a particular target

        *  An implicit prerequisite generated as a result of locating an appropriate inference rule and corresponding file that matches the suffix of the target

       The five internal macros are:

       $@      The $@ shall evaluate to the full target name of the current target, or the archive filename part of a library archive target. It shall be evaluated for both target and inference rules.

               For  example, in the .c.a inference rule, $@ represents the out-of-date .a file to be built. Similarly, in a makefile target rule to build lib.a from file.c, $@ represents the out-of-date
               lib.a.

       $%      The $% macro shall be evaluated only when the current target is an archive library member of the form libname(member.o).  In these cases, $@ shall evaluate to libname and $% shall  evalu‐
               ate to member.o.  The $% macro shall be evaluated for both target and inference rules.

               For example, in a makefile target rule to build lib.a(file.o), $% represents file.o, as opposed to $@, which represents lib.a.

       $?      The $? macro shall evaluate to the list of prerequisites that are newer than the current target. It shall be evaluated for both target and inference rules.

               For  example,  in  a  makefile  target rule to build prog from file1.o, file2.o, and file3.o, and where prog is not out-of-date with respect to file1.o, but is out-of-date with respect to
               file2.o and file3.o, $? represents file2.o and file3.o.

       $<      In an inference rule, the $< macro shall evaluate to the filename whose existence allowed the inference rule to be chosen for the target.  In the .DEFAULT rule, the $< macro shall  evalu‐
               ate to the current target name. The meaning of the $< macro shall be otherwise unspecified.

               For example, in the .c.a inference rule, $< represents the prerequisite .c file.

       $*      The $* macro shall evaluate to the current target name with its suffix deleted. It shall be evaluated at least for inference rules.

               For example, in the .c.a inference rule, $*.o represents the out-of-date .o file that corresponds to the prerequisite .c file.

       Each  of  the  internal macros has an alternative form. When an uppercase 'D' or 'F' is appended to any of the macros, the meaning shall be changed to the directory part for 'D' and filename part
       for 'F'.  The directory part is the path prefix of the file without a trailing <slash>; for the current directory, the directory part is '.'.  When the $? macro contains more than  one  prerequi‐
       site filename, the $(?D) and $(?F) (or ${?D} and ${?F}) macros expand to a list of directory name parts and filename parts respectively.

       For the target lib(member.o) and the s2.a rule, the internal macros shall be defined as:

       $<      member.s2

       $*      member

       $@      lib

       $?      member.s2

       $%      member.o

   Default Rules
       The  default  rules  for  make shall achieve results that are the same as if the following were used.  Implementations that do not support the C-Language Development Utilities option may omit CC,
       CFLAGS, YACC, YFLAGS, LEX, LFLAGS, LDFLAGS, and the .c, .y, and .l inference rules. Implementations that do not support FORTRAN may omit FC, FFLAGS, and the .f  inference  rules.  Implementations
       may provide additional macros and rules.

           SPECIAL TARGETS

           .SCCS_GET: sccs $(SCCSFLAGS) get $(SCCSGETFLAGS) $@

           .SUFFIXES: .o .c .y .l .a .sh .f .c~ .y~ .l~ .sh~ .f~

           MACROS

           MAKE=make
           AR=ar
           ARFLAGS=-rv
           YACC=yacc
           YFLAGS=
           LEX=lex
           LFLAGS=
           LDFLAGS=
           CC=c99
           CFLAGS=-O 1
           FC=fort77
           FFLAGS=-O 1
           GET=get
           GFLAGS=
           SCCSFLAGS=
           SCCSGETFLAGS=-s

           SINGLE SUFFIX RULES

           .c:
               $(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

           .f:
               $(FC) $(FFLAGS) $(LDFLAGS) -o $@ $<

           .sh:
               cp $< $@
               chmod a+x $@

           .c~:
               $(GET) $(GFLAGS) -p $< > $*.c
               $(CC) $(CFLAGS) $(LDFLAGS) -o $@ $*.c

           .f~:
               $(GET) $(GFLAGS) -p $< > $*.f
               $(FC) $(FFLAGS) $(LDFLAGS) -o $@ $*.f

           .sh~:
               $(GET) $(GFLAGS) -p $< > $*.sh
               cp $*.sh $@
               chmod a+x $@

           DOUBLE SUFFIX RULES

           .c.o:
               $(CC) $(CFLAGS) -c $<

           .f.o:
               $(FC) $(FFLAGS) -c $<

           .y.o:
               $(YACC) $(YFLAGS) $<
               $(CC) $(CFLAGS) -c y.tab.c
               rm -f y.tab.c
               mv y.tab.o $@

           .l.o:
               $(LEX) $(LFLAGS) $<
               $(CC) $(CFLAGS) -c lex.yy.c
               rm -f lex.yy.c
               mv lex.yy.o $@

           .y.c:
               $(YACC) $(YFLAGS) $<
               mv y.tab.c $@

           .l.c:
               $(LEX) $(LFLAGS) $<
               mv lex.yy.c $@

           .c~.o:
               $(GET) $(GFLAGS) -p $< > $*.c
               $(CC) $(CFLAGS) -c $*.c

           .f~.o:
               $(GET) $(GFLAGS) -p $< > $*.f
               $(FC) $(FFLAGS) -c $*.f

           .y~.o:
               $(GET) $(GFLAGS) -p $< > $*.y
               $(YACC) $(YFLAGS) $*.y
               $(CC) $(CFLAGS) -c y.tab.c
               rm -f y.tab.c
               mv y.tab.o $@

           .l~.o:
               $(GET) $(GFLAGS) -p $< > $*.l
               $(LEX) $(LFLAGS) $*.l
               $(CC) $(CFLAGS) -c lex.yy.c
               rm -f lex.yy.c
               mv lex.yy.o $@

           .y~.c:
               $(GET) $(GFLAGS) -p $< > $*.y
               $(YACC) $(YFLAGS) $*.y
               mv y.tab.c $@

           .l~.c:
               $(GET) $(GFLAGS) -p $< > $*.l
               $(LEX) $(LFLAGS) $*.l
               mv lex.yy.c $@

           .c.a:
               $(CC) -c $(CFLAGS) $<
               $(AR) $(ARFLAGS) $@ $*.o
               rm -f $*.o

           .f.a:
               $(FC) -c $(FFLAGS) $<
               $(AR) $(ARFLAGS) $@ $*.o
               rm -f $*.o

EXIT STATUS
       When the -q option is specified, the make utility shall exit with one of the following values:

        0    Successful completion.

        1    The target was not up-to-date.

       >1    An error occurred.

       When the -q option is not specified, the make utility shall exit with one of the following values:

        0    Successful completion.

       >0    An error occurred.

CONSEQUENCES OF ERRORS
       Default.

       The following sections are informative.

APPLICATION USAGE
       If there is a source file (such as ./source.c) and there are two SCCS files corresponding to it (./s.source.c and ./SCCS/s.source.c), on XSI-conformant systems make uses the SCCS file in the cur‐
       rent directory. However, users are advised to use the underlying SCCS utilities (admin, delta, get, and so on) or the sccs utility for all source files in a given directory.  If  both  forms  are
       used for a given source file, future developers are very likely to be confused.

       It is incumbent upon portable makefiles to specify the .POSIX special target in order to guarantee that they are not affected by local extensions.

       The  -k  and  -S options are both present so that the relationship between the command line, the MAKEFLAGS variable, and the makefile can be controlled precisely. If the k flag is passed in MAKE‐
       FLAGS and a command is of the form:

           $(MAKE) -S foo

       then the default behavior is restored for the child make.

       When the -n option is specified, it is always added to MAKEFLAGS.  This allows a recursive make -n target to be used to see all of the action that would be taken to update target.

       Because of widespread historical practice, interpreting a <number-sign> ('#') inside a variable as the start of a comment has the unfortunate side-effect of making it impossible to place a  <num‐
       ber-sign> in a variable, thus forbidding something like:

           CFLAGS = "-D COMMENT_CHAR='#'"

       Many historical make utilities stop chaining together inference rules when an intermediate target is nonexistent. For example, it might be possible for a make to determine that both .y.c and .c.o
       could be used to convert a .y to a .o.  Instead, in this case, make requires the use of a .y.o rule.

       The best way to provide portable makefiles is to include all of the rules needed in the makefile itself. The rules  provided  use  only  features  provided  by  other  parts  of  this  volume  of
       POSIX.1‐2017.  The  default rules include rules for optional commands in this volume of POSIX.1‐2017. Only rules pertaining to commands that are provided are needed in an implementation's default
       set.

       Macros used within other macros are evaluated when the new macro is used rather than when the new macro is defined. Therefore:

           MACRO = value1
           NEW   = $(MACRO)
           MACRO = value2

           target:
               echo $(NEW)

       would produce value2 and not value1 since NEW was not expanded until it was needed in the echo command line.

       Some historical applications have been known to intermix target_name and macro=name operands on the command line, expecting that all of the macros are processed before  any  of  the  targets  are
       dealt with. Conforming applications do not do this, although some backwards-compatibility support may be included in some implementations.

       The  following  characters  in  filenames may give trouble: '=', ':', '`', single-quote, and '@'.  In include filenames, pattern matching characters and '"' should also be avoided, as they may be
       treated as special by some implementations.

       For inference rules, the description of $< and $? seem similar. However, an example shows the minor difference. In a makefile containing:

           foo.o: foo.h

       if foo.h is newer than foo.o, yet foo.c is older than foo.o, the built-in rule to make foo.o from foo.c is used, with $< equal to foo.c and $? equal to foo.h.  If foo.c is also newer than  foo.o,
       $< is equal to foo.c and $? is equal to foo.h foo.c.

       As  a  consequence of the general rules for target updating, a useful special case is that if a target has no prerequisites and no commands, and the target of the rule is a nonexistent file, then
       make acts as if this target has been updated whenever its rule is run.

       Note:     This implies that all targets depending on this one will always have their commands run.

       Shell command sequences like make; cp original copy; make may have problems on filesystems where the timestamp resolution is the minimum (1 second) required by the standard and where make consid‐
       ers  identical  timestamps to be up-to-date. Conversely, rules like copy: original; cp -p original copy will result in redundant work on make implementations that consider identical timestamps to
       be out-of-date.

       This standard does not specify precedence between macro definition and include directives. Thus, the behavior of:

           include =foo.mk

       is unspecified. To define a variable named include, either the white space before the <equal-sign> should be removed, or another macro should be used, as in:

           INCLUDE_NAME = include
           $(INCLUDE_NAME) =foo.mk

       On the other hand, if the intent is to include a file which starts with an <equal-sign>, either the filename should be changed to ./=foo.mk, or the makefile should be written as:

           INCLUDE_FILE = =foo.mk
           include $(INCLUDE_FILE)

EXAMPLES
        1. The following command:

               make

           makes the first target found in the makefile.

        2. The following command:

               make junk

           makes the target junk.

        3. The following makefile says that pgm depends on two files, a.o and b.o, and that they in turn depend on their corresponding source files (a.c and b.c), and a common file incl.h:

               .POSIX:
               pgm: a.o b.o
                   c99 a.o b.o -o pgm
               a.o: incl.h a.c
                   c99 -c a.c
               b.o: incl.h b.c
                   c99 -c b.c

        4. An example for making optimized .o files from .c files is:

               .c.o:
                   c99 -c -O 1 $*.c

           or:

               .c.o:
                   c99 -c -O 1 $<

        5. The most common use of the archive interface follows. Here, it is assumed that the source files are all C-language source:

               lib: lib(file1.o) lib(file2.o) lib(file3.o)
                   @echo lib is now up-to-date

           The .c.a rule is used to make file1.o, file2.o, and file3.o and insert them into lib.

           The treatment of escaped <newline> characters throughout the makefile is historical practice. For example, the inference rule:

               .c.o\
               :

           works, and the macro:

               f=  bar baz\
                   biz
               a:
                   echo ==$f==

           echoes "==bar baz biz==".

           If $? were:

               /usr/include/stdio.h /usr/include/unistd.h foo.h

           then $(?D) would be:

               /usr/include /usr/include .

           and $(?F) would be:

               stdio.h unistd.h foo.h

        6. The contents of the built-in rules can be viewed by running:

               make -p -f /dev/null 2>/dev/null

RATIONALE
       The make utility described in this volume of POSIX.1‐2017 is intended to provide the means for changing portable source code into executables that can be run on an POSIX.1‐2008-conforming system.
       It reflects the most common features present in System V and BSD makes.

       Historically, the make utility has been an especially fertile ground for vendor and research organization-specific syntax modifications and extensions. Examples include:

        *  Syntax supporting parallel execution (such as from various multi-processor vendors, GNU, and others)

        *  Additional ``operators'' separating targets and their prerequisites (System V, BSD, and others)

        *  Specifying that command lines containing the strings "${MAKE}" and "$(MAKE)" are executed when the -n option is specified (GNU and System V)

        *  Modifications of the meaning of internal macros when referencing libraries (BSD and others)

        *  Using a single instance of the shell for all of the command lines of the target (BSD and others)

        *  Allowing <space> characters as well as <tab> characters to delimit command lines (BSD)

        *  Adding C preprocessor-style ``include'' and ``ifdef'' constructs (System V, GNU, BSD, and others)

        *  Remote execution of command lines (Sprite and others)

        *  Specifying additional special targets (BSD, System V, and most others)

        *  Specifying an alternate shell to use to process commands.

       Additionally, many vendors and research organizations have rethought the basic concepts of make, creating vastly extended, as well as completely new, syntaxes. Each of these versions of make ful‐
       fills the needs of a different community of users; it is unreasonable for this volume of POSIX.1‐2017 to require behavior that would be incompatible (and probably inferior) to historical practice
       for such a community.

       In similar circumstances, when the industry has enough sufficiently incompatible formats as to make them irreconcilable, this volume of POSIX.1‐2017 has followed one or both of two courses of ac‐
       tion. Commands have been renamed (cksum, echo, and pax) and/or command line options have been provided to select the desired behavior (grep, od, and pax).

       Because the syntax specified for the make utility is, by and large, a subset of the syntaxes accepted by almost all versions of make, it was decided that it would be counter-productive to  change
       the  name.   And  since the makefile itself is a basic unit of portability, it would not be completely effective to reserve a new option letter, such as make -P, to achieve the portable behavior.
       Therefore, the special target .POSIX was added to the makefile, allowing users to specify ``standard'' behavior. This special target does not preclude extensions in the make utility, nor does  it
       preclude  such  extensions being used by the makefile specifying the target; it does, however, preclude any extensions from being applied that could alter the behavior of previously valid syntax;
       such extensions must be controlled via command line options or new special targets. It is incumbent upon portable makefiles to specify the .POSIX special target in order to  guarantee  that  they
       are not affected by local extensions.

       The  portable version of make described in this reference page is not intended to be the state-of-the-art software generation tool and, as such, some newer and more leading-edge features have not
       been included. An attempt has been made to describe the portable makefile in a manner that does not preclude such extensions as long as they do not disturb the portable behavior described here.

       When the -n option is specified, it is always added to MAKEFLAGS.  This allows a recursive make -n target to be used to see all of the action that would be taken to update target.

       The definition of MAKEFLAGS allows both the System V letter string and the BSD command line formats. The two formats are sufficiently different to allow implementations to  support  both  without
       ambiguity.

       Early proposals stated that an ``unquoted'' <number-sign> was treated as the start of a comment. The make utility does not pay any attention to quotes. A <number-sign> starts a comment regardless
       of its surroundings.

       The text about ``other implementation-defined pathnames may also be tried'' in addition to ./makefile and ./Makefile is to allow such extensions as SCCS/s.Makefile and other  variations.  It  was
       made  an implementation-defined requirement (as opposed to unspecified behavior) to highlight surprising implementations that might select something unexpected like /etc/Makefile.  XSI-conformant
       systems also try ./s.makefile, SCCS/s.makefile, ./s.Makefile, and SCCS/s.Makefile.

       Early proposals contained the macro NPROC as a means of specifying that make should use n processes to do the work required. While this feature is a valuable extension for many systems, it is not
       common usage and could require other non-trivial extensions to makefile syntax. This extension is not required by this volume of POSIX.1‐2017, but could be provided as a compatible extension. The
       macro PARALLEL is used by some historical systems with essentially the same meaning (but without using a name that is a common system limit value). It is suggested that implementors recognize the
       existing use of NPROC and/or PARALLEL as extensions to make.

       The default rules are based on System V. The default CC= value is c99 instead of cc because this volume of POSIX.1‐2017 does not standardize the utility named cc.  Thus, every conforming applica‐
       tion would be required to define CC=c99 to expect to run. There is no advantage conferred by the hope that the makefile might hit the ``preferred'' compiler because this cannot be  guaranteed  to
       work. Also, since the portable makescript can only use the c99 options, no advantage is conferred in terms of what the script can do.  It is a quality-of-implementation issue as to whether c99 is
       as valuable as cc.

       The -d option to make is frequently used to produce debugging information, but is too implementation-defined to add to this volume of POSIX.1‐2017.

       The -p option is not passed in MAKEFLAGS on most historical implementations and to change this would cause many implementations to break without sufficiently increased portability.

       Commands that begin with a <plus-sign> ('+') are executed even if the -n option is present. Based on the GNU version of make, the behavior of -n when the <plus-sign>  prefix  is  encountered  has
       been  extended  to  apply to -q and -t as well. However, the System V convention of forcing command execution with -n when the command line of a target contains either of the strings "$(MAKE)" or
       "${MAKE}" has not been adopted. This functionality appeared in early proposals, but the danger of this approach was pointed out with the following example of a portion of a makefile:

           subdir:
               cd subdir; rm all_the_files; $(MAKE)

       The loss of the System V behavior in this case is well-balanced by the safety afforded to other makefiles that were not aware of this situation. In any event, the command line <plus-sign>  prefix
       can provide the desired functionality.

       The  double <colon> in the target rule format is supported in BSD systems to allow more than one target line containing the same target name to have commands associated with it. Since this is not
       functionality described in the SVID or XPG3 it has been allowed as an extension, but not mandated.

       The default rules are provided with text specifying that the built-in rules shall be the same as if the listed set were used. The intent is that implementations should be able to  use  the  rules
       without change, but will be allowed to alter them in ways that do not affect the primary behavior.

       One point of discussion was whether to drop the default rules list from this volume of POSIX.1‐2017. They provide convenience, but do not enhance portability of applications. The prime benefit is
       in portability of users who wish to type make command and have the command build from a command.c file.

       The historical MAKESHELL feature, and related features provided by other make implementations, were omitted. In some implementations it is used to let a user override the shell to be used to  run
       make  commands.  This was confusing; for a portable make, the shell should be chosen by the makefile writer. Further, a makefile writer cannot require an alternate shell to be used and still con‐
       sider the makefile portable. While it would be possible to standardize a mechanism for specifying an alternate shell, existing implementations do not agree on such a mechanism, and makefile writ‐
       ers can already invoke an alternate shell by specifying the shell name in the rule for a target; for example:

           python -c "foo"

       The  make  utilities in most historical implementations process the prerequisites of a target in left-to-right order, and the makefile format requires this. It supports the standard idiom used in
       many makefiles that produce yacc programs; for example:

           foo: y.tab.o lex.o main.o
               $(CC) $(CFLAGS) -o $@ t.tab.o lex.o main.o

       In this example, if make chose any arbitrary order, the lex.o might not be made with the correct y.tab.h.  Although there may be better ways to express this relationship, it is widely  used  his‐
       torically. Implementations that desire to update prerequisites in parallel should require an explicit extension to make or the makefile format to accomplish it, as described previously.

       The  algorithm for determining a new entry for target rules is partially unspecified. Some historical makes allow comment lines (including blank and empty lines) within the collection of commands
       marked by leading <tab> characters. A conforming makefile must ensure that each command starts with a <tab>, but implementations are free to ignore comments without triggering the start of a  new
       entry.

       The  ASYNCHRONOUS EVENTS section includes having SIGTERM and SIGHUP, along with the more traditional SIGINT and SIGQUIT, remove the current target unless directed not to do so. SIGTERM and SIGHUP
       were added to parallel other utilities that have historically cleaned up their work as a result of these signals. When make receives any signal other than SIGQUIT, it is required to resend itself
       the  signal  it  received  so  that  it exits with a status that reflects the signal. The results from SIGQUIT are partially unspecified because, on systems that create core files upon receipt of
       SIGQUIT, the core from make would conflict with a core file from the command that was running when the SIGQUIT arrived. The main concern was to prevent damaged  files  from  appearing  up-to-date
       when make is rerun.

       The  .PRECIOUS  special  target  was extended to affect all targets globally (by specifying no prerequisites). The .IGNORE and .SILENT special targets were extended to allow prerequisites; it was
       judged to be more useful in some cases to be able to turn off errors or echoing for a list of targets than for the entire makefile. These extensions to make in System V were made to match histor‐
       ical practice from the BSD make.

       Macros  are  not exported to the environment of commands to be run. This was never the case in any historical make and would have serious consequences. The environment is the same as the environ‐
       ment to make except that MAKEFLAGS and macros defined on the make command line are added, and except that macros defined by the MAKEFLAGS environment variable and  macros  defined  in  the  make‐
       file(s) may update the value of an existing environment variable (other than SHELL).

       Some  implementations  do not use system() for all command lines, as required by the portable makefile format; as a performance enhancement, they select lines without shell metacharacters for di‐
       rect execution by execve().  There is no requirement that system() be used specifically, but merely that the same results be achieved.  The metacharacters typically used to bypass the direct  ex‐
       ecve() execution have been any of:

           =  |  ^  (  )  ;  &  <  >  *  ?  [  ]  :  $  `  '  "  \  \n

       The  default  in some advanced versions of make is to group all the command lines for a target and execute them using a single shell invocation; the System V method is to pass each line individu‐
       ally to a separate shell. The single-shell method has the advantages in performance and the lack of a requirement for many continued lines. However, converting to this  newer  method  has  caused
       portability  problems with many historical makefiles, so the behavior with the POSIX makefile is specified to be the same as that of System V. It is suggested that the special target .ONESHELL be
       used as an implementation extension to achieve the single-shell grouping for a target or group of targets.

       Novice users of make have had difficulty with the historical need to start commands with a <tab>.  Since it is often difficult to discern differences between <tab> and <space> characters on  ter‐
       minals  or printed listings, confusing bugs can arise. In early proposals, an attempt was made to correct this problem by allowing leading <blank> characters instead of <tab> characters. However,
       implementors reported many makefiles that failed in subtle ways following this change, and it is difficult to implement a make that unambiguously  can  differentiate  between  macro  and  command
       lines.   There  is  extensive historical practice of allowing leading <space> characters before macro definitions. Forcing macro lines into column 1 would be a significant backwards-compatibility
       problem for some makefiles.  Therefore, historical practice was restored.

       There is substantial variation in the handling of include lines by different implementations. However, there is enough commonality for the standard to be able to specify a minimum set of require‐
       ments that allow the feature to be used portably. Known variations have been explicitly called out as unspecified behavior in the description.

       The System V dynamic dependency feature was not included. It would support:

           cat: $$@.c

       that would expand to;

           cat: cat.c

       This  feature exists only in the new version of System V make and, while useful, is not in wide usage. This means that macros are expanded twice for prerequisites: once at makefile parse time and
       once at target update time.

       Consideration was given to adding metarules to the POSIX make.  This would make %.o: %.c the same as .c.o:.  This is quite useful and available from some vendors, but  it  would  cause  too  many
       changes  to this make to support. It would have introduced rule chaining and new substitution rules. However, the rules for target names have been set to reserve the '%' and '"' characters. These
       are traditionally used to implement metarules and quoting of target names, respectively. Implementors are strongly encouraged to use these characters only for these purposes.

       A request was made to extend the suffix delimiter character from a <period> to any character. The metarules feature in newer makes solves this problem in  a  more  general  way.  This  volume  of
       POSIX.1‐2017 is staying with the more conservative historical definition.

       The  standard output format for the -p option is not described because it is primarily a debugging option and because the format is not generally useful to programs. In historical implementations
       the output is not suitable for use in generating makefiles. The -p format has been variable across historical implementations. Therefore, the definition of -p was only to provide  a  consistently
       named option for obtaining make script debugging information.

       Some historical implementations have not cleared the suffix list with -r.

       Implementations  should  be aware that some historical applications have intermixed target_name and macro=value operands on the command line, expecting that all of the macros are processed before
       any of the targets are dealt with. Conforming applications do not do this, but some backwards-compatibility support may be warranted.

       Empty inference rules are specified with a <semicolon> command rather than omitting all commands, as described in an early proposal. The latter case has no traditional meaning and is reserved for
       implementation extensions, such as in GNU make.

       Earlier  versions of this standard defined comment lines only as lines with '#' as the first character. Many places then talked about comments, blank lines, and empty lines; but some places inad‐
       vertently only mentioned comments when blank lines and empty lines had also been accepted in all known implementations. The standard now defines comment lines to be blank lines, empty lines,  and
       lines starting with a '#' character and explictily lists cases where blank lines and empty lines are not acceptable.

       On  most  historic systems, the make utility considered a target with a prerequisite that had an identical timestamp as up-to-date. The HP-UX implementation of make treated it as out-of-date. The
       standard now allows either behavior, but implementations are encouraged to follow the example set by HP-UX.  This is especially important on file systems where the  timestamp  resolution  is  the
       minimum (1 second) required by the standard. All implementations of make should make full use of the finest timestamp resolution available on the file systems holding targets and prerequisites to
       ensure that targets are up-to-date even for prerequisite files with timestamps that were updated within the same second. However, if the timestamp resolutions of the  file  systems  containing  a
       target and a prerequisite are different, the timestamp with the more precise resolution should be rounded down to the resolution of the less precise timestamp for the comparison.

FUTURE DIRECTIONS
       Some implementations of make include an export directive to add specified make variables to the environment. This may be considered for standardization in a future version.

       A future version of this standard may require that macro expansions using the forms $(string1:[op]%[os]=[np][%][ns]) or ${string1:[op]%[os]=[np][%][ns]} are treated as pattern macro expansions.

SEE ALSO
       Chapter 2, Shell Command Language, ar, c99, get, lex, sccs, sh, yacc

       The Base Definitions volume of POSIX.1‐2017, Section 6.1, Portable Character Set, Chapter 8, Environment Variables, Section 12.2, Utility Syntax Guidelines

       The System Interfaces volume of POSIX.1‐2017, exec, system()

COPYRIGHT
       Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group
       Base Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.  In the event of any discrepancy between this  ver‐
       sion  and  the  original  IEEE and The Open Group Standard, the original IEEE and The Open Group Standard is the referee document. The original Standard can be obtained online at http://www.open‐
       group.org/unix/online.html .

       Any typographical or formatting errors that appear in this page are most likely to have been introduced during the conversion of the source files to man page format. To report  such  errors,  see
       https://www.kernel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                                                                                2017                                                                                           MAKE(1P)
