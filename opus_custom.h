opus_custom.h(3)                     Opus                     opus_custom.h(3)

NAME
       opus_custom.h - Opus-Custom reference implementation API.

SYNOPSIS
       #include 'opus_defines.h'

   Macros
       #define OPUS_CUSTOM_EXPORT
       #define OPUS_CUSTOM_EXPORT_STATIC

   Typedefs
       typedef struct OpusCustomEncoder OpusCustomEncoder
           Contains the state of an encoder.
       typedef struct OpusCustomDecoder OpusCustomDecoder
           State of the decoder.
       typedef struct OpusCustomMode OpusCustomMode
           The mode contains all the information necessary to create an
           encoder.

   Functions
       OpusCustomMode * opus_custom_mode_create (opus_int32 Fs, int
           frame_size, int *error)
           Creates a new mode struct.
       void opus_custom_mode_destroy (OpusCustomMode *mode)
           Destroys a mode struct.
       int opus_custom_encoder_get_size (const OpusCustomMode *mode, int
           channels)
           Gets the size of an OpusCustomEncoder structure.
       OpusCustomEncoder * opus_custom_encoder_create (const OpusCustomMode
           *mode, int channels, int *error)
           Creates a new encoder state.
       void opus_custom_encoder_destroy (OpusCustomEncoder *st)
           Destroys a an encoder state.
       int opus_custom_encode_float (OpusCustomEncoder *st, const float *pcm,
           int frame_size, unsigned char *compressed, int maxCompressedBytes)
           Encodes a frame of audio.
       int opus_custom_encode (OpusCustomEncoder *st, const opus_int16 *pcm,
           int frame_size, unsigned char *compressed, int maxCompressedBytes)
           Encodes a frame of audio.
       int opus_custom_encoder_ctl (OpusCustomEncoder *OPUS_RESTRICT st, int
           request,...)
           Perform a CTL function on an Opus custom encoder.
       int opus_custom_decoder_get_size (const OpusCustomMode *mode, int
           channels)
           Gets the size of an OpusCustomDecoder structure.
       int opus_custom_decoder_init (OpusCustomDecoder *st, const
           OpusCustomMode *mode, int channels)
           Initializes a previously allocated decoder state The memory pointed
           to by st must be the size returned by opus_custom_decoder_get_size.
       OpusCustomDecoder * opus_custom_decoder_create (const OpusCustomMode
           *mode, int channels, int *error)
           Creates a new decoder state.
       void opus_custom_decoder_destroy (OpusCustomDecoder *st)
           Destroys a an decoder state.
       int opus_custom_decode_float (OpusCustomDecoder *st, const unsigned
           char *data, int len, float *pcm, int frame_size)
           Decode an opus custom frame with floating point output.
       int opus_custom_decode (OpusCustomDecoder *st, const unsigned char
           *data, int len, opus_int16 *pcm, int frame_size)
           Decode an opus custom frame.
       int opus_custom_decoder_ctl (OpusCustomDecoder *OPUS_RESTRICT st, int
           request,...)
           Perform a CTL function on an Opus custom decoder.

Detailed Description
       Opus-Custom reference implementation API.

Macro Definition Documentation
   #define OPUS_CUSTOM_EXPORT
   #define OPUS_CUSTOM_EXPORT_STATIC
Author
       Generated automatically by Doxygen for Opus from the source code.

Version 1.3.1                   Fri Feb 11 2022               opus_custom.h(3)
