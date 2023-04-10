types.h(3)                                                                               Library Functions Manual                                                                               types.h(3)

NAME
       types.h - Common types used in decoder and encoder API.

SYNOPSIS
   Macros
       #define BROTLI_BOOL   int
           A portable bool replacement.
       #define BROTLI_FALSE   0
           Portable false replacement.
       #define BROTLI_TRUE   1
           Portable true replacement.
       #define TO_BROTLI_BOOL(X)   (!!(X) ? BROTLI_TRUE : BROTLI_FALSE)
           bool to BROTLI_BOOL conversion macros.

   Typedefs
       typedef void *(* brotli_alloc_func) (void *opaque, size_t size)
           Allocating function pointer type.
       typedef void(* brotli_free_func) (void *opaque, void *address)
           Deallocating function pointer type.

Detailed Description
       Common types used in decoder and encoder API.

Macro Definition Documentation
   #define BROTLI_BOOL   int
       A portable bool replacement. BROTLI_BOOL is a 'documentation' type: actually it is int, but in API it denotes a type, whose only values are BROTLI_TRUE and BROTLI_FALSE.

       BROTLI_BOOL values passed to Brotli should either be BROTLI_TRUE or BROTLI_FALSE, or be a result of TO_BROTLI_BOOL macros.

       BROTLI_BOOL values returned by Brotli should not be tested for equality with true, false, BROTLI_TRUE, BROTLI_FALSE, but rather should be evaluated, for example:

       if (SomeBrotliFunction(encoder, BROTLI_TRUE) &&
           !OtherBrotliFunction(decoder, BROTLI_FALSE)) {
         bool x = !!YetAnotherBrotliFunction(encoder, TO_BROLTI_BOOL(2 * 2 == 4));
         DoSomething(x);
       }

   #define BROTLI_FALSE   0
       Portable false replacement.

   #define BROTLI_TRUE   1
       Portable true replacement.

   #define TO_BROTLI_BOOL(X)   (!!(X) ? BROTLI_TRUE : BROTLI_FALSE)
       bool to BROTLI_BOOL conversion macros.

Typedef Documentation
   typedef void*(* brotli_alloc_func) (void *opaque, size_t size)
       Allocating function pointer type.

       Parameters:
           opaque custom memory manager handle provided by client
           size requested memory region size; can not be 0

       Returns:
           0 in the case of failure

           a valid pointer to a memory region of at least size bytes long otherwise

   typedef void(* brotli_free_func) (void *opaque, void *address)
       Deallocating function pointer type. This function SHOULD do nothing if address is 0.

       Parameters:
           opaque custom memory manager handle provided by client
           address memory region pointer returned by brotli_alloc_func, or 0

Author
       Generated automatically by Doxygen for Brotli from the source code.

Brotli                                                                                        Thu Feb 22 2018                                                                                   types.h(3)
