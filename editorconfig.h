editorconfig.h(3)                                                                        Library Functions Manual                                                                        editorconfig.h(3)

NAME
       editorconfig.h - Header file of EditorConfig.

SYNOPSIS
       #include <editorconfig/editorconfig_handle.h>

   Macros
       #define EDITORCONFIG_PARSE_NOT_FULL_PATH   (-2)
       #define EDITORCONFIG_PARSE_MEMORY_ERROR   (-3)
       #define EDITORCONFIG_PARSE_VERSION_TOO_NEW   (-4)

   Functions
       int editorconfig_parse (const char *full_filename, editorconfig_handle h)
           Parse editorconfig files corresponding to the file path given by full_filename, and related information is input and output in h.
       const char * editorconfig_get_error_msg (int err_num)
           Get the error message from the error number returned by editorconfig_parse().
       void editorconfig_get_version (int *major, int *minor, int *patch)
           Get the version number of EditorConfig.
       const char * editorconfig_get_version_suffix (void)
           Get the version suffix.

Detailed Description
       Header file of EditorConfig.

       Related page: EditorConfig File Format editorconfig-format(5)

       Author
           EditorConfig Team

Macro Definition Documentation
   #define EDITORCONFIG_PARSE_MEMORY_ERROR   (-3)
       editorconfig_parse() return value: a memory error occurs.

   #define EDITORCONFIG_PARSE_NOT_FULL_PATH   (-2)
       editorconfig_parse() return value: the full_filename parameter of editorconfig_parse() is not a full path name

   #define EDITORCONFIG_PARSE_VERSION_TOO_NEW   (-4)
       editorconfig_parse() return value: the required version specified in editorconfig_handle is greater than the current version.

Function Documentation
   const char * editorconfig_get_error_msg (int err_num)
       Get the error message from the error number returned by editorconfig_parse(). An example is available at src/bin/main.c in EditorConfig C Core source code.

       Parameters
           err_num The error number that is used to obtain the error message.

       Returns
           The error message corresponding to err_num.

   void editorconfig_get_version (int * major, int * minor, int * patch)
       Get the version number of EditorConfig. An example is available at src/bin/main.c in EditorConfig C Core source code.

       Parameters
           major If not null, the integer pointed by major will be filled with the major version of EditorConfig.
           minor If not null, the integer pointed by minor will be filled with the minor version of EditorConfig.
           patch If not null, the integer pointed by patch will be filled with the patch version of EditorConfig.

       Returns
           None.

   const char * editorconfig_get_version_suffix (void)
       Get the version suffix.

       Returns
           The version suffix, such as '-development' for a development version, empty string for a stable version.

   int editorconfig_parse (const char * full_filename, editorconfig_handle h)
       Parse editorconfig files corresponding to the file path given by full_filename, and related information is input and output in h. An example is available at src/bin/main.c in EditorConfig C Core
       source code.

       Parameters
           full_filename The full path of a file that is edited by the editor for which the parsing result is.
           h The editorconfig_handle to be used and returned from this function (including the parsing result). The editorconfig_handle should be created by editorconfig_handle_init().

       Return values
           0 Everything is OK.
           Positive Integer A parsing error occurs. The return value would be the line number of parsing error. err_file obtained from h by calling editorconfig_handle_get_err_file() will also be filled
           with the file path that caused the parsing error.
           Negative Integer Some error occured. See below for the reason of the error for each return value.
           EDITORCONFIG_PARSE_NOT_FULL_PATH The full_filename is not a full path name.
           EDITORCONFIG_PARSE_MEMORY_ERROR A memory error occurs.
           EDITORCONFIG_PARSE_VERSION_TOO_NEW The required version specified in editorconfig_handle is greater than the current version.

Author
       Generated automatically by Doxygen for EditorConfig from the source code.

EditorConfig                                                                                  Thu Jan 19 2023                                                                            editorconfig.h(3)
