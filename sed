SED(1)                           User Commands                          SED(1)

NAME
       sed - stream editor for filtering and transforming text

SYNOPSIS
       sed [-V] [--version] [--help] [-n] [--quiet] [--silent]
           [-l N] [--line-length=N] [-u] [--unbuffered]
           [-E] [-r] [--regexp-extended]
           [-e script] [--expression=script]
           [-f script-file] [--file=script-file]
           [script-if-no-other-script]
           [file...]

DESCRIPTION
       Sed  is a stream editor.  A stream editor is used to perform basic text
       transformations on an input stream (a file or input from  a  pipeline).
       While  in  some  ways similar to an editor which permits scripted edits
       (such as ed), sed works by making only one pass over the input(s),  and
       is consequently more efficient.  But it is sed's ability to filter text
       in a pipeline which particularly distinguishes it from other  types  of
       editors.

       -n, --quiet, --silent

              suppress automatic printing of pattern space

       --debug

              annotate program execution

       -e script, --expression=script

              add the script to the commands to be executed

       -f script-file, --file=script-file

              add the contents of script-file to the commands to be executed

       --follow-symlinks

              follow symlinks when processing in place

       -i[SUFFIX], --in-place[=SUFFIX]

              edit files in place (makes backup if SUFFIX supplied)

       -l N, --line-length=N

              specify the desired line-wrap length for the `l' command

       --posix

              disable all GNU extensions.

       -E, -r, --regexp-extended

              use  extended regular expressions in the script (for portability
              use POSIX -E).

       -s, --separate

              consider files as separate rather than as a  single,  continuous
              long stream.

       --sandbox

              operate in sandbox mode (disable e/r/w commands).

       -u, --unbuffered

              load  minimal amounts of data from the input files and flush the
              output buffers more often

       -z, --null-data

              separate lines by NUL characters

       --help
              display this help and exit

       --version
              output version information and exit

       If no -e, --expression, -f, or --file option is given, then  the  first
       non-option  argument  is taken as the sed script to interpret.  All re‐
       maining arguments are names of input files; if no input files are spec‐
       ified, then the standard input is read.

       GNU  sed  home page: <https://www.gnu.org/software/sed/>.  General help
       using GNU software: <https://www.gnu.org/gethelp/>.  E-mail bug reports
       to: <bug-sed@gnu.org>.

COMMAND SYNOPSIS
       This is just a brief synopsis of sed commands to serve as a reminder to
       those who already know sed; other documentation (such  as  the  texinfo
       document) must be consulted for fuller descriptions.

   Zero-address ``commands''
       : label
              Label for b and t commands.

       #comment
              The  comment  extends until the next newline (or the end of a -e
              script fragment).

       }      The closing bracket of a { } block.

   Zero- or One- address commands
       =      Print the current line number.

       a \

       text   Append text, which has each embedded newline preceded by a back‐
              slash.

       i \

       text   Insert text, which has each embedded newline preceded by a back‐
              slash.

       q [exit-code]
              Immediately quit the sed script without processing any more  in‐
              put,  except that if auto-print is not disabled the current pat‐
              tern space will be printed.  The exit code argument is a GNU ex‐
              tension.

       Q [exit-code]
              Immediately  quit the sed script without processing any more in‐
              put.  This is a GNU extension.

       r filename
              Append text read from filename.

       R filename
              Append a line read from filename.  Each invocation of  the  com‐
              mand reads a line from the file.  This is a GNU extension.

   Commands which accept address ranges
       {      Begin a block of commands (end with a }).

       b label
              Branch to label; if label is omitted, branch to end of script.

       c \

       text   Replace  the  selected  lines with text, which has each embedded
              newline preceded by a backslash.

       d      Delete pattern space.  Start next cycle.

       D      If pattern space contains no newline, start a normal  new  cycle
              as  if  the d command was issued.  Otherwise, delete text in the
              pattern space up to the first newline, and  restart  cycle  with
              the  resultant  pattern space, without reading a new line of in‐
              put.

       h H    Copy/append pattern space to hold space.

       g G    Copy/append hold space to pattern space.

       l      List out the current line in a ``visually unambiguous'' form.

       l width
              List out the current line in a  ``visually  unambiguous''  form,
              breaking it at width characters.  This is a GNU extension.

       n N    Read/append the next line of input into the pattern space.

       p      Print the current pattern space.

       P      Print  up  to  the first embedded newline of the current pattern
              space.

       s/regexp/replacement/
              Attempt to match regexp against the pattern space.  If  success‐
              ful,  replace  that  portion  matched with replacement.  The re‐
              placement may contain the special character & to refer  to  that
              portion  of the pattern space which matched, and the special es‐
              capes \1 through \9 to refer to the corresponding matching  sub-
              expressions in the regexp.

       t label
              If  a s/// has done a successful substitution since the last in‐
              put line was read and since the last t or T command, then branch
              to label; if label is omitted, branch to end of script.

       T label
              If no s/// has done a successful substitution since the last in‐
              put line was read and since the last t or T command, then branch
              to label; if label is omitted, branch to end of script.  This is
              a GNU extension.

       w filename
              Write the current pattern space to filename.

       W filename
              Write the first line of the current pattern space  to  filename.
              This is a GNU extension.

       x      Exchange the contents of the hold and pattern spaces.

       y/source/dest/
              Transliterate  the  characters in the pattern space which appear
              in source to the corresponding character in dest.

Addresses
       Sed commands can be given with no addresses, in which case the  command
       will  be  executed for all input lines; with one address, in which case
       the command will only be executed for input lines which match that  ad‐
       dress;  or  with  two addresses, in which case the command will be exe‐
       cuted for all input lines which match  the  inclusive  range  of  lines
       starting  from  the first address and continuing to the second address.
       Three things to note about address ranges: the  syntax  is  addr1,addr2
       (i.e.,  the  addresses  are separated by a comma); the line which addr1
       matched will always be accepted, even if addr2 selects an earlier line;
       and  if  addr2 is a regexp, it will not be tested against the line that
       addr1 matched.

       After the address (or address-range), and before the command, a !   may
       be inserted, which specifies that the command shall only be executed if
       the address (or address-range) does not match.

       The following address types are supported:

       number Match only the specified line number (which  increments  cumula‐
              tively  across  files,  unless the -s option is specified on the
              command line).

       first~step
              Match every step'th line starting with line first.  For example,
              ``sed -n 1~2p'' will print all the odd-numbered lines in the in‐
              put stream, and the address 2~5 will  match  every  fifth  line,
              starting  with the second.  first can be zero; in this case, sed
              operates as if it were equal to step.  (This is an extension.)

       $      Match the last line.

       /regexp/
              Match lines matching the regular expression regexp.  Matching is
              performed  on  the  current pattern space, which can be modified
              with commands such as ``s///''.

       \cregexpc
              Match lines matching the regular expression regexp.  The  c  may
              be any character.

       GNU sed also supports some special 2-address forms:

       0,addr2
              Start  out  in  "matched  first  address"  state, until addr2 is
              found.  This is similar to 1,addr2, except that if addr2 matches
              the very first line of input the 0,addr2 form will be at the end
              of its range, whereas the 1,addr2 form will still be at the  be‐
              ginning  of  its range.  This works only when addr2 is a regular
              expression.

       addr1,+N
              Will match addr1 and the N lines following addr1.

       addr1,~N
              Will match addr1 and the lines following addr1  until  the  next
              line whose input line number is a multiple of N.

REGULAR EXPRESSIONS
       POSIX.2 BREs should be supported, but they aren't completely because of
       performance problems.  The \n sequence in a regular expression  matches
       the  newline  character, and similarly for \a, \t, and other sequences.
       The -E option switches to using extended regular  expressions  instead;
       it  has  been  supported  for  years by GNU sed, and is now included in
       POSIX.

BUGS
       E-mail bug reports to bug-sed@gnu.org.  Also, please include the output
       of ``sed --version'' in the body of your report if at all possible.

AUTHOR
       Written by Jay Fenlason, Tom Lord, Ken Pizzini, Paolo Bonzini, Jim Mey‐
       ering, and Assaf Gordon.

       This sed program was built without SELinux support.

       GNU sed home page: <https://www.gnu.org/software/sed/>.   General  help
       using GNU software: <https://www.gnu.org/gethelp/>.  E-mail bug reports
       to: <bug-sed@gnu.org>.

COPYRIGHT
       Copyright © 2022 Free Software Foundation, Inc.   License  GPLv3+:  GNU
       GPL version 3 or later <https://gnu.org/licenses/gpl.html>.
       This  is  free  software:  you  are free to change and redistribute it.
       There is NO WARRANTY, to the extent permitted by law.

SEE ALSO
       awk(1), ed(1), grep(1), tr(1),  perlre(1),  sed.info,  any  of  various
       books on sed, the sed FAQ (http://sed.sf.net/grabbag/tutorials/sed‐
       faq.txt), http://sed.sf.net/grabbag/.

       The full documentation for sed is maintained as a Texinfo manual.  If
       the info and sed programs are properly installed at your site, the com‐
       mand

              info sed

       should give you access to the complete manual.

GNU sed 4.9                       March 2023                            SED(1)
SED(1P)                    POSIX Programmer's Manual                   SED(1P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux
       implementation of this interface may differ (consult the  corresponding
       Linux  manual page for details of Linux behavior), or the interface may
       not be implemented on Linux.

NAME
       sed — stream editor

SYNOPSIS
       sed [-n] script [file...]

       sed [-n] -e script [-e script]... [-f script_file]... [file...]

       sed [-n] [-e script]... -f script_file [-f script_file]... [file...]

DESCRIPTION
       The sed utility is a stream editor that shall read  one  or  more  text
       files,  make editing changes according to a script of editing commands,
       and write the results to standard output. The script shall be  obtained
       from  either  the script operand string or a combination of the option-
       arguments from the -e script and -f script_file options.

OPTIONS
       The sed utility  shall  conform  to  the  Base  Definitions  volume  of
       POSIX.1‐2017,  Section 12.2, Utility Syntax Guidelines, except that the
       order of presentation of the -e and -f options is significant.

       The following options shall be supported:

       -e script Add the editing commands specified by the script option-argu‐
                 ment to the end of the script of editing commands.

       -f script_file
                 Add  the  editing commands in the file script_file to the end
                 of the script of editing commands.

       -n        Suppress the default output (in which each line, after it  is
                 examined  for  editing,  is written to standard output). Only
                 lines explicitly selected for output are written.

       If any -e or -f options are specified, the script of  editing  commands
       shall  initially  be empty. The commands specified by each -e or -f op‐
       tion shall be added to the script in the order specified. When each ad‐
       dition is made, if the previous addition (if any) was from a -e option,
       a <newline> shall be inserted before the new  addition.  The  resulting
       script  shall have the same properties as the script operand, described
       in the OPERANDS section.

OPERANDS
       The following operands shall be supported:

       file      A pathname of a file whose contents are read and  edited.  If
                 multiple  file  operands are specified, the named files shall
                 be read in the order specified and the concatenation shall be
                 edited. If no file operands are specified, the standard input
                 shall be used.

       script    A string to be used as the script of  editing  commands.  The
                 application  shall not present a script that violates the re‐
                 strictions of a text file except  that  the  final  character
                 need not be a <newline>.

STDIN
       The standard input shall be used if no file operands are specified, and
       shall be used if a file operand is '-' and  the  implementation  treats
       the '-' as meaning standard input.  Otherwise, the standard input shall
       not be used.  See the INPUT FILES section.

INPUT FILES
       The input files shall be text files. The script_files named by  the  -f
       option shall consist of editing commands.

ENVIRONMENT VARIABLES
       The following environment variables shall affect the execution of sed:

       LANG      Provide  a  default  value for the internationalization vari‐
                 ables that are unset or null. (See the Base Definitions  vol‐
                 ume  of POSIX.1‐2017, Section 8.2, Internationalization Vari‐
                 ables for the precedence  of  internationalization  variables
                 used to determine the values of locale categories.)

       LC_ALL    If  set  to  a non-empty string value, override the values of
                 all the other internationalization variables.

       LC_COLLATE
                 Determine the locale for the behavior of ranges,  equivalence
                 classes,  and multi-character collating elements within regu‐
                 lar expressions.

       LC_CTYPE  Determine the locale for the interpretation of  sequences  of
                 bytes of text data as characters (for example, single-byte as
                 opposed to  multi-byte  characters  in  arguments  and  input
                 files),  and the behavior of character classes within regular
                 expressions.

       LC_MESSAGES
                 Determine the locale that should be used to affect the format
                 and  contents  of diagnostic messages written to standard er‐
                 ror.

       NLSPATH   Determine the location of message catalogs for the processing
                 of LC_MESSAGES.

ASYNCHRONOUS EVENTS
       Default.

STDOUT
       The  input  files shall be written to standard output, with the editing
       commands specified in the script applied. If the -n  option  is  speci‐
       fied, only those input lines selected by the script shall be written to
       standard output.

STDERR
       The standard error shall be used only for diagnostic and  warning  mes‐
       sages.

OUTPUT FILES
       The output files shall be text files whose formats are dependent on the
       editing commands given.

EXTENDED DESCRIPTION
       The script shall consist of editing commands of the following form:

           [address[,address]]function

       where function represents a single-character command verb from the list
       in Editing Commands in sed, followed by any applicable arguments.

       The  command  can  be preceded by <blank> characters and/or <semicolon>
       characters. The function can be preceded by <blank>  characters.  These
       optional characters shall have no effect.

       In default operation, sed cyclically shall append a line of input, less
       its terminating <newline> character, into the  pattern  space.  Reading
       from  input  shall  be  skipped if a <newline> was in the pattern space
       prior to a D command ending the previous cycle. The sed  utility  shall
       then apply in sequence all commands whose addresses select that pattern
       space, until a command starts the next cycle or quits. If  no  commands
       explicitly  started a new cycle, then at the end of the script the pat‐
       tern space shall be copied to standard output (except when -n is speci‐
       fied)  and  the  pattern  space  shall be deleted. Whenever the pattern
       space is written to standard output or a named file, sed shall  immedi‐
       ately follow it with a <newline>.

       Some  of  the  editing commands use a hold space to save all or part of
       the pattern space for subsequent retrieval. The pattern and hold spaces
       shall each be able to hold at least 8192 bytes.

   Addresses in sed
       An  address  is either a decimal number that counts input lines cumula‐
       tively across files, a '$' character that addresses the  last  line  of
       input,  or  a context address (which consists of a BRE, as described in
       Regular Expressions in sed, preceded and followed by a delimiter,  usu‐
       ally a <slash>).

       An editing command with no addresses shall select every pattern space.

       An  editing  command  with  one address shall select each pattern space
       that matches the address.

       An editing command with two addresses shall select the inclusive  range
       from the first pattern space that matches the first address through the
       next pattern space that matches the second. (If the second address is a
       number  less  than or equal to the line number first selected, only one
       line shall be selected.) Starting at the first line following  the  se‐
       lected  range,  sed shall look again for the first address. Thereafter,
       the process shall be repeated. Omitting either or both of  the  address
       components in the following form produces undefined results:

           [address[,address]]

   Regular Expressions in sed
       The  sed  utility  shall support the BREs described in the Base Defini‐
       tions volume of POSIX.1‐2017, Section 9.3, Basic  Regular  Expressions,
       with the following additions:

        *  In  a  context  address,  the construction "\cBREc", where c is any
           character other than <backslash> or <newline>, shall  be  identical
           to  "/BRE/".   If the character designated by c appears following a
           <backslash>, then it shall be considered to be that literal charac‐
           ter, which shall not terminate the BRE. For example, in the context
           address "\xabc\xdefx", the second x stands for itself, so that  the
           BRE is "abcxdef".

        *  The  escape  sequence  '\n' shall match a <newline> embedded in the
           pattern space. A literal <newline> shall not be used in the BRE  of
           a context address or in the substitute function.

        *  If  an RE is empty (that is, no pattern is specified) sed shall be‐
           have as if the last RE used in the last command applied (either  as
           an address or as part of a substitute command) was specified.

   Editing Commands in sed
       In  the  following list of editing commands, the maximum number of per‐
       missible addresses for each function is indicated by [0addr],  [1addr],
       or [2addr], representing zero, one, or two addresses.

       The  argument  text  shall  consist of one or more lines. Each embedded
       <newline> in the text shall be preceded by a <backslash>.  Other <back‐
       slash> characters in text shall be removed, and the following character
       shall be treated literally.

       The r and w command verbs, and the w flag to the  s  command,  take  an
       rfile  (or  wfile) parameter, separated from the command verb letter or
       flag by one or more <blank> characters; implementations may allow  zero
       separation as an extension.

       The  argument  rfile  or the argument wfile shall terminate the editing
       command. Each wfile shall be created before processing  begins.  Imple‐
       mentations  shall  support  at least ten wfile arguments in the script;
       the actual number (greater than or equal to 10) that  is  supported  by
       the implementation is unspecified. The use of the wfile parameter shall
       cause that file to be initially created, if it does not exist, or shall
       replace the contents of an existing file.

       The b, r, s, t, w, y, and : command verbs shall accept additional argu‐
       ments. The following synopses indicate which arguments shall  be  sepa‐
       rated from the command verbs by a single <space>.

       The a and r commands schedule text for later output. The text specified
       for the a command, and the contents of the file  specified  for  the  r
       command,  shall  be written to standard output just before the next at‐
       tempt to fetch a line of input when executing the N or n  commands,  or
       when  reaching  the end of the script. If written when reaching the end
       of the script, and the -n option was not specified, the text  shall  be
       written  after  copying  the pattern space to standard output. The con‐
       tents of the file specified for the r command shall be as of  the  time
       the  output is written, not the time the r command is applied. The text
       shall be output in the order in which the a and r commands were applied
       to the input.

       Editing commands other than {...}, a, b, c, i, r, t, w, :, and # can be
       followed by a <semicolon>, optional  <blank>  characters,  and  another
       editing  command. However, when an s editing command is used with the w
       flag, following it with another command in this manner  produces  unde‐
       fined results.

       A function can be preceded by a '!'  character, in which case the func‐
       tion shall be applied if the addresses do not select the pattern space.
       Zero or more <blank> characters shall be accepted before the '!'  char‐
       acter. It is unspecified whether <blank> characters can follow the  '!'
       character,  and conforming applications shall not follow the '!'  char‐
       acter with <blank> characters.

       If a label argument (to a b, t, or : command) contains characters  out‐
       side  of  the  portable filename character set, or if a label is longer
       than 8 bytes, the behavior is  unspecified.  The  implementation  shall
       support  label  arguments  recognized as unique up to at least 8 bytes;
       the actual length (greater than or equal to 8) supported by the  imple‐
       mentation is unspecified. It is unspecified whether exceeding the maxi‐
       mum supported label length causes an error or a silent truncation.

       [2addr] {editing command

       editing command

       ...

       }         Execute a list of sed editing commands only when the  pattern
                 space  is selected. The list of sed editing commands shall be
                 surrounded by braces. The braces can be preceded or  followed
                 by <blank> characters. The <right-brace> shall be preceded by
                 a <newline> or <semicolon> (before any optional <blank> char‐
                 acters preceding the <right-brace>).

                 Each command in the list of commands shall be terminated by a
                 <newline> character, or by a <semicolon> character if permit‐
                 ted when the command is used outside the braces.  The editing
                 commands can be preceded by <blank> characters, but shall not
                 be followed by <blank> characters.

       [1addr]a\

       text      Write text to standard output as described previously.

       [2addr]b [label]
                 Branch  to the : command verb bearing the label argument.  If
                 label is not specified, branch to the end of the script.

       [2addr]c\

       text      Delete the pattern space. With a 0 or 1 address or at the end
                 of  a 2-address range, place text on the output and start the
                 next cycle.

       [2addr]d  Delete the pattern space and start the next cycle.

       [2addr]D  If the pattern space contains no <newline>, delete  the  pat‐
                 tern  space  and start a normal new cycle as if the d command
                 was issued. Otherwise, delete the initial segment of the pat‐
                 tern  space  through  the first <newline>, and start the next
                 cycle with the resultant pattern space  and  without  reading
                 any new input.

       [2addr]g  Replace  the contents of the pattern space by the contents of
                 the hold space.

       [2addr]G  Append to the pattern space a <newline> followed by the  con‐
                 tents of the hold space.

       [2addr]h  Replace  the  contents of the hold space with the contents of
                 the pattern space.

       [2addr]H  Append to the hold space a <newline> followed by the contents
                 of the pattern space.

       [1addr]i\

       text      Write text to standard output.

       [2addr]l  (The  letter ell.) Write the pattern space to standard output
                 in a visually unambiguous form. The characters listed in  the
                 Base  Definitions  volume  of POSIX.1‐2017, Table 5-1, Escape
                 Sequences and Associated Actions  ('\\',  '\a',  '\b',  '\f',
                 '\r',  '\t',  '\v') shall be written as the corresponding es‐
                 cape sequence; the '\n' in that table is not applicable. Non-
                 printable  characters  not  in that table shall be written as
                 one three-digit octal number (with a  preceding  <backslash>)
                 for each byte in the character (most significant byte first).

                 Long  lines  shall be folded, with the point of folding indi‐
                 cated by writing a <backslash> followed by a  <newline>;  the
                 length  at which folding occurs is unspecified, but should be
                 appropriate for the output device. The end of each line shall
                 be marked with a '$'.

       [2addr]n  Write  the  pattern  space  to standard output if the default
                 output has not been suppressed, and replace the pattern space
                 with the next line of input, less its terminating <newline>.

                 If  no  next  line  of input is available, the n command verb
                 shall branch to the end of the script and quit without start‐
                 ing a new cycle.

       [2addr]N  Append  the  next  line  of input, less its terminating <new‐
                 line>, to the pattern space, using an embedded  <newline>  to
                 separate  the  appended  material from the original material.
                 Note that the current line number changes.

                 If no next line of input is available,  the  N  command  verb
                 shall branch to the end of the script and quit without start‐
                 ing a new cycle or copying the pattern space to standard out‐
                 put.

       [2addr]p  Write the pattern space to standard output.

       [2addr]P  Write  the pattern space, up to the first <newline>, to stan‐
                 dard output.

       [1addr]q  Branch to the end of the script and quit without  starting  a
                 new cycle.

       [1addr]r rfile
                 Copy  the  contents  of rfile to standard output as described
                 previously. If rfile does not exist or  cannot  be  read,  it
                 shall  be treated as if it were an empty file, causing no er‐
                 ror condition.

       [2addr]s/BRE/replacement/flags
                 Substitute the replacement string for instances of the BRE in
                 the  pattern  space.  Any character other than <backslash> or
                 <newline> can be used instead of a <slash> to delimit the BRE
                 and  the replacement. Within the BRE and the replacement, the
                 BRE delimiter itself can be used as a literal character if it
                 is preceded by a <backslash>.

                 The  replacement  string  shall  be scanned from beginning to
                 end. An <ampersand> ('&') appearing in the replacement  shall
                 be replaced by the string matching the BRE. The special mean‐
                 ing of '&' in this context can be suppressed by preceding  it
                 by  a  <backslash>.  The characters "\n", where n is a digit,
                 shall be replaced by the text matched  by  the  corresponding
                 back-reference  expression.  If the corresponding back-refer‐
                 ence expression does not  match,  then  the  characters  "\n"
                 shall be replaced by the empty string. The special meaning of
                 "\n" where n is a digit in this context, can be suppressed by
                 preceding  it  by  a <backslash>.  For each other <backslash>
                 encountered, the following character shall lose  its  special
                 meaning (if any).

                 A  line can be split by substituting a <newline> into it. The
                 application shall escape the <newline> in the replacement  by
                 preceding it by a <backslash>.

                 The  meaning of an unescaped <backslash> immediately followed
                 by any character other than '&', <backslash>, a digit,  <new‐
                 line>,  or  the delimiter character used for this command, is
                 unspecified.

                 A substitution shall be considered  to  have  been  performed
                 even  if  the  replacement  string is identical to the string
                 that it replaces. Any <backslash> used to alter  the  default
                 meaning of a subsequent character shall be discarded from the
                 BRE or the replacement before evaluating the BRE or using the
                 replacement.

                 The value of flags shall be zero or more of:

                 n         Substitute  for  the nth occurrence only of the BRE
                           found within the pattern space.

                 g         Globally substitute  for  all  non-overlapping  in‐
                           stances  of the BRE rather than just the first one.
                           If both g and n are specified, the results are  un‐
                           specified.

                 p         Write the pattern space to standard output if a re‐
                           placement was made.

                 w wfile   Write. Append the pattern space to wfile if  a  re‐
                           placement  was made. A conforming application shall
                           precede the wfile argument with one or more <blank>
                           characters.  If  the  w  flag  is not the last flag
                           value given in a  concatenation  of  multiple  flag
                           values, the results are undefined.

       [2addr]t [label]
                 Test.  Branch  to the : command verb bearing the label if any
                 substitutions have been made since the most recent reading of
                 an  input  line  or execution of a t.  If label is not speci‐
                 fied, branch to the end of the script.

       [2addr]w wfile
                 Append (write) the pattern space to wfile.

       [2addr]x  Exchange the contents of the pattern and hold spaces.

       [2addr]y/string1/string2/
                 Replace all occurrences of characters  in  string1  with  the
                 corresponding  characters  in string2.  If a <backslash> fol‐
                 lowed by an 'n' appear in string1 or string2, the two charac‐
                 ters  shall  be handled as a single <newline>.  If the number
                 of characters in string1 and string2 are not equal, or if any
                 of  the  characters in string1 appear more than once, the re‐
                 sults are undefined. Any character other than <backslash>  or
                 <newline>  can  be  used  instead  of  <slash> to delimit the
                 strings. If the delimiter is  not  'n',  within  string1  and
                 string2,  the delimiter itself can be used as a literal char‐
                 acter if it is preceded by a <backslash>.  If  a  <backslash>
                 character  is immediately followed by a <backslash> character
                 in string1 or string2, the two <backslash>  characters  shall
                 be  counted  as  a  single literal <backslash> character. The
                 meaning of a <backslash> followed by any  character  that  is
                 not  'n',  a <backslash>, or the delimiter character is unde‐
                 fined.

       [0addr]:label
                 Do nothing. This command bears a label to which the b  and  t
                 commands branch.

       [1addr]=  Write the following to standard output:

                     "%d\n", <current line number>

       [0addr]   Ignore this empty command.

       [0addr]#  Ignore the '#' and the remainder of the line (treat them as a
                 comment), with the single exception that  if  the  first  two
                 characters  in  the script are "#n", the default output shall
                 be suppressed; this shall be the equivalent of specifying  -n
                 on the command line.

EXIT STATUS
       The following exit values shall be returned:

        0    Successful completion.

       >0    An error occurred.

CONSEQUENCES OF ERRORS
       Default.

       The following sections are informative.

APPLICATION USAGE
       Regular  expressions  match  entire strings, not just individual lines,
       but a <newline> is matched by '\n' in a sed RE; a <newline> is not  al‐
       lowed  by the general definition of regular expression in POSIX.1‐2008.
       Also note that '\n' cannot be used to match a <newline> at the  end  of
       an  arbitrary  input  line;  <newline> characters appear in the pattern
       space as a result of the N editing command.

       When using sed to process pathnames, it is recommended that LC_ALL,  or
       at least LC_CTYPE and LC_COLLATE, are set to POSIX or C in the environ‐
       ment, since pathnames can contain byte sequences that do not form valid
       characters  in some locales, in which case the utility's behavior would
       be undefined. In the POSIX locale each  byte  is  a  valid  single-byte
       character, and therefore this problem is avoided.

EXAMPLES
       This  sed  script  simulates  the  BSD cat -s command, squeezing excess
       empty lines from standard input.

           sed -n '
           # Write non-empty lines.
           /./ {
               p
               d
               }
           # Write a single empty line, then look for more empty lines.
           /^$/    p
           # Get next line, discard the held <newline> (empty line),
           # and look for more empty lines.
           :Empty
           /^$/    {
               N
               s/.//
               b Empty
               }
           # Write the non-empty line before going back to search
           # for the first in a set of empty lines.
               p
           '

       The following sed command is a much simpler method of  squeezing  empty
       lines, although it is not quite the same as cat -s since it removes any
       initial empty lines:

           sed -n '/./,/^$/p'

RATIONALE
       This volume of POSIX.1‐2017  requires  implementations  to  support  at
       least  ten distinct wfiles, matching historical practice on many imple‐
       mentations. Implementations are encouraged to support  more,  but  con‐
       forming applications should not exceed this limit.

       The exit status codes specified here are different from those in System
       V. System V returns 2 for garbled sed commands, but returns  zero  with
       its  usage  message or if the input file could not be opened. The stan‐
       dard developers considered this to be a bug.

       The manner in which the l command writes non-printable  characters  was
       changed  to avoid the historical backspace-overstrike method, and other
       requirements to achieve unambiguous output were added. See  the  RATIO‐
       NALE for ed for details of the format chosen, which is the same as that
       chosen for sed.

       This volume of POSIX.1‐2017 requires implementations to provide pattern
       and hold spaces of at least 8192 bytes, larger than the 4000 bytes spa‐
       ces used by some historical implementations, but less  than  the  20480
       bytes  limit  used in an early proposal. Implementations are encouraged
       to allocate dynamically larger pattern and hold spaces as needed.

       The requirements for acceptance of <blank> and  <space>  characters  in
       command  lines  has  been made more explicit than in early proposals to
       describe clearly the historical practice and to remove confusion  about
       the  phrase  ``protect initial blanks [sic] and tabs from the stripping
       that is done on every script line'' that appears in much of the histor‐
       ical documentation of the sed utility description of text. (Not all im‐
       plementations are known to have stripped <blank> characters  from  text
       lines,  although  they all have allowed leading <blank> characters pre‐
       ceding the address on a command line.)

       The treatment of '#' comments differs from the SVID which only allows a
       comment as the first line of the script, but matches BSD-derived imple‐
       mentations. The comment character is treated as a command, and  it  has
       the  same  properties  in  terms of being accepted with leading <blank>
       characters; the BSD implementation has historically supported this.

       Early proposals required that a script_file have at least one  non-com‐
       ment  line.  Some historical implementations have behaved in unexpected
       ways if this were not the case. The standard developers considered that
       this  was incorrect behavior and that application developers should not
       have to avoid this feature. A correct implementation of this volume  of
       POSIX.1‐2017  shall  permit  script_files  that consist only of comment
       lines.

       Early proposals indicated that if -e and -f  options  were  intermixed,
       all  -e  options  were  processed  before any -f options. This has been
       changed to process them in the order presented because it matches  his‐
       torical practice and is more intuitive.

       The  treatment  of the p flag to the s command differs between System V
       and BSD-based systems when the default output is suppressed. In the two
       examples:

           echo a | sed    's/a/A/p'
           echo a | sed -n 's/a/A/p'

       this  volume of POSIX.1‐2017, BSD, System V documentation, and the SVID
       indicate that the first example should write two lines with A,  whereas
       the  second  should  write  one. Some System V systems write the A only
       once in both examples because the p flag is ignored if the -n option is
       not specified.

       This  is  a case of a diametrical difference between systems that could
       not be reconciled through the compromise of declaring the  behavior  to
       be  unspecified.  The  SVID/BSD/System  V  documentation  behavior  was
       adopted for this volume of POSIX.1‐2017 because:

        *  No known documentation for any historic system describes the inter‐
           action between the p flag and the -n option.

        *  The selected behavior is more correct as there is no technical jus‐
           tification for any interaction between the p flag and  the  -n  op‐
           tion.  A  relationship  between  -n and the p flag might imply that
           they are only used together, but this ignores  valid  scripts  that
           interrupt  the cyclical nature of the processing through the use of
           the D, d, q, or branching commands. Such scripts rely on the p suf‐
           fix  to write the pattern space because they do not make use of the
           default output at the ``bottom'' of the script.

        *  Because the -n option makes the p flag unnecessary, any interaction
           would  only  be useful if sed scripts were written to run both with
           and without the -n option. This is believed to be unlikely.  It  is
           even more unlikely that programmers have coded the p flag expecting
           it to be unnecessary. Because the interaction was  not  documented,
           the  likelihood of a programmer discovering the interaction and de‐
           pending on it is further decreased.

        *  Finally, scripts that break under the  specified  behavior  produce
           too  much output instead of too little, which is easier to diagnose
           and correct.

       The form of the substitute command that uses the n suffix  was  limited
       to  the first 512 matches in an early proposal. This limit has been re‐
       moved because  there  is  no  reason  an  editor  processing  lines  of
       {LINE_MAX}  length should have this restriction. The command s/a/A/2047
       should be able to substitute the 2047th occurrence of a on a line.

       The b, t, and : commands are documented to ignore leading white  space,
       but  no mention is made of trailing white space. Historical implementa‐
       tions of sed assigned different locations to the labels 'x'  and  "x ".
       This  is  not useful, and leads to subtle programming errors, but it is
       historical practice, and changing it could theoretically break  working
       scripts.  Implementors are encouraged to provide warning messages about
       labels that are never referenced by a b or t command, jumps  to  labels
       that do not exist, and label arguments that are subject to truncation.

       Earlier  versions  of  this  standard  allowed for implementations with
       bytes other than eight bits, but this has been modified  in  this  ver‐
       sion.

FUTURE DIRECTIONS
       None.

SEE ALSO
       awk, ed, grep

       The  Base  Definitions  volume  of  POSIX.1‐2017, Table 5-1, Escape Se‐
       quences and Associated Actions, Chapter 8, Environment Variables,  Sec‐
       tion  9.3,  Basic  Regular  Expressions,  Section  12.2, Utility Syntax
       Guidelines

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

IEEE/The Open Group                  2017                              SED(1P)
