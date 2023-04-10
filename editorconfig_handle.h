editorconfig_handle.h(3)                                                                 Library Functions Manual                                                                 editorconfig_handle.h(3)

NAME
       editorconfig_handle.h - Header file of EditorConfig handle.

SYNOPSIS
   Typedefs
       typedef void * editorconfig_handle
           The editorconfig handle object type.

   Functions
       editorconfig_handle editorconfig_handle_init (void)
           Create and intialize a default editorconfig_handle object.
       int editorconfig_handle_destroy (editorconfig_handle h)
           Destroy an editorconfig_handle object.
       const char * editorconfig_handle_get_err_file (editorconfig_handle h)
           Get the err_file field of an editorconfig_handle object.
       void editorconfig_handle_get_version (const editorconfig_handle h, int *major, int *minor, int *patch)
           Get the version fields of an editorconfig_handle object.
       void editorconfig_handle_set_version (const editorconfig_handle h, int major, int minor, int patch)
           Set the version fields of an editorconfig_handle object.
       void editorconfig_handle_set_conf_file_name (editorconfig_handle h, const char *conf_file_name)
           Set the conf_file_name field of an editorconfig_handle object.
       const char * editorconfig_handle_get_conf_file_name (const editorconfig_handle h)
           Get the conf_file_name field of an editorconfig_handle object.
       void editorconfig_handle_get_name_value (const editorconfig_handle h, int n, const char **name, const char **value)
           Get the nth name and value fields of an editorconfig_handle object.
       int editorconfig_handle_get_name_value_count (const editorconfig_handle h)
           Get the count of name and value fields of an editorconfig_handle object.

Detailed Description
       Header file of EditorConfig handle.

       Author
           EditorConfig Team

Function Documentation
   int editorconfig_handle_destroy (editorconfig_handle h)
       Destroy an editorconfig_handle object.

       Parameters
           h The editorconfig_handle object needs to be destroyed.

       Return values
           zero The editorconfig_handle object is destroyed successfully.
           non-zero Failed to destroy the editorconfig_handle object.

   const char * editorconfig_handle_get_conf_file_name (const editorconfig_handle h)
       Get the conf_file_name field of an editorconfig_handle object.

       Parameters
           h The editorconfig_handle object whose conf_file_name field needs to be obtained.

       Returns
           The value of the conf_file_name field of the editorconfig_handle object.

   const char * editorconfig_handle_get_err_file (editorconfig_handle h)
       Get the err_file field of an editorconfig_handle object.

       Parameters
           h The editorconfig_handle object whose err_file needs to be obtained.

       Return values
           NULL No error file exists.
           non-NULL The pointer to the path of the file caused the parsing error is returned.

   void editorconfig_handle_get_name_value (const editorconfig_handle h, int n, const char ** name, const char ** value)
       Get the nth name and value fields of an editorconfig_handle object.

       Parameters
           h The editorconfig_handle object whose name and value fields need to be obtained.
           n The zero-based index of the name and value fields to be obtained.
           name If not null, *name will be set to point to the obtained name.
           value If not null, *value will be set to point to the obtained value.

       Returns
           None.

   int editorconfig_handle_get_name_value_count (const editorconfig_handle h)
       Get the count of name and value fields of an editorconfig_handle object.

       Parameters
           h The editorconfig_handle object whose count of name and value fields need to be obtained.

       Returns
           the count of name and value fields of the editorconfig_handle object.

   void editorconfig_handle_get_version (const editorconfig_handle h, int * major, int * minor, int * patch)
       Get the version fields of an editorconfig_handle object.

       Parameters
           h The editorconfig_handle object whose version field need to be obtained.
           major If not null, the integer pointed by major will be filled with the major version field of the editorconfig_handle object.
           minor If not null, the integer pointed by minor will be filled with the minor version field of the editorconfig_handle object.
           patch If not null, the integer pointed by patch will be filled with the patch version field of the editorconfig_handle object.

       Returns
           None.

   editorconfig_handle editorconfig_handle_init (void)
       Create and intialize a default editorconfig_handle object.

       Return values
           NULL Failed to create the editorconfig_handle object.
           non-NULL The created editorconfig_handle object is returned.

   void editorconfig_handle_set_conf_file_name (editorconfig_handle h, const char * conf_file_name)
       Set the conf_file_name field of an editorconfig_handle object.

       Parameters
           h The editorconfig_handle object whose conf_file_name field needs to be set.
           conf_file_name The new value of the conf_file_name field of the editorconfig_handle object.

       Returns
           None.

   void editorconfig_handle_set_version (const editorconfig_handle h, int major, int minor, int patch)
       Set the version fields of an editorconfig_handle object.

       Parameters
           h The editorconfig_handle object whose version fields need to be set.
           major If not less than 0, the major version field will be set to major. If this parameter is less than 0, the major version field of the editorconfig_handle object will remain unchanged.
           minor If not less than 0, the minor version field will be set to minor. If this parameter is less than 0, the minor version field of the editorconfig_handle object will remain unchanged.
           patch If not less than 0, the patch version field will be set to patch. If this parameter is less than 0, the patch version field of the editorconfig_handle object will remain unchanged.

       Returns
           None.

Author
       Generated automatically by Doxygen for EditorConfig from the source code.

EditorConfig                                                                                  Thu Jan 19 2023                                                                     editorconfig_handle.h(3)
