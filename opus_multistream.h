opus_multistream.h(3)                Opus                opus_multistream.h(3)

NAME
       opus_multistream.h - Opus reference implementation multistream API.

SYNOPSIS
       #include 'opus.h'

   Macros
       #define OPUS_MULTISTREAM_GET_ENCODER_STATE(x,  y)
           Gets the encoder state for an individual stream of a multistream
           encoder.
       #define OPUS_MULTISTREAM_GET_DECODER_STATE(x,  y)
           Gets the decoder state for an individual stream of a multistream
           decoder.

   Typedefs
       typedef struct OpusMSEncoder OpusMSEncoder
           Opus multistream encoder state.
       typedef struct OpusMSDecoder OpusMSDecoder
           Opus multistream decoder state.

   Functions
       Multistream encoder functions

           opus_int32 opus_multistream_encoder_get_size (int streams, int
               coupled_streams)
               Gets the size of an OpusMSEncoder structure.
           opus_int32 opus_multistream_surround_encoder_get_size (int
               channels, int mapping_family)
           OpusMSEncoder * opus_multistream_encoder_create (opus_int32 Fs, int
               channels, int streams, int coupled_streams, const unsigned char
               *mapping, int application, int *error)
               Allocates and initializes a multistream encoder state.
           OpusMSEncoder * opus_multistream_surround_encoder_create
               (opus_int32 Fs, int channels, int mapping_family, int *streams,
               int *coupled_streams, unsigned char *mapping, int application,
               int *error)
           int opus_multistream_encoder_init (OpusMSEncoder *st, opus_int32
               Fs, int channels, int streams, int coupled_streams, const
               unsigned char *mapping, int application)
               Initialize a previously allocated multistream encoder state.
           int opus_multistream_surround_encoder_init (OpusMSEncoder *st,
               opus_int32 Fs, int channels, int mapping_family, int *streams,
               int *coupled_streams, unsigned char *mapping, int application)
           int opus_multistream_encode (OpusMSEncoder *st, const opus_int16
               *pcm, int frame_size, unsigned char *data, opus_int32
               max_data_bytes)
               Encodes a multistream Opus frame.
           int opus_multistream_encode_float (OpusMSEncoder *st, const float
               *pcm, int frame_size, unsigned char *data, opus_int32
               max_data_bytes)
               Encodes a multistream Opus frame from floating point input.
           void opus_multistream_encoder_destroy (OpusMSEncoder *st)
               Frees an OpusMSEncoder allocated by
               opus_multistream_encoder_create().
           int opus_multistream_encoder_ctl (OpusMSEncoder *st, int
               request,...)
               Perform a CTL function on a multistream Opus encoder.

       Multistream decoder functions

           opus_int32 opus_multistream_decoder_get_size (int streams, int
               coupled_streams)
               Gets the size of an OpusMSDecoder structure.
           OpusMSDecoder * opus_multistream_decoder_create (opus_int32 Fs, int
               channels, int streams, int coupled_streams, const unsigned char
               *mapping, int *error)
               Allocates and initializes a multistream decoder state.
           int opus_multistream_decoder_init (OpusMSDecoder *st, opus_int32
               Fs, int channels, int streams, int coupled_streams, const
               unsigned char *mapping)
               Intialize a previously allocated decoder state object.
           int opus_multistream_decode (OpusMSDecoder *st, const unsigned char
               *data, opus_int32 len, opus_int16 *pcm, int frame_size, int
               decode_fec)
               Decode a multistream Opus packet.
           int opus_multistream_decode_float (OpusMSDecoder *st, const
               unsigned char *data, opus_int32 len, float *pcm, int
               frame_size, int decode_fec)
               Decode a multistream Opus packet with floating point output.
           int opus_multistream_decoder_ctl (OpusMSDecoder *st, int
               request,...)
               Perform a CTL function on a multistream Opus decoder.
           void opus_multistream_decoder_destroy (OpusMSDecoder *st)
               Frees an OpusMSDecoder allocated by
               opus_multistream_decoder_create().

Detailed Description
       Opus reference implementation multistream API.

Author
       Generated automatically by Doxygen for Opus from the source code.

Version 1.3.1                   Fri Feb 11 2022          opus_multistream.h(3)
