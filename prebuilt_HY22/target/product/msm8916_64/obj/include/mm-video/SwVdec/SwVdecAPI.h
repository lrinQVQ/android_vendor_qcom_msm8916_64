/*============================================================================
  @file SwVdecAPI.h
  This file defines the interface for Software Video Decoder module.

  Copyright (c) 2013-2014 Qualcomm Technologies, Inc.  All Rights Reserved.
  Qualcomm Technologies Proprietary and Confidential.
============================================================================*/

/*============================================================================
  EDIT HISTORY FOR MODULE

  $Header: //source/qcom/qct/multimedia2/Video/HEVC_SoftwareCodec2/SwVdec/api/SwVdecAPI.h#3 $
  $DateTime: 2013/09/24 16:09:42 $
  $Change: 4488152 $
  $Author: jeehongy $

  when        who  what, where, why
  ----------  ---  -----------------------------------------------------------
  2013-03-06  kv   Initial version.

============================================================================*/

#ifndef _SWVDEC_API_H
#define _SWVDEC_API_H

#include "SwVdecTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/**<
 * Interface Functions supported by SW Decoder library
 */

/**< This function is a synchronous API to
  * initialize the SW Decoder Lib and Acquire resources
  *
  *  @param[in] pInitParams
  *     The initial parameters.
  *  @param[in] pCallbackFn
  *     The callback functions
  *  @param[out] ppSwDec
  *     The sw decoder handle.
  *
  *  @return SWVDEC_STATUS_SUCCESS if success
  *     status error otherwise
  */
SWVDEC_STATUS SwVdec_Init(SWVDEC_INITPARAMS* pInitParams, SWVDEC_CALLBACK *pCallbackFn, SWVDEC_HANDLE* ppSwDec);

/**< This function is a synchronous API to
  * de-Initialize the SW Decoder Lib and Release resources
  *
  *  @param[in] pSwDec
  *     The sw decoder handle.
  *
  *  @return SWVDEC_STATUS_SUCCESS if success
  *     status error otherwise
  */
SWVDEC_STATUS SwVdec_DeInit(SWVDEC_HANDLE pSwDec);

/**< This function is a synchronous API to
  * get all supported color formats by the current decoder component.
  *
  *  @param[in] pSwDec
  *     The sw decoder handle.
  *  @param[out] pNumColorFormats
  *     The number of supported color formats.
  *  @param[inout] pColorFormats
  *     If NULL this field is ignored. If non-NULL it will return an array of supported color format.
  *
  *  @return SWVDEC_STATUS_SUCCESS if success
  *     status error otherwise
  */
SWVDEC_STATUS SwVdec_GetSupportedColorFormats(SWVDEC_HANDLE pSwDec,
                                              unsigned long int *pNumColorFormats,
                                              SWVDEC_COLOR_FORMAT_TYPE *pColorFormats);

/**< This function is a synchronous API to
  * set output buffer - gives buffer pointer to the Decoder
  *
  *  @param[in] pSwDec
  *     The sw decoder handle.
  *  @param[in] pOutputBuffers
  *     The output buffer pointer.
  *
  *  @return SWVDEC_STATUS_SUCCESS if success
  *     status error otherwise
  */
SWVDEC_STATUS SwVdec_SetOutputBuffer(SWVDEC_HANDLE pSwDec, SWVDEC_OPBUFFER* pOutputBuffers);

/**< This function is a synchronous API to
  * start decoding
  *
  *  @param[in] pSwDec
  *     The sw decoder handle.
  *
  *  @return SWVDEC_STATUS_SUCCESS if success
  *     status error otherwise
  */
SWVDEC_STATUS SwVdec_Start(SWVDEC_HANDLE pSwDec);

/**< This function is a synchronous API to
  * stop decoding
  *
  *  @param[in] pSwDec
  *     The sw decoder handle.
  *
  *  @return SWVDEC_STATUS_SUCCESS if success
  *     status error otherwise
  */
SWVDEC_STATUS SwVdec_Stop(SWVDEC_HANDLE pSwDec);

/**< This function is an asynchronous API to
  * flush input and/or output buffers
  *
  *  @param[in] pSwDec
  *     The sw decoder handle.
  *  @param[in] aFlushType
  *     The flush type.
  *
  *  @return SWVDEC_STATUS_SUCCESS if success
  *     status error otherwise
  */
SWVDEC_STATUS SwVdec_Flush(SWVDEC_HANDLE pSwDec, SWVDEC_BUFFER_FLUSH_TYPE aFlushType);

/**< This function is an asynchronous API to send an input buffer. The sw decoder shall treat this frame
  * read only. When the buffer is no longer used, the sw decoder shall call the SWVDEC_IPBUFFER callback
  * to return the input buffer
  *
  *  @param[in] pSwDec
  *     The sw decoder handle.
  *  @param[in] pInBuffer
  *     The input buffer pointer.
  *
  *  @return SWVDEC_STATUS_SUCCESS if success
  *     status error otherwise
  */
SWVDEC_STATUS SwVdec_EmptyThisBuffer(SWVDEC_HANDLE pSwDec, SWVDEC_IPBUFFER* pInBuffer);

/**< This function is an asynchronous API to send a frame for reuse.
  * When the buffer is used to decode a frame, the sw decoder shall call the
  * SWVDEC_OPBUFFER callback to return the frame for rendering
  *
  *  @param[in] pSwDec
  *     The sw decoder handle.
  *  @param[in] pOpBuffer
  *     The output buffer pointer.
  *
  *  @return SWVDEC_STATUS_SUCCESS if success
  *     status error otherwise
  */
SWVDEC_STATUS SwVdec_FillThisBuffer(SWVDEC_HANDLE pSwDec, SWVDEC_OPBUFFER* pOpBuffer);

/**< This function is a synchronous API to
  * set a sw decoder property
  *
  *  @param[in] pSwDec
  *     The sw decoder handle.
  *  @param[in] pProperty
  *     The sw decoder pointer.
  *
  *  @return SWVDEC_STATUS_SUCCESS if success
  *     status error otherwise
  */
SWVDEC_STATUS SwVdec_SetProperty(SWVDEC_HANDLE pSwDec, SWVDEC_PROP* pProperty);

/**< This function is a synchronous API to
  * get a sw decoder property
  *
  *  @param[in] pSwDec
  *     The sw decoder handle.
  *  @param[in] pProperty
  *     The sw decoder pointer.
  *
  *  @return SWVDEC_STATUS_SUCCESS if success
  *     status error otherwise
  */
SWVDEC_STATUS SwVdec_GetProperty(SWVDEC_HANDLE pSwDec, SWVDEC_PROP* pProperty);

#ifdef __cplusplus
}  /* closing brace for extern "C" */
#endif

#endif //_SWVDEC_API_H
