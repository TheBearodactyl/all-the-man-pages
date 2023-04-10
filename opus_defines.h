opus_defines.h(3)                    Opus                    opus_defines.h(3)

NAME
       opus_defines.h - Opus reference implementation constants.

SYNOPSIS
       #include 'opus_types.h'

   Macros
       #define OPUS_OK
           No error.
       #define OPUS_BAD_ARG
           One or more invalid/out of range arguments.
       #define OPUS_BUFFER_TOO_SMALL
           Not enough bytes allocated in the buffer.
       #define OPUS_INTERNAL_ERROR
           An internal error was detected.
       #define OPUS_INVALID_PACKET
           The compressed data passed is corrupted.
       #define OPUS_UNIMPLEMENTED
           Invalid/unsupported request number.
       #define OPUS_INVALID_STATE
           An encoder or decoder structure is invalid or already freed.
       #define OPUS_ALLOC_FAIL
           Memory allocation has failed.
       #define OPUS_AUTO
           Auto/default setting.
       #define OPUS_BITRATE_MAX
           Maximum bitrate.
       #define OPUS_APPLICATION_VOIP
           Best for most VoIP/videoconference applications where listening
           quality and intelligibility matter most.
       #define OPUS_APPLICATION_AUDIO
           Best for broadcast/high-fidelity application where the decoded
           audio should be as close as possible to the input.
       #define OPUS_APPLICATION_RESTRICTED_LOWDELAY
           Only use when lowest-achievable latency is what matters most.
       #define OPUS_SIGNAL_VOICE   3001
           Signal being encoded is voice.
       #define OPUS_SIGNAL_MUSIC   3002
           Signal being encoded is music.
       #define OPUS_BANDWIDTH_NARROWBAND
           4 kHz bandpass
       #define OPUS_BANDWIDTH_MEDIUMBAND
           6 kHz bandpass
       #define OPUS_BANDWIDTH_WIDEBAND
           8 kHz bandpass
       #define OPUS_BANDWIDTH_SUPERWIDEBAND
           12 kHz bandpass
       #define OPUS_BANDWIDTH_FULLBAND
           20 kHz bandpass
       #define OPUS_FRAMESIZE_ARG   5000
           Select frame size from the argument (default)
       #define OPUS_FRAMESIZE_2_5_MS   5001
           Use 2.5 ms frames.
       #define OPUS_FRAMESIZE_5_MS   5002
           Use 5 ms frames.
       #define OPUS_FRAMESIZE_10_MS   5003
           Use 10 ms frames.
       #define OPUS_FRAMESIZE_20_MS   5004
           Use 20 ms frames.
       #define OPUS_FRAMESIZE_40_MS   5005
           Use 40 ms frames.
       #define OPUS_FRAMESIZE_60_MS   5006
           Use 60 ms frames.
       #define OPUS_FRAMESIZE_80_MS   5007
           Use 80 ms frames.
       #define OPUS_FRAMESIZE_100_MS   5008
           Use 100 ms frames.
       #define OPUS_FRAMESIZE_120_MS   5009
           Use 120 ms frames.
       #define OPUS_SET_COMPLEXITY(x)
           Configures the encoder's computational complexity.
       #define OPUS_GET_COMPLEXITY(x)
           Gets the encoder's complexity configuration.
       #define OPUS_SET_BITRATE(x)
           Configures the bitrate in the encoder.
       #define OPUS_GET_BITRATE(x)
           Gets the encoder's bitrate configuration.
       #define OPUS_SET_VBR(x)
           Enables or disables variable bitrate (VBR) in the encoder.
       #define OPUS_GET_VBR(x)
           Determine if variable bitrate (VBR) is enabled in the encoder.
       #define OPUS_SET_VBR_CONSTRAINT(x)
           Enables or disables constrained VBR in the encoder.
       #define OPUS_GET_VBR_CONSTRAINT(x)
           Determine if constrained VBR is enabled in the encoder.
       #define OPUS_SET_FORCE_CHANNELS(x)
           Configures mono/stereo forcing in the encoder.
       #define OPUS_GET_FORCE_CHANNELS(x)
           Gets the encoder's forced channel configuration.
       #define OPUS_SET_MAX_BANDWIDTH(x)
           Configures the maximum bandpass that the encoder will select
           automatically.
       #define OPUS_GET_MAX_BANDWIDTH(x)
           Gets the encoder's configured maximum allowed bandpass.
       #define OPUS_SET_BANDWIDTH(x)
           Sets the encoder's bandpass to a specific value.
       #define OPUS_SET_SIGNAL(x)
           Configures the type of signal being encoded.
       #define OPUS_GET_SIGNAL(x)
           Gets the encoder's configured signal type.
       #define OPUS_SET_APPLICATION(x)
           Configures the encoder's intended application.
       #define OPUS_GET_APPLICATION(x)
           Gets the encoder's configured application.
       #define OPUS_GET_LOOKAHEAD(x)
           Gets the total samples of delay added by the entire codec.
       #define OPUS_SET_INBAND_FEC(x)
           Configures the encoder's use of inband forward error correction
           (FEC).
       #define OPUS_GET_INBAND_FEC(x)
           Gets encoder's configured use of inband forward error correction.
       #define OPUS_SET_PACKET_LOSS_PERC(x)
           Configures the encoder's expected packet loss percentage.
       #define OPUS_GET_PACKET_LOSS_PERC(x)
           Gets the encoder's configured packet loss percentage.
       #define OPUS_SET_DTX(x)
           Configures the encoder's use of discontinuous transmission (DTX).
       #define OPUS_GET_DTX(x)
           Gets encoder's configured use of discontinuous transmission.
       #define OPUS_SET_LSB_DEPTH(x)
           Configures the depth of signal being encoded.
       #define OPUS_GET_LSB_DEPTH(x)
           Gets the encoder's configured signal depth.
       #define OPUS_SET_EXPERT_FRAME_DURATION(x)
           Configures the encoder's use of variable duration frames.
       #define OPUS_GET_EXPERT_FRAME_DURATION(x)
           Gets the encoder's configured use of variable duration frames.
       #define OPUS_SET_PREDICTION_DISABLED(x)
           If set to 1, disables almost all use of prediction, making frames
           almost completely independent.
       #define OPUS_GET_PREDICTION_DISABLED(x)
           Gets the encoder's configured prediction status.
       #define OPUS_RESET_STATE
           Resets the codec state to be equivalent to a freshly initialized
           state.
       #define OPUS_GET_FINAL_RANGE(x)
           Gets the final state of the codec's entropy coder.
       #define OPUS_GET_BANDWIDTH(x)
           Gets the encoder's configured bandpass or the decoder's last
           bandpass.
       #define OPUS_GET_SAMPLE_RATE(x)
           Gets the sampling rate the encoder or decoder was initialized with.
       #define OPUS_SET_PHASE_INVERSION_DISABLED(x)
           If set to 1, disables the use of phase inversion for intensity
           stereo, improving the quality of mono downmixes, but slightly
           reducing normal stereo quality.
       #define OPUS_GET_PHASE_INVERSION_DISABLED(x)
           Gets the encoder's configured phase inversion status.
       #define OPUS_GET_IN_DTX(x)
           Gets the DTX state of the encoder.
       #define OPUS_SET_GAIN(x)
           Configures decoder gain adjustment.
       #define OPUS_GET_GAIN(x)
           Gets the decoder's configured gain adjustment.
       #define OPUS_GET_LAST_PACKET_DURATION(x)
           Gets the duration (in samples) of the last packet successfully
           decoded or concealed.
       #define OPUS_GET_PITCH(x)
           Gets the pitch of the last decoded frame, if available.

   Functions
       const char * opus_strerror (int error)
           Converts an opus error code into a human readable string.
       const char * opus_get_version_string (void)
           Gets the libopus version string.

Detailed Description
       Opus reference implementation constants.

Author
       Generated automatically by Doxygen for Opus from the source code.

Version 1.3.1                   Fri Feb 11 2022              opus_defines.h(3)
