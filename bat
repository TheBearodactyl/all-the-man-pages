BAT(1)                                                                                    General Commands Manual                                                                                   BAT(1)

NAME
       bat - a cat(1) clone with syntax highlighting and Git integration.

USAGE
       bat [OPTIONS] [FILE]...

       bat cache [CACHE-OPTIONS] [--build|--clear]

DESCRIPTION
       bat prints the syntax-highlighted content of a collection of FILEs to the terminal. If no FILE is specified, or when FILE is '-', it reads from standard input.

       bat supports a large number of programming and markup languages.  It also communicates with git(1) to show modifications with respect to the git index.  bat automatically pipes its output through
       a pager (by default: less).

       Whenever the output of bat goes to a non-interactive terminal, i.e. when the output is piped into another process or into a file, bat will act as a drop-in replacement for cat(1) and fall back to
       printing the plain file contents.

OPTIONS
       General remarks: Command-line options like '-l'/'--language' that take values can be specified as either '--language value', '--language=value', '-l value' or '-lvalue'.

       -A, --show-all

              Show non-printable characters like space, tab or newline. Use '--tabs' to control the width of the tab-placeholders.

       --nonprintable-notation

              Specify how to display non-printable characters when using --show-all.

              Possible values:

              caret  Use character sequences like ^G, ^J, ^@, .. to identify non-printable characters

              unicode
                     Use special Unicode code points to identify non-printable characters

       -p, --plain

              Only show plain style, no decorations. This is an alias for '--style=plain'. When '-p' is used twice ('-pp'), it also disables automatic paging (alias for '--style=plain --paging=never').

       -l, --language <language>

              Explicitly  set  the  language  for  syntax  highlighting.  The  language  can  be  specified  as a name (like 'C++' or 'LaTeX') or possible file extension (like 'cpp', 'hpp' or 'md'). Use
              '--list-languages' to show all supported language names and file extensions.

       -H, --highlight-line <N:M>...

              Highlight the specified line ranges with a different background color. For example:

              --highlight-line 40
                     highlights line 40

              --highlight-line 30:40
                     highlights lines 30 to 40

              --highlight-line :40
                     highlights lines 1 to 40

              --highlight-line 40:
                     highlights lines 40 to the end of the file

              --highlight-line 30:+10
                     highlights lines 30 to 40

       --file-name <name>...

              Specify the name to display for a file. Useful when piping data to bat from STDIN when bat does not otherwise know the filename. Note that the provided file name is also  used  for  syntax
              detection.

       -d, --diff

              Only show lines that have been added/removed/modified with respect to the Git index. Use '--diff-context=N' to control how much context you want to see.

       --diff-context <N>...

              Include N lines of context around added/removed/modified lines when using '--diff'.

       --tabs <T>

              Set the tab width to T spaces. Use a width of 0 to pass tabs through directly

       --wrap <mode>

              Specify the text-wrapping mode (*auto*, never, character). The '--terminal-width' option can be used in addition to control the output width.

       --terminal-width <width>

              Explicitly  set  the  width  of  the terminal instead of determining it automatically. If prefixed with '+' or '-', the value will be treated as an offset to the actual terminal width. See
              also: '--wrap'.

       -n, --number

              Only show line numbers, no other decorations. This is an alias for '--style=numbers'

       --color <when>

              Specify when to use colored output. The automatic mode only enables colors if an interactive terminal is detected. Possible values: *auto*, never, always.

       --italic-text <when>

              Specify when to use ANSI sequences for italic text in the output. Possible values: always, *never*.

       --decorations <when>

              Specify when to use the decorations that have been specified via '--style'. The automatic mode only enables decorations if an interactive terminal is  detected.  Possible  values:  *auto*,
              never, always.

       -f, --force-colorization

              Alias for '--decorations=always --color=always'. This is useful if the output of bat is piped to another program, but you want to keep the colorization/decorations.

       --paging <when>

              Specify  when  to  use the pager. To disable the pager, use '--paging=never' or its alias, -P. To disable the pager permanently, set BAT_PAGER to an empty string. To control which pager is
              used, see the '--pager' option. Possible values: *auto*, never, always.

       --pager <command>

              Determine which pager is used. This option will override the PAGER and BAT_PAGER environment variables. The default pager is 'less'. To control when the pager is used, see  the  '--paging'
              option. Example: '--pager "less -RF"'.

              Note:  By  default,  if the pager is set to 'less' (and no command-line options are specified), 'bat' will pass the following command line options to the pager: '-R'/'--RAW-CONTROL-CHARS',
              '-F'/'--quit-if-one-screen' and '-X'/'--no-init'. The last option ('-X') is only used for 'less' versions older than 530. The '-R' option is needed to interpret ANSI colors correctly.  The
              second  option ('-F') instructs less to exit immediately if the output size is smaller than the vertical size of the terminal. This is convenient for small files because you do not have to
              press 'q' to quit the pager. The third option ('-X') is needed to fix a bug with the '--quit-if-one-screen' feature in old versions of 'less'. Unfortunately,  it  also  breaks  mouse-wheel
              support  in  'less'. If you want to enable mouse-wheel scrolling on older versions of 'less', you can pass just '-R' (as in the example above, this will disable the quit-if-one-screen fea‐
              ture). For less 530 or newer, it should work out of the box.

       -m, --map-syntax <glob-pattern:syntax-name>...

              Map a glob pattern to an existing syntax name. The glob pattern is matched on the full path and the filename. For example, to highlight  *.build  files  with  the  Python  syntax,  use  -m
              '*.build:Python'. To highlight files named '.myignore' with the Git Ignore syntax, use -m '.myignore:Git Ignore'.  Note that the right-hand side is the *name* of the syntax, not a file ex‐
              tension.

       --theme <theme>

              Set the theme for syntax highlighting. Use '--list-themes' to see all available themes.  To set a default theme, add the '--theme="..."' option to the  configuration  file  or  export  the
              BAT_THEME environment variable (e.g.: export BAT_THEME="...").

       --list-themes

              Display a list of supported themes for syntax highlighting.

       --style <style-components>

              Configure which elements (line numbers, file headers, grid borders, Git modifications, ..) to display in addition to the file contents. The argument is a comma-separated list of components
              to display (e.g. 'numbers,changes,grid') or a pre-defined style ('full').  To set a default style, add the '--style=".."' option to the configuration file or export the BAT_STYLE  environ‐
              ment variable (e.g.: export BAT_STYLE=".."). Possible values: *default*, full, auto, plain, changes, header, header-filename, header-filesize, grid, rule, numbers, snip.

       -r, --line-range <N:M>...

              Only print the specified range of lines for each file. For example:

              --line-range 30:40
                     prints lines 30 to 40

              --line-range :40
                     prints lines 1 to 40

              --line-range 40:
                     prints lines 40 to the end of the file

              --line-range 30:+10
                     prints lines 30 to 40

       -L, --list-languages

              Display a list of supported languages for syntax highlighting.

       -u, --unbuffered

              This option exists for POSIX-compliance reasons ('u' is for 'unbuffered'). The output is always unbuffered - this option is simply ignored.

       -h, --help

              Print this help message.

       -V, --version

              Show version information.

POSITIONAL ARGUMENTS
       <FILE>...

              Files to print and concatenate. Use a dash ('-') or no argument at all to read from standard input.

SUBCOMMANDS
       cache - Modify the syntax-definition and theme cache.

FILES
       bat can also be customized with a configuration file. The location of the file is dependent on your operating system. To get the default path for your system, call:

       bat --config-file

       Alternatively, you can use the BAT_CONFIG_PATH environment variable to point bat to a non-default location of the configuration file.

       To generate a default configuration file, call:

       bat --generate-config-file

ADDING CUSTOM LANGUAGES
       bat  supports  Sublime  Text  .sublime-syntax  language  files, and can be customized to add additional languages to your local installation. To do this, add the .sublime-syntax language files to
       `$(bat --config-dir)/syntaxes` and run `bat cache --build`.

       Example:

            mkdir -p "$(bat --config-dir)/syntaxes"
            cd "$(bat --config-dir)/syntaxes"

            # Put new '.sublime-syntax' language definition files
            # in this folder (or its subdirectories), for example:
            git clone https://github.com/tellnobody1/sublime-purescript-syntax

            # And then build the cache.
            bat cache --build

       Once the cache is built, the new language will be visible in `bat --list-languages`.
       If you ever want to remove the custom languages, you can clear the cache with `bat cache --clear`.

ADDING CUSTOM THEMES
       Similarly to custom languages, bat supports Sublime Text .tmTheme themes.  These can be installed to `$(bat --config-dir)/themes`, and are added to the cache with `bat cache --build`.

MORE INFORMATION
       For more information and up-to-date documentation, visit the bat repo:
       https://github.com/sharkdp/bat

                                                                                                                                                                                                    BAT(1)
