ACK(1)                                                                              User Contributed Perl Documentation                                                                             ACK(1)

NAME
       ack - grep-like text finder

SYNOPSIS
           ack [options] PATTERN [FILE...]
           ack -f [options] [DIRECTORY...]

DESCRIPTION
       ack is designed as an alternative to grep for programmers.

       ack searches the named input FILEs or DIRECTORYs for lines containing a match to the given PATTERN.  By default, ack prints the matching lines.  If no FILE or DIRECTORY is given, the current
       directory will be searched.

       PATTERN is a Perl regular expression.  Perl regular expressions are commonly found in other programming languages, but for the particulars of their behavior, please consult perlreref
       <https://perldoc.perl.org/perlreref.html>.  If you don't know how to use regular expression but are interested in learning, you may consult perlretut <https://perldoc.perl.org/perlretut.html>.
       If you do not need or want ack to use regular expressions, please see the "-Q"/"--literal" option.

       Ack can also list files that would be searched, without actually searching them, to let you take advantage of ack's file-type filtering capabilities.

FILE SELECTION
       If files are not specified for searching, either on the command line or piped in with the "-x" option, ack delves into subdirectories selecting files for searching.

       ack is intelligent about the files it searches.  It knows about certain file types, based on both the extension on the file and, in some cases, the contents of the file.  These selections can be
       made with the --type option.

       With no file selection, ack searches through regular files that are not explicitly excluded by --ignore-dir and --ignore-file options, either present in ackrc files or on the command line.

       The default options for ack ignore certain files and directories.  These include:

       •   Backup files: Files matching #*# or ending with ~.

       •   Coredumps: Files matching core.\d+

       •   Version control directories like .svn and .git.

       Run ack with the "--dump" option to see what settings are set.

       However, ack always searches the files given on the command line, no matter what type.  If you tell ack to search in a coredump, it will search in a coredump.

DIRECTORY SELECTION
       ack descends through the directory tree of the starting directories specified.  If no directories are specified, the current working directory is used.  However, it will ignore the shadow
       directories used by many version control systems, and the build directories used by the Perl MakeMaker system.  You may add or remove a directory from this list with the --[no]ignore-dir option.
       The option may be repeated to add/remove multiple directories from the ignore list.

       For a complete list of directories that do not get searched, run "ack --dump".

MATCHING IN A RANGE OF LINES
       The "--range-start" and "--range-end" options let you specify ranges of lines to search within each file.

       Say you had the following file, called testfile:

           # This function calls print on "foo".
           sub foo {
               print 'foo';
           }
           my $print = 1;
           sub bar {
               print 'bar';
           }
           my $task = 'print';

       Calling "ack print" will give us five matches:

           $ ack print testfile
           # This function calls print on "foo".
               print 'foo';
           my $print = 1;
               print 'bar';
           my $task = 'print';

       What if we only want to search for "print" within the subroutines?  We can specify ranges of lines that we want ack to search.  The range starts with any line that matches the pattern "^sub \w+",
       and stops with any line that matches "^}".

           $ ack --range-start='^sub \w+' --range-end='^}' print testfile
               print 'foo';
               print 'bar';

       Note that ack searched two ranges of lines.  The listing below shows which lines were in a range and which were out of the range.

           Out # This function calls print on "foo".
           In  sub foo {
           In      print 'foo';
           In  }
           Out my $print = 1;
           In  sub bar {
           In      print 'bar';
           In  }
           Out my $task = 'print';

       You don't have to specify both "--range-start" and "--range-end".  IF "--range-start" is omitted, then the range runs from the first line in the file unitl the first line that matches
       "--range-end".  Similarly, if "--range-end" is omitted, the range runs from the first line matching "--range-start" to the end of the file.

       For example, if you wanted to search all HTML files up until the first instance of the "<body>", you could do

           ack foo --html --range-end='<body>'

       Or to search after Perl's `__DATA__` or `__END__` markers, you would do

           ack pattern --perl --range-start='^__(END|DATA)__'

       It's possible for a range to start and stop on the same line.  For example

           --range-start='<title>' --range-end='</title>'

       would match this line as both the start and end of the range, making a one-line range.

           <title>Page title</title>

       Note that the patterns in "--range-start" and "--range-end" are not affected by options like "-i", "-w" and "-Q" that modify the behavior of the main pattern being matched.

       Again, ranges only affect where matches are looked for.  Everything else in ack works the same way.  Using "-c" option with a range will give a count of all the matches that appear within those
       ranges.  The "-l" shows those files that have a match within a range, and the "-L" option shows files that do not have a match within a range.

       The "-v" option for negating a match works inside the range, too.  To see lines that don't match "google" within the "<head>" section of your HTML files, you could do:

           ack google -v --html --range-start='<head' --range-end='</head>'

       Specifying a range to search does not affect how matches are displayed.  The context for a match will still be the same, and

       Using the context options work the same way, and will show context lines for matches even if the context lines fall outside the range.  Similarly, "--passthru" will show all lines in the file,
       but only show matches for lines within the range.

OPTIONS
       --ackrc
           Specifies an ackrc file to load after all others; see "ACKRC LOCATION SEMANTICS".

       -A NUM, --after-context=NUM
           Print NUM lines of trailing context after matching lines.

       -B NUM, --before-context=NUM
           Print NUM lines of leading context before matching lines.

       --[no]break
           Print a break between results from different files. On by default when used interactively.

       -C [NUM], --context[=NUM]
           Print NUM lines (default 2) of context around matching lines.  You can specify zero lines of context to override another context specified in an ackrc.

       -c, --count
           Suppress normal output; instead print a count of matching lines for each input file.  If -l is in effect, it will only show the number of lines for each file that has lines matching.  Without
           -l, some line counts may be zeroes.

           If combined with -h (--no-filename) ack outputs only one total count.

       --[no]color, --[no]colour
           --color highlights the matching text.  --nocolor suppresses the color.  This is on by default unless the output is redirected.

           On Windows, this option is off by default unless the Win32::Console::ANSI module is installed or the "ACK_PAGER_COLOR" environment variable is used.

       --color-filename=color
           Sets the color to be used for filenames.

       --color-match=color
           Sets the color to be used for matches.

       --color-colno=color
           Sets the color to be used for column numbers.

       --color-lineno=color
           Sets the color to be used for line numbers.

       --[no]column
           Show the column number of the first match.  This is helpful for editors that can place your cursor at a given position.

       --create-ackrc
           Dumps the default ack options to standard output.  This is useful for when you want to customize the defaults.

       --dump
           Writes the list of options loaded and where they came from to standard output.  Handy for debugging.

       --[no]env
           --noenv disables all environment processing. No .ackrc is read and all environment variables are ignored. By default, ack considers .ackrc and settings in the environment.

       --flush
           --flush flushes output immediately.  This is off by default unless ack is running interactively (when output goes to a pipe or file).

       -f  Only print the files that would be searched, without actually doing any searching.  PATTERN must not be specified, or it will be taken as a path to search.

       --files-from=FILE
           The list of files to be searched is specified in FILE.  The list of files are separated by newlines.  If FILE is "-", the list is loaded from standard input.

           Note that the list of files is not filtered in any way.  If you add "--type=html" in addition to "--files-from", the "--type" will be ignored.

       --[no]filter
           Forces ack to act as if it were receiving input via a pipe.

       --[no]follow
           Follow or don't follow symlinks, other than whatever starting files or directories were specified on the command line.

           This is off by default.

       -g PATTERN
           Print searchable files where the relative path + filename matches PATTERN.

           Note that

               ack -g foo

           is exactly the same as

               ack -f | ack foo

           This means that just as ack will not search, for example, .jpg files, "-g" will not list .jpg files either.  ack is not intended to be a general-purpose file finder.

           Note also that if you have "-i" in your .ackrc that the filenames to be matched will be case-insensitive as well.

           This option can be combined with --color to make it easier to spot the match.

       --[no]group
           --group groups matches by file name.  This is the default when used interactively.

           --nogroup prints one result per line, like grep.  This is the default when output is redirected.

       -H, --with-filename
           Print the filename for each match. This is the default unless searching a single explicitly specified file.

       -h, --no-filename
           Suppress the prefixing of filenames on output when multiple files are searched.

       --[no]heading
           Print a filename heading above each file's results.  This is the default when used interactively.

       --help
           Print a short help statement.

       --help-types
           Print all known types.

       --help-colors
           Print a chart of various color combinations.

       --help-rgb-colors
           Like --help-colors but with more precise RGB colors.

       -i, --ignore-case
           Ignore case distinctions in PATTERN.  Overrides --smart-case and -I.

       -I, --no-ignore-case
           Turns on case distinctions in PATTERN.  Overrides --smart-case and -i.

       --ignore-ack-defaults
           Tells ack to completely ignore the default definitions provided with ack.  This is useful in combination with --create-ackrc if you really want to customize ack.

       --[no]ignore-dir=DIRNAME, --[no]ignore-directory=DIRNAME
           Ignore directory (as CVS, .svn, etc are ignored). May be used multiple times to ignore multiple directories. For example, mason users may wish to include --ignore-dir=data. The --noignore-dir
           option allows users to search directories which would normally be ignored (perhaps to research the contents of .svn/props directories).

           The DIRNAME must always be a simple directory name. Nested directories like foo/bar are NOT supported. You would need to specify --ignore-dir=foo and then no files from any foo directory are
           taken into account by ack unless given explicitly on the command line.

       --ignore-file=FILTER:ARGS
           Ignore files matching FILTER:ARGS.  The filters are specified identically to file type filters as seen in "Defining your own types".

       -k, --known-types
           Limit selected files to those with types that ack knows about.

       -l, --files-with-matches
           Only print the filenames of matching files, instead of the matching text.

       -L, --files-without-matches
           Only print the filenames of files that do NOT match.

       --match PATTERN
           Specify the PATTERN explicitly. This is helpful if you don't want to put the regex as your first argument, e.g. when executing multiple searches over the same set of files.

               # search for foo and bar in given files
               ack file1 t/file* --match foo
               ack file1 t/file* --match bar

       -m=NUM, --max-count=NUM
           Print only NUM matches out of each file.  If you want to stop ack after printing the first match of any kind, use the -1 options.

       --man
           Print this manual page.

       -n, --no-recurse
           No descending into subdirectories.

       -o  Show only the part of each line matching PATTERN (turns off text highlighting).  This is exactly the same as "--output=$&".

       --output=expr
           Output the evaluation of expr for each line (turns off text highlighting). If PATTERN matches more than once then a line is output for each non-overlapping match.

           expr may contain the strings "\n", "\r" and "\t", which will be expanded to their corresponding characters line feed, carriage return and tab, respectively.

           expr may also contain the following Perl special variables:

           $1 through $9
               The subpattern from the corresponding set of capturing parentheses.  If your pattern is "(.+) and (.+)", and the string is "this and that', then $1 is "this" and $2 is "that".

           $_  The contents of the line in the file.

           $.  The number of the line in the file.

           $&, "$`" and "$'"
               $& is the the string matched by the pattern, "$`" is what precedes the match, and "$'" is what follows it.  If the pattern is "gra(ph|nd)" and the string is "lexicographic", then $& is
               "graph", "$`" is "lexico" and "$'" is "ic".

               Use of these variables in your output will slow down the pattern matching.

           $+  The match made by the last parentheses that matched in the pattern.  For example, if your pattern is "Version: (.+)|Revision: (.+)", then $+ will contain whichever set of parentheses
               matched.

           $f  $f is available, in "--output" only, to insert the filename.  This is a stand-in for the discovered $filename usage in old "ack2 --output", which is disallowed with "ack3" improved
               security.

               The intended usage is to provide the grep or compile-error syntax needed for editor/IDE go-to-line integration, e.g. "--output=$f:$.:$_" or "--output=$f\t$.\t$&"

       --pager=program, --nopager
           --pager directs ack's output through program.  This can also be specified via the "ACK_PAGER" and "ACK_PAGER_COLOR" environment variables.

           Using --pager does not suppress grouping and coloring like piping output on the command-line does.

           --nopager cancels any setting in ~/.ackrc, "ACK_PAGER" or "ACK_PAGER_COLOR".  No output will be sent through a pager.

       --passthru
           Prints all lines, whether or not they match the expression.  Highlighting will still work, though, so it can be used to highlight matches while still seeing the entire file, as in:

               # Watch a log file, and highlight a certain IP address.
               $ tail -f ~/access.log | ack --passthru 123.45.67.89

       --print0
           Only works in conjunction with -f, -g, -l or -c, options that only list filenames.  The filenames are output separated with a null byte instead of the usual newline. This is helpful when
           dealing with filenames that contain whitespace, e.g.

               # Remove all files of type HTML.
               ack -f --html --print0 | xargs -0 rm -f

       -p[N], --proximate[=N]
           Groups together match lines that are within N lines of each other.  This is useful for visually picking out matches that appear close to other matches.

           For example, if you got these results without the "--proximate" option,

               15: First match
               18: Second match
               19: Third match
               37: Fourth match

           they would look like this with "--proximate=1"

               15: First match

               18: Second match
               19: Third match

               37: Fourth match

           and this with "--proximate=3".

               15: First match
               18: Second match
               19: Third match

               37: Fourth match

           If N is omitted, N is set to 1.

       -P  Negates the effect of the --proximate option.  Shortcut for --proximate=0.

       -Q, --literal
           Quote all metacharacters in PATTERN, it is treated as a literal.

       -r, -R, --recurse
           Recurse into sub-directories. This is the default and just here for compatibility with grep. You can also use it for turning --no-recurse off.

       --range-start=PATTERN, --range-end=PATTERN
           Specifies patterns that mark the start and end of a range.  See "MATCHING IN A RANGE OF LINES" for details.

       -s  Suppress error messages about nonexistent or unreadable files.  This is taken from fgrep.

       -S, --[no]smart-case, --no-smart-case
           Ignore case in the search strings if PATTERN contains no uppercase characters. This is similar to "smartcase" in the vim text editor.  The options overrides -i and -I.

           -S is a synonym for --smart-case.

           -i always overrides this option.

       --sort-files
           Sorts the found files lexicographically.  Use this if you want your file listings to be deterministic between runs of ack.

       --show-types
           Outputs the filetypes that ack associates with each file.

           Works with -f and -g options.

       -t TYPE, --type=TYPE, --TYPE
           Specify the types of files to include in the search.  TYPE is a filetype, like perl or xml.  --type=perl can also be specified as --perl, although this is deprecated.

           Type inclusions can be repeated and are ORed together.

           See ack --help-types for a list of valid types.

       -T TYPE, --type=noTYPE, --noTYPE
           Specifies the type of files to exclude from the search.  --type=noperl can be done as --noperl, although this is deprecated.

           If a file is of both type "foo" and "bar", specifying both --type=foo and --type=nobar will exclude the file, because an exclusion takes precedence over an inclusion.

       --type-add TYPE:FILTER:ARGS
           Files with the given ARGS applied to the given FILTER are recognized as being of (the existing) type TYPE.  See also "Defining your own types".

       --type-set TYPE:FILTER:ARGS
           Files with the given ARGS applied to the given FILTER are recognized as being of type TYPE. This replaces an existing definition for type TYPE.  See also "Defining your own types".

       --type-del TYPE
           The filters associated with TYPE are removed from Ack, and are no longer considered for searches.

       --[no]underline
           Turns on underlining of matches, where "underlining" is printing a line of carets under the match.

               $ ack -u foo
               peanuts.txt
               17: Come kick the football you fool
                                 ^^^          ^^^
               623: Price per square foot
                                     ^^^

           This is useful if you're dumping the results of an ack run into a text file or printer that doesn't support ANSI color codes.

           The setting of underline does not affect highlighting of matches.

       -v, --invert-match
           Invert match: select non-matching lines.

       --version
           Display version and copyright information.

       -w, --word-regexp
           Force PATTERN to match only whole words.

       -x  An abbreviation for --files-from=-. The list of files to search are read from standard input, with one line per file.

           Note that the list of files is not filtered in any way.  If you add "--type=html" in addition to "-x", the "--type" will be ignored.

       -1  Stops after reporting first match of any kind.  This is different from --max-count=1 or -m1, where only one match per file is shown.  Also, -1 works with -f and -g, where -m does not.

       --thpppt
           Display the all-important Bill The Cat logo.  Note that the exact spelling of --thpppppt is not important.  It's checked against a regular expression.

       --bar
           Check with the admiral for traps.

       --cathy
           Chocolate, Chocolate, Chocolate!

THE .ackrc FILE
       The .ackrc file contains command-line options that are prepended to the command line before processing.  Multiple options may live on multiple lines.  Lines beginning with a # are ignored.  A
       .ackrc might look like this:

           # Always sort the files
           --sort-files

           # Always color, even if piping to another program
           --color

           # Use "less -r" as my pager
           --pager=less -r

       Note that arguments with spaces in them do not need to be quoted, as they are not interpreted by the shell. Basically, each line in the .ackrc file is interpreted as one element of @ARGV.

       ack looks in several locations for .ackrc files; the searching process is detailed in "ACKRC LOCATION SEMANTICS".  These files are not considered if --noenv is specified on the command line.

Defining your own types
       ack allows you to define your own types in addition to the predefined types. This is done with command line options that are best put into an .ackrc file - then you do not have to define your
       types over and over again. In the following examples the options will always be shown on one command line so that they can be easily copy & pasted.

       File types can be specified both with the the --type=xxx option, or the file type as an option itself.  For example, if you create a filetype of "cobol", you can specify --type=cobol or simply
       --cobol.  File types must be at least two characters long.  This is why the C language is --cc and the R language is --rr.

       ack --perl foo searches for foo in all perl files. ack --help-types tells you, that perl files are files ending in .pl, .pm, .pod or .t. So what if you would like to include .xs files as well
       when searching for --perl files? ack --type-add perl:ext:xs --perl foo does this for you. --type-add appends additional extensions to an existing type.

       If you want to define a new type, or completely redefine an existing type, then use --type-set. ack --type-set eiffel:ext:e,eiffel defines the type eiffel to include files with the extensions .e
       or .eiffel. So to search for all eiffel files containing the word Bertrand use ack --type-set eiffel:ext:e,eiffel --eiffel Bertrand.  As usual, you can also write --type=eiffel instead of
       --eiffel. Negation also works, so --noeiffel excludes all eiffel files from a search. Redefining also works: ack --type-set cc:ext:c,h and .xs files no longer belong to the type cc.

       When defining your own types in the .ackrc file you have to use the following:

         --type-set=eiffel:ext:e,eiffel

       or writing on separate lines

         --type-set
         eiffel:ext:e,eiffel

       The following does NOT work in the .ackrc file:

         --type-set eiffel:ext:e,eiffel

       In order to see all currently defined types, use --help-types, e.g.  ack --type-set backup:ext:bak --type-add perl:ext:perl --help-types

       In addition to filtering based on extension, ack offers additional filter types.  The generic syntax is --type-set TYPE:FILTER:ARGS; ARGS depends on the value of FILTER.

       is:FILENAME
           is filters match the target filename exactly.  It takes exactly one argument, which is the name of the file to match.

           Example:

               --type-set make:is:Makefile

       ext:EXTENSION[,EXTENSION2[,...]]
           ext filters match the extension of the target file against a list of extensions.  No leading dot is needed for the extensions.

           Example:

               --type-set perl:ext:pl,pm,t

       match:PATTERN
           match filters match the target filename against a regular expression.  The regular expression is made case-insensitive for the search.

           Example:

               --type-set make:match:/(gnu)?makefile/

       firstlinematch:PATTERN
           firstlinematch matches the first line of the target file against a regular expression.  Like match, the regular expression is made case insensitive.

           Example:

               --type-add perl:firstlinematch:/perl/

ACK COLORS
       ack allows customization of the colors it uses when presenting matches onscreen.  It uses the colors available in Perl's Term::ANSIColor module, which provides the following listed values. Note
       that case does not matter when using these values.

       There are four different colors ack uses:

           Aspect      Option              Env. variable       Default
           --------    -----------------   ------------------  ---------------
           filename    --color-filename    ACK_COLOR_FILENAME  black on_yellow
           match       --color-match       ACK_COLOR_MATCH     bold green
           line no.    --color-lineno      ACK COLOR_LINENO    bold yellow
           column no.  --color-colno       ACK COLOR_COLNO     bold yellow

       The column number column is only used if the column number is shown because of the --column option.

       Colors may be specified by command-line option, such as "ack --color-filename='red on_white'", or by setting an environment variable, such as "ACK_COLOR_FILENAME='red on_white'".  Options for
       colors can be set in your ACKRC file (See "THE .ackrc FILE").

       ack can understand the following colors for the foreground:

           black red green yellow blue magenta cyan white

       The optional background color is specified by prepending "on_" to one of the foreground colors:

           on_black on_red on_green on_yellow on_blue on_magenta on_cyan on_white

       Each of the foreground colors can be modified with the following attributes, which may or may not be supported by your terminal:

           bold faint italic underline blink reverse concealed

       Any combinations of modifiers can be added to the foreground color. If your terminal supports it, and you enjoy visual punishment, you can specify:

           ack --color-filename="blink italic underline bold red on_yellow"

       For charts of the colors and what they look like, run "ack --help-colors" and "ack --help-rgb-colors".

       If the eight standard colors, in their bold, faint and unmodified states, aren't enough for you to choose from, you can also specify colors by their RGB values.  They are specified as "rgbXYZ"
       where X, Y, and Z are values between 0 and 5 giving the intensity of red, green and blue, respectively.  Therefore, "rgb500" is pure red, "rgb505" is purple, and so on.

       Background colors can be specified with the "on_" prefix prepended on an RGB color, so that "on_rgb505" would be a purple background.

       The modifier attributes of blink, italic, underscore and so on may or may not work on the RGB colors.

       For a chart of the 216 possible RGB colors, run "ack --help-rgb-colors".

ENVIRONMENT VARIABLES
       For commonly-used ack options, environment variables can make life much easier.  These variables are ignored if --noenv is specified on the command line.

       ACKRC
           Specifies the location of the user's .ackrc file.  If this file doesn't exist, ack looks in the default location.

       ACK_COLOR_COLNO
           Color specification for the column number in ack's output.  By default, the column number is not shown.  You have to enable it with the --column option.  See the section "ack Colors" above.

       ACK_COLOR_FILENAME
           Color specification for the filename in ack's output.  See the section "ack Colors" above.

       ACK_COLOR_LINENO
           Color specification for the line number in ack's output.  See the section "ack Colors" above.

       ACK_COLOR_MATCH
           Color specification for the matched text in ack's output.  See the section "ack Colors" above.

       ACK_PAGER
           Specifies a pager program, such as "more", "less" or "most", to which ack will send its output.

           Using "ACK_PAGER" does not suppress grouping and coloring like piping output on the command-line does, except that on Windows ack will assume that "ACK_PAGER" does not support color.

           "ACK_PAGER_COLOR" overrides "ACK_PAGER" if both are specified.

       ACK_PAGER_COLOR
           Specifies a pager program that understands ANSI color sequences.  Using "ACK_PAGER_COLOR" does not suppress grouping and coloring like piping output on the command-line does.

           If you are not on Windows, you never need to use "ACK_PAGER_COLOR".

ACK & OTHER TOOLS
   Simple vim integration
       ack integrates easily with the Vim text editor. Set this in your .vimrc to use ack instead of grep:

           set grepprg=ack\ -k

       That example uses "-k" to search through only files of the types ack knows about, but you may use other default flags. Now you can search with ack and easily step through the results in Vim:

         :grep Dumper perllib

   Editor integration
       Many users have integrated ack into their preferred text editors.  For details and links, see <https://beyondgrep.com/more-tools/>.

   Shell and Return Code
       For greater compatibility with grep, ack in normal use returns shell return or exit code of 0 only if something is found and 1 if no match is found.

       (Shell exit code 1 is "$?=256" in perl with "system" or backticks.)

       The grep code 2 for errors is not used.

       If "-f" or "-g" are specified, then 0 is returned if at least one file is found.  If no files are found, then 1 is returned.

DEBUGGING ACK PROBLEMS
       If ack gives you output you're not expecting, start with a few simple steps.

   Try it with --noenv
       Your environment variables and .ackrc may be doing things you're not expecting, or forgotten you specified.  Use --noenv to ignore your environment and .ackrc.

   Use -f to see what files have been selected for searching
       Ack's -f was originally added as a debugging tool.  If ack is not finding matches you think it should find, run ack -f to see what files have been selected.  You can also add the "--show-types"
       options to show the type of each file selected.

   Use --dump
       This lists the ackrc files that are loaded and the options loaded from them.  You may be loading an .ackrc file that you didn't know you were loading.

ACKRC LOCATION SEMANTICS
       Ack can load its configuration from many sources.  The following list specifies the sources Ack looks for configuration files; each one that is found is loaded in the order specified here, and
       each one overrides options set in any of the sources preceding it.  (For example, if I set --sort-files in my user ackrc, and --nosort-files on the command line, the command line takes
       precedence)

       •   Defaults are loaded from App::Ack::ConfigDefaults.  This can be omitted using "--ignore-ack-defaults".

       •   Global ackrc

           Options are then loaded from the global ackrc.  This is located at "/etc/ackrc" on Unix-like systems.

           Under Windows XP and earlier, the global ackrc is at "C:\Documents and Settings\All Users\Application Data\ackrc"

           Under Windows Vista/7, the global ackrc is at "C:\ProgramData\ackrc"

           The "--noenv" option prevents all ackrc files from being loaded.

       •   User ackrc

           Options are then loaded from the user's ackrc.  This is located at "$HOME/.ackrc" on Unix-like systems.

           Under Windows XP and earlier, the user's ackrc is at "C:\Documents and Settings\$USER\Application Data\ackrc".

           Under Windows Vista/7, the user's ackrc is at "C:\Users\$USER\AppData\Roaming\ackrc".

           If you want to load a different user-level ackrc, it may be specified with the $ACKRC environment variable.

           The "--noenv" option prevents all ackrc files from being loaded.

       •   Project ackrc

           Options are then loaded from the project ackrc.  The project ackrc is the first ackrc file with the name ".ackrc" or "_ackrc", first searching in the current directory, then the parent
           directory, then the grandparent directory, etc.  This can be omitted using "--noenv".

       •   --ackrc

           The "--ackrc" option may be included on the command line to specify an ackrc file that can override all others.  It is consulted even if "--noenv" is present.

       •   Command line

           Options are then loaded from the command line.

BUGS & ENHANCEMENTS
       ack is based at GitHub at <https://github.com/beyondgrep/ack3>

       Please report any bugs or feature requests to the issues list at GitHub: <https://github.com/beyondgrep/ack3/issues>.

       Please include the operating system that you're using; the output of the command "ack --version"; and any customizations in your .ackrc you may have.

       To suggest enhancements, please submit an issue at <https://github.com/beyondgrep/ack3/issues>.  Also read the DEVELOPERS.md file in the ack code repository.

       Also, feel free to discuss your issues on the ack mailing list at <https://groups.google.com/group/ack-users>.

SUPPORT
       Support for and information about ack can be found at:

       •   The ack homepage

           <https://beyondgrep.com/>

       •   Source repository

           <https://github.com/beyondgrep/ack3>

       •   The ack issues list at GitHub

           <https://github.com/beyondgrep/ack3/issues>

       •   The ack announcements mailing list

           <https://groups.google.com/group/ack-announcement>

       •   The ack users' mailing list

           <https://groups.google.com/group/ack-users>

       •   The ack development mailing list

           <https://groups.google.com/group/ack-users>

COMMUNITY
       There are ack mailing lists and a Slack channel for ack.  See <https://beyondgrep.com/community/> for details.

FAQ
       This is the Frequently Asked Questions list for ack.

   Can I stop using grep now?
       Many people find ack to be better than grep as an everyday tool 99% of the time, but don't throw grep away, because there are times you'll still need it.  For example, you might be looking
       through huge log files and not using regular expressions.  In that case, grep will probably perform better.

   Why isn't ack finding a match in (some file)?
       First, take a look and see if ack is even looking at the file.  ack is intelligent in what files it will search and which ones it won't, but sometimes that can be surprising.

       Use the "-f" switch, with no regex, to see a list of files that ack will search for you.  If your file doesn't show up in the list of files that "ack -f" shows, then ack never looks in it.

   Wouldn't it be great if ack did search & replace?
       No, ack will always be read-only.  Perl has a perfectly good way to do search & replace in files, using the "-i", "-p" and "-n" switches.

       You can certainly use ack to select your files to update.  For example, to change all "foo" to "bar" in all PHP files, you can do this from the Unix shell:

           $ perl -i -p -e's/foo/bar/g' $(ack -f --php)

   Can I make ack recognize .xyz files?
       Yes!  Please see "Defining your own types" in the ack manual.

   Will you make ack recognize .xyz files by default?
       We might, depending on how widely-used the file format is.

       Submit an issue at in the GitHub issue queue at <https://github.com/beyondgrep/ack3/issues>.  Explain what the file format is, where we can find out more about it, and what you have been using in
       your .ackrc to support it.

       Please do not bother creating a pull request.  The code for filetypes is trivial compared to the rest of the process we go through.

   Why is it called ack if it's called ack-grep?
       The name of the program is "ack".  Some packagers have called it "ack-grep" when creating packages because there's already a package out there called "ack" that has nothing to do with this ack.

       I suggest you make a symlink named ack that points to ack-grep because one of the crucial benefits of ack is having a name that's so short and simple to type.

       To do that, run this with sudo or as root:

          ln -s /usr/bin/ack-grep /usr/bin/ack

       Alternatively, you could use a shell alias:

           # bash/zsh
           alias ack=ack-grep

           # csh
           alias ack ack-grep

   What does ack mean?
       Nothing.  I wanted a name that was easy to type and that you could pronounce as a single syllable.

   Can I do multi-line regexes?
       No, ack does not support regexes that match multiple lines.  Doing so would require reading in the entire file at a time.

       If you want to see lines near your match, use the "--A", "--B" and "--C" switches for displaying context.

   Why is ack telling me I have an invalid option when searching for "+foo"?
       ack treats command line options beginning with "+" or "-" as options; if you would like to search for these, you may prefix your search term with "--" or use the "--match" option.  (However,
       don't forget that "+" is a regular expression metacharacter!)

   Why does "ack '.{40000,}'" fail?  Isn't that a valid regex?
       The Perl language limits the repetition quantifier to 32K.  You can search for ".{32767}" but not ".{32768}".

   Ack does "X" and shouldn't, should it?
       We try to remain as close to grep's behavior as possible, so when in doubt, see what grep does!  If there's a mismatch in functionality there, please submit an issue to GitHub, and/or bring it up
       on the ack-users mailing list.

ACKNOWLEDGEMENTS
       How appropriate to have acknowledgements!

       Thanks to everyone who has contributed to ack in any way, including Eric Pement, Gabor Szabo, Frieder Bluemle, Grzegorz Kaczmarczyk, Dan Book, Tomasz Konojacki, Salomon Smeke, M. Scott Ford,
       Anders Eriksson, H.Merijn Brand, Duke Leto, Gerhard Poul, Ethan Mallove, Marek Kubica, Ray Donnelly, Nikolaj Schumacher, Ed Avis, Nick Morrott, Austin Chamberlin, Varadinsky, Sébastien Feugère,
       Jakub Wilk, Pete Houston, Stephen Thirlwall, Jonah Bishop, Chris Rebert, Denis Howe, Raúl Gundín, James McCoy, Daniel Perrett, Steven Lee, Jonathan Perret, Fraser Tweedale, Raál Gundán, Steffen
       Jaeckel, Stephan Hohe, Michael Beijen, Alexandr Ciornii, Christian Walde, Charles Lee, Joe McMahon, John Warwick, David Steinbrunner, Kara Martens, Volodymyr Medvid, Ron Savage, Konrad Borowski,
       Dale Sedivic, Michael McClimon, Andrew Black, Ralph Bodenner, Shaun Patterson, Ryan Olson, Shlomi Fish, Karen Etheridge, Olivier Mengue, Matthew Wild, Scott Kyle, Nick Hooey, Bo Borgerson, Mark
       Szymanski, Marq Schneider, Packy Anderson, JR Boyens, Dan Sully, Ryan Niebur, Kent Fredric, Mike Morearty, Ingmar Vanhassel, Eric Van Dewoestine, Sitaram Chamarty, Adam James, Richard Carlsson,
       Pedro Melo, AJ Schuster, Phil Jackson, Michael Schwern, Jan Dubois, Christopher J. Madsen, Matthew Wickline, David Dyck, Jason Porritt, Jjgod Jiang, Thomas Klausner, Uri Guttman, Peter Lewis,
       Kevin Riggle, Ori Avtalion, Torsten Blix, Nigel Metheringham, Gábor Szabó, Tod Hagan, Michael Hendricks, Ævar Arnfjörð Bjarmason, Piers Cawley, Stephen Steneker, Elias Lutfallah, Mark Leighton
       Fisher, Matt Diephouse, Christian Jaeger, Bill Sully, Bill Ricker, David Golden, Nilson Santos F. Jr, Elliot Shank, Merijn Broeren, Uwe Voelker, Rick Scott, Ask Bjørn Hansen, Jerry Gay, Will
       Coleda, Mike O'Regan, Slaven Rezić, Mark Stosberg, David Alan Pisoni, Adriano Ferreira, James Keenan, Leland Johnson, Ricardo Signes, Pete Krawczyk and Rob Hoelz.

AUTHOR
       Andy Lester, "<andy at petdance.com>"

COPYRIGHT & LICENSE
       Copyright 2005-2022 Andy Lester.

       This program is free software; you can redistribute it and/or modify it under the terms of the Artistic License v2.0.

       See https://www.perlfoundation.org/artistic-license-20.html or the LICENSE.md file that comes with the ack distribution.

perl v5.36.0                                                                                    2022-11-14                                                                                          ACK(1)
