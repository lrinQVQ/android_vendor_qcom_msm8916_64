/*============================================================================
  @file SwVdecTypes.h
  This file defines the types for Software Video Decoder modules.

  Copyright (c) 2013-2014 Qualcomm Technologies, Inc.  All Rights Reserved.
  Qualcomm Technologies Proprietary and Confidential.
============================================================================*/

/*============================================================================
  EDIT HISTORY FOR MODULE

  $Header: //source/qcom/qct/multimedia2/Video/HEVC_SoftwareCodec2/SwVdec/api/SwVdecTypes.h#6 $
  $DateTime: 2013/09/27 14:15:35 $
  $Change: 4508992 $
  $Author: jeehongy $

  when        who  what, where, why
  ----------  ---  -----------------------------------------------------------
  2013-03-06  kv   Initial version.

============================================================================*/

#ifndef _SWVDEC_TYPES_H
#define _SWVDEC_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/*==== DECODER - PROFILE ENUMERATIONS ======================================*/

/**<
 * List of HEVC Profiles supported
 */
typedef enum
{
    SWVDEC_HEVC_MAIN_PROFILE    = 0,  /** HEVC Main profile */
} SWVDEC_HEVC_PROFILE;


/*==== DECODER - LEVEL ENUMERATIONS ========================================*/
/**<
 * Level Enumeration for HEVC
 */
typedef enum
{
    SWVDEC_HEVC_LEVEL_UNKNOWN   = 0,  /**< Unknown Level       */
    SWVDEC_HEVC_LEVEL_3_1       = 2,  /**< HEVC Level 1       */
} SWVDEC_HEVC_LEVEL;


/*==== GENERIC CODEC ENUMERATIONS ==================================================*/
/**<
 * Buffer Flag definition.
 *
 * Flags have specific values such that a particular buffer can take more than one flag.
 */
#define SWVDEC_FLAG_EOS             0x00000001  /**< IP/OP - EOS flag */
#define SWVDEC_FLAG_DECODEONLY      0x00000002  /**<    OP - A component that renders the buffer shall
                                                             ignore all buffers with DECODEONLY flag */
#define SWVDEC_FLAG_INPUT_CONSUMED  0x00000004  /**<    IP - Input buffer/frame consumed */
#define SWVDEC_FLAG_DECODED_FRAME   0x00000008  /**<    OP - Normal decoded frame */
#define SWVDEC_FLAG_FLUSHED         0x00000010  /**< IP/OP - Buffer/Frame flushed */
#define SWVDEC_FLAG_READONLY        0x00000200  /**<    OP - In dynamic buffer mode, indicates the buffer
                                                             is used for reference and still required by
                                                             SWVDEC and client can use it as a read only buffer */

/**<
 * Enumerations for error status
 */
typedef enum {
    SWVDEC_S_SUCCESS,                   /**< Success */
    SWVDEC_S_EFAIL,                     /**< General failure */
    SWVDEC_S_EBADPARAM,                 /**< bad parameters */
    SWVDEC_S_EINVALSTATE,               /**< called at invalid state */
    SWVDEC_S_ENOSWRES,                  /**< Insufficient SW resources, memory, thread... */
    SWVDEC_S_EUNSUPPORTED,              /**< unsupported feature */
    SWVDEC_S_EUNSUPPORTEDCOLORFORMAT,   /**< unsupported color format */
    SWVDEC_S_EDUPLICATE,                /**< duplicate output buffer setting */
    SWVDEC_S_ENOTIMPLEMENTED            /**< the API is not implemented yet */
} SWVDEC_STATUS;

/**<
 * Enumerations for Decoder mode of operation
 */
typedef enum {
    SWVDEC_MODE_PARSE_DECODE,           /**< Both parser and decode enabled */
    SWVDEC_MODE_PARSE_ONLY,             /**< Only parser enabled no decoder a.k.a worker  */
    SWVDEC_MODE_DECODE_ONLY,            /**< Only worker enabled no parser enabled */
} SWVDEC_MODE_TYPE;

/**<
 * Macro for printing enumerations for Decoder mode of operation
 */
#define SWVDEC_MODE_TYPE_STRING(x) ((x == SWVDEC_MODE_PARSE_DECODE) ?   \
                                    "SWVDEC_MODE_PARSE_DECODE" :        \
                                    ((x == SWVDEC_MODE_PARSE_ONLY) ?    \
                                     "SWVDEC_MODE_PARSE_ONLY" :         \
                                     ((x == SWVDEC_MODE_DECODE_ONLY) ?  \
                                      "SWVDEC_MODE_DECODE_ONLY" :       \
                                      "unknown mode")))

/**<
 * Decoder type enumeration.
 */
typedef enum
{
    SWVDEC_DECODER_HEVC,                /**< HEVC decoder */
} SWVDEC_DECODER_TYPE;

/**<
 * Macro for printing Decoder type enumeration.
 */
#define SWVDEC_DECODER_TYPE_STRING(x) ((x == SWVDEC_DECODER_HEVC) ? \
                                       "SWVDEC_DECODER_HEVC" :      \
                                       "unknown decoder")

/**<
 * Decoder output color format type enumeration.
 */
typedef enum
{
    SWVDEC_FORMAT_UNDEF,                /**< Undefined Color Format */
    SWVDEC_FORMAT_YV12,                 /**< YV12 Planar format */
    SWVDEC_FORMAT_YV21,                 /**< YV21 Planar format */
    SWVDEC_FORMAT_NV12,                 /**< NV12 Interleaved format */
    SWVDEC_FORMAT_NV21,                 /**< NV21 Interleaved format */
    /**< more... TBD */
} SWVDEC_COLOR_FORMAT_TYPE;

/**<
 * Macro for printing Decoder output color format type enumeration.
 */
#define SWVDEC_COLOR_FORMAT_TYPE_STRING(x) ((x == SWVDEC_FORMAT_UNDEF) ?    \
                                            "SWVDEC_FORMAT_UNDEF" :         \
                                            ((x == SWVDEC_FORMAT_YV12) ?    \
                                             "SWVDEC_FORMAT_YV12" :         \
                                             ((x == SWVDEC_FORMAT_YV21) ?   \
                                              "SWVDEC_FORMAT_YV21" :        \
                                              ((x == SWVDEC_FORMAT_NV12) ?  \
                                               "SWVDEC_FORMAT_NV12" :       \
                                               ((x == SWVDEC_FORMAT_NV21) ? \
                                                "SWVDEC_FORMAT_NV21" :      \
                                                "unknown color format")))))

/**<
 * Property IDs
 */
typedef enum
{
    SWVDEC_PROP_ID_DIMENSIONS,        /**< Clip dimensions */
    SWVDEC_PROP_ID_IPBUFFREQ,         /**< Input Buffer requirements  */
    SWVDEC_PROP_ID_OPBUFFREQ,         /**< Output Buffer requirements */
    SWVDEC_PROP_ID_FRAME_ATTR,        /**< Output Frame Attributes */
    SWVDEC_PROP_ID_MODE,              /**< Out put  */
    SWVDEC_PROP_ID_BUFFER_ALLOC_MODE, /**< dynamic or static */
    SWVDEC_PROP_ID_SMOOTH_STREAMING   /**< smooth streaming mode */
} SWVDEC_PROP_ID;

#define SWVDEC_PROP_ID_STRING(x) ((x == SWVDEC_PROP_ID_DIMENSIONS) ?                  \
                                  "SWVDEC_PROP_ID_DIMENSIONS" :                       \
                                  ((x == SWVDEC_PROP_ID_IPBUFFREQ) ?                  \
                                   "SWVDEC_PROP_ID_IPBUFFREQ" :                       \
                                   ((x == SWVDEC_PROP_ID_OPBUFFREQ) ?                 \
                                    "SWVDEC_PROP_ID_OPBUFFREQ" :                      \
                                    ((x == SWVDEC_PROP_ID_FRAME_ATTR) ?               \
                                     "SWVDEC_PROP_ID_FRAME_ATTR" :                    \
                                     ((x == SWVDEC_PROP_ID_MODE) ?                    \
                                      "SWVDEC_PROP_ID_MODE" :                         \
                                      ((x == SWVDEC_PROP_ID_BUFFER_ALLOC_MODE) ?      \
                                       "SWVDEC_PROP_ID_BUFFER_ALLOC_MODE" :           \
                                       ((x == SWVDEC_PROP_ID_SMOOTH_STREAMING) ? \
                                        "SWVDEC_PROP_ID_SMOOTH_STREAMING" :      \
                                        "unknown prop id")))))))

typedef enum
{
    SWVDEC_BUF_ALLOC_MODE_STATIC,    /**< static buffer allocation, pBuffer is always the same and valid */
    SWVDEC_BUF_ALLOC_MODE_DYNAMIC,   /**< dynamic buffer allocation, pBuffer will change from call to call */
} SWVDEC_BUFFER_ALLOC_MODE;

#define SWVDEC_BUFFER_ALLOC_MODE_STRING(x) ((x == SWVDEC_BUF_ALLOC_MODE_STATIC) ?   \
                                            "SWVDEC_BUF_ALLOC_MODE_STATIC" :        \
                                            ((x == SWVDEC_BUF_ALLOC_MODE_DYNAMIC) ? \
                                             "SWVDEC_BUF_ALLOC_MODE_DYNAMIC" :      \
                                             "unknown buffer alloc mode"))

/**
 *  Introduced for the purpose of dynamic output buffer. Keeps track of whether this buffer
 *  is owned by client or the codec.
 */
typedef enum
{
    SWVDEC_BUF_OWNER_CLIENT,    /**< Buffer is owned by the client */
    SWVDEC_BUF_OWNER_CODEC,     /**< Buffer is owned by the codec */
} SWVDEC_BUFFER_OWNER_TYPE;

/**
 *  The type of flush. This is a bit mask where ALL is bitmask
 *  of input and output.
 */
typedef enum
{
    SWVDEC_FLUSH_OUTPUT = 1,
    SWVDEC_FLUSH_ALL = 2
} SWVDEC_BUFFER_FLUSH_TYPE;

/**
 * Macro for printing flush type enumeration.
 */
#define SWVDEC_BUFFER_FLUSH_TYPE_STRING(x) ((x == SWVDEC_FLUSH_OUTPUT) ? \
                                            "SWVDEC_FLUSH_OUTPUT" :      \
                                            ((x == SWVDEC_FLUSH_ALL) ?   \
                                             "SWVDEC_FLUSH_ALL" :        \
                                             "unknown flush type"))

/**
 *  The type of event.
 */
typedef enum
{
    SWVDEC_FLUSH_DONE,
    SWVDEC_RECONFIG_SUFFICIENT_RESOURCES,
    SWVDEC_RECONFIG_INSUFFICIENT_RESOURCES,
    SWVDEC_ERROR,
    SWVDEC_RELEASE_BUFFER_REFERENCE,
}
SWVDEC_EVENT;

/**<
 * Structure for Dimensions property
 */
typedef struct {
    SWVDEC_MODE_TYPE eMode;  /**< Decoder Mode of operation */
} SWVDEC_PROP_MODE;

/**<
 * Structure for input/utput buffer requirements property
 */
typedef struct {
    unsigned long int   nSize;          /**< Size of the buffer required */
    unsigned long int   nMinCount;      /**< Minimum number of buffers needed */
    unsigned long int   nMaxCount;      /**< Maximum number of buffers needed */
    unsigned long int   nAlignment;     /**< Alignment requirements */
#ifdef _WIN32
    unsigned long int nStride;
    unsigned long int nChromaOffset;      ///> Offset to the start of chroma plane from start of frame ptr
#endif
} SWVDEC_PROP_BUFF_REQ;

/**<
 * Structure for Dimensions property
 */
typedef struct {
    unsigned long int   nWidth;         /**< Frame Width */
    unsigned long int   nHeight;        /**< Frame Height */
} SWVDEC_PROP_DIMENSIONS;


/**<
 * Define the planes for YUV packed formats.
 * e.g. YVYU, UYVY, RGB, etc
 */
typedef struct {
    unsigned long int     nOffset;       /**< Data offset  */
    unsigned long int     nStride;       /**< Stride of a scan line in bytes */
} SWVDEC_COLOR_FORMAT_PACKED;

/**<
 * Define the planes for YUV packed formats.
 * e.g. NV12, NV21, samsung tile, etc
 */
typedef struct {
    unsigned long int     nLumaOffset;   /**< Luma data offset  */
    unsigned long int     nLumaStride;   /**< Stride of a scan line in bytes for luma*/

    unsigned long int     nChromaOffset; /**< Chroma data offset  */
    unsigned long int     nChromaStride; /**< Stride of a scan line in bytes for chroma*/
} SWVDEC_COLOR_FORMAT_INTERLEAVED;

/**<
 * Define the planes for YUV packed formats.
 * e.g. YV12, YV21, etc
 */
typedef struct {
    unsigned long int     nLumaOffset;       /**< Luma data offset  */
    unsigned long int     nLumaStride;       /**< Stride of a scan line in bytes for luma*/
    unsigned long int     nChromaBlueOffset; /**< Chroma data offset  */
    unsigned long int     nChromaBlueStride; /**< Stride of a scan line in bytes for chroma blue*/
    unsigned long int     nChromaRedOffset;  /**< Chroma data offset  */
    unsigned long int     nChromaRedStride;  /**< Stride of a scan line in bytes for chroma red*/
} SWVDEC_COLOR_FORMAT_PLANAR;

/**<
 * Structure for Dimensions property
 */
typedef struct {
    SWVDEC_COLOR_FORMAT_TYPE              eColorFormat;     /**< Color Format */
    union {
        SWVDEC_COLOR_FORMAT_PACKED        sPacked;          /**< YUV packed plane */
        SWVDEC_COLOR_FORMAT_INTERLEAVED   sInterleaved;     /**< YUV interleaved (psuedo planar) planes */
        SWVDEC_COLOR_FORMAT_PLANAR        sPlanar;          /**< YUV planar planes */
    } uFormats;                                             /**< uFormats can not be set using SwVdec_SetProperty */
} SWVDEC_PROP_FRAME_ATTR;

typedef struct {
    SWVDEC_BUFFER_ALLOC_MODE eBufAllocMode;
} SWVDEC_PROP_BUF_ALLOC_MODE;

typedef struct {
    unsigned int bEnableSmoothStreaming; /**< smooth streaming enable/disable flag */
} SWVDEC_PROP_SMOOTH_STREAMING;

/**<
 * Common struct for all properties
 */
typedef struct {
    SWVDEC_PROP_ID                   ePropId;          /**< Property Id */
    union {
        SWVDEC_PROP_MODE             sMode;            /**< Codec Mode */
        SWVDEC_PROP_DIMENSIONS       sDimensions;      /**< Clip dimensions */
        SWVDEC_PROP_BUFF_REQ         sIpBuffReq;       /**< Input Buffer Requirements */
        SWVDEC_PROP_BUFF_REQ         sOpBuffReq;       /**< Output Buffer Requirements */
        SWVDEC_PROP_FRAME_ATTR       sFrameAttr;       /**< Frame Attributes - Color format, stride(s), offset(s) */
        SWVDEC_PROP_BUF_ALLOC_MODE   sBufAllocMode;    /**< Static or Dynamic mode. Assumes, we are referring to Output buffer */
        SWVDEC_PROP_SMOOTH_STREAMING sSmoothStreaming; /**< Smooth Streaming mode */
    } uProperty;
} SWVDEC_PROP;


/**<
 * Input params for Initialization of Software Decoder library
 */
typedef struct {
    SWVDEC_DECODER_TYPE          eDecType;                 /**< Type of Decoder to be used */
    SWVDEC_PROP_MODE             sMode;                    /**< Codec Mode */
    SWVDEC_PROP_DIMENSIONS       sDimensions;              /**< Dimensions of clip being decoded */
    union {
        SWVDEC_HEVC_PROFILE      eHevcProfile;             /**< H265 profile */
    } uProfile;
    union {
        SWVDEC_HEVC_LEVEL        eHevcLevel;               /**< H264 level */
    } uLevel;
    unsigned long int            nAverageBitrate;          /**< Average Bitrate */
    unsigned long int            nPeakBitRate;             /**< Peak Bitrate */
    SWVDEC_COLOR_FORMAT_TYPE     eColorFormat;             /**< Color format in which the Decoder should generate the output */
    unsigned char               *pSequenceHeader;          /**< Sequence Header. If NULL, it will be ignored */
    unsigned long int            nSequenceHeaderLen;       /**< Sequence Header length. It will be ignored if pSequenceHeader is NULL */
} SWVDEC_INITPARAMS;


/**<
* structure representing an input frame
*/
#define MAX_NALUS 40 /* maximum number of NAL Units per frame */
typedef struct {
    unsigned char*       pBuffer;                       /**< Ptr to Input Buffer */
    unsigned long int    nSize;                         /**< Allocated Size of IP Buffer */
    unsigned long int    nFilledLen;                    /**< Filled Size of Input Buffer */
    unsigned long int    nFlags;                        /**< buffer flag, EOS, etc. Passed from input to output */
    unsigned long long   nIpTimestamp;                  /**< Timestamp, passed from input to output */
    void*                pClientFrameData;              /**< Client Frame Data ptr - passed from input to output */
    void*                pClientBufferData;             /**< Client Buffer Data ptr - NOT passed, identifies this buffer */
    unsigned int         anNalUnitLocation[MAX_NALUS+1];/**< Location of NAL Units */
    unsigned int         nNumNalUnits;                  /**< Number of NAL Units */
} SWVDEC_IPBUFFER;

/**<
* structure representing an output frame
*/
typedef struct {
    unsigned char*       pBuffer;                       /**< Ouput Buffer Ptr */
    unsigned long int    nSize;                         /**< Allocated Size of OP Buffer */
    unsigned long int    nFilledLen;                    /**< Filled Size of OP Buffer */
    unsigned long int    nWidth;                        /**< Width  of picture in OP Buffer */
    unsigned long int    nHeight;                       /**< Height of picture in OP Buffer */
    unsigned long int    nFlags;                        /**< buffer flag, EOS, etc. Passed from input to output */
    unsigned long long   nOpTimestamp;                  /**< Timestamp, passed from input to output */
    void*                pClientFrameData;              /**< Client Frame Data ptr - passed from input to output */
    void*                pClientBufferData;             /**< Client Buffer Data ptr - NOT passed, identifies this buffer */
} SWVDEC_OPBUFFER;

/**<
* structure representing an event
*/
typedef struct {
    SWVDEC_EVENT eEvent;                        /**< Event that need to be notified to client */
    void*        pEventData;                    /**< Extra data specific to the event */
} SWVDEC_EVENTHANDLER;

/**<
 * Software Deocder object handle
 */
struct SwDecHandle;
typedef struct SwDecHandle* SWVDEC_HANDLE;

/**<
 * Callback functions provided by Client to SW Decoder Library
 */
typedef struct SWVDEC_CALLBACK {
    /**
    * This callback function for the sw decoder module to notify a
    * client that a decoded frame is ready for rendering. After
    * flush this is also used to return the buffers back
    *
    *  @param[out] pSwDec
    *     The Software Vdec Handle
    *  @param[out] pOpBuffer
    *     The output buffer ready for rendering
    *  @param[out] pClientHandle
    *     The client handle
    *
    *  @return SWVDEC_S_SUCCESS if success
    *     status error otherwise
    */
    SWVDEC_STATUS (*FillBufferDone)(SWVDEC_HANDLE pSwDec, SWVDEC_OPBUFFER* pOpBuffer, void *pClientHandle);

    /**
    * This callback function for the sw decoder module to notify a
    * client that an orignal input buffer is no longer used. After
    * flush this is also used to return the buffers back
    *
    *  @param[out] pSwDec
    *     The Software Vdec Handle
    *  @param[out] pIpBuffer
    *     The input buffer that is no longer used
    *  @param[out] pClientHandle
    *     The client handle
    *
    *  @return SWVDEC_S_SUCCESS if success
    *     status error otherwise
    */
    SWVDEC_STATUS (*EmptyBufferDone)(SWVDEC_HANDLE pSwDec, SWVDEC_IPBUFFER* pIpBuffer, void *pClientHandle);

    /**
    * This callback function for the sw decoder module to notify a
    * client that an event has happened
    *
    *  @param[out] pSwDec
    *     The Software Vdec Handle
    *  @param[out] pEventHandler
    *     The event information
    *  @param[out] pClientHandle
    *     The client handle
    *
    *  @return SWVDEC_S_SUCCESS if success
    *     status error otherwise
    */
    SWVDEC_STATUS (*HandleEvent)(SWVDEC_HANDLE pSwDec, SWVDEC_EVENTHANDLER* pEventHandler, void *pClientHandle);

    /**
    * the client callback handle
    */
    void* pClientHandle;
} SWVDEC_CALLBACK;

#ifdef __cplusplus
}  /* closing brace for extern "C" */
#endif

#endif //_SWVDEC_TYPES_H
