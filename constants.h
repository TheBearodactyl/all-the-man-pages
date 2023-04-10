constants.h(3)                                                                           Library Functions Manual                                                                           constants.h(3)

NAME
       constants.h - Common constants used in decoder and encoder API.

SYNOPSIS
   Macros
       #define BROTLI_LARGE_MAX_DISTANCE_BITS   62U
           The theoretical maximum number of distance bits specified for large window brotli, for 64-bit encoders and decoders.
       #define BROTLI_LARGE_MAX_WBITS   30
           The maximum supported large brotli window bits by the encoder and decoder.
       #define BROTLI_MAX_NPOSTFIX   3
           Maximal number of 'postfix' bits.

Detailed Description
       Common constants used in decoder and encoder API.

Macro Definition Documentation
   #define BROTLI_LARGE_MAX_DISTANCE_BITS   62U
       The theoretical maximum number of distance bits specified for large window brotli, for 64-bit encoders and decoders. Even when in practice 32-bit encoders and decoders only support up to 30 max
       distance bits, the value is set to 62 because it affects the large window brotli file format. Specifically, it affects the encoding of simple huffman tree for distances, see Specification RFC
       7932 chapter 3.4.

   #define BROTLI_LARGE_MAX_WBITS   30
       The maximum supported large brotli window bits by the encoder and decoder. Large window brotli allows up to 62 bits, however the current encoder and decoder, designed for 32-bit integers, only
       support up to 30 bits maximum.

   #define BROTLI_MAX_NPOSTFIX   3
       Maximal number of 'postfix' bits. Number of 'postfix' bits is stored as 2 bits in meta-block header.

Author
       Generated automatically by Doxygen for Brotli from the source code.

Brotli                                                                                        Wed May 13 2020                                                                               constants.h(3)
