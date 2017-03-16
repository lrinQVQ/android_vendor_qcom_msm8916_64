/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
  Copyright (c) 2013-2015 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/
#ifndef IZAT_API_BASE_H
#define IZAT_API_BASE_H

#include <WiperData.h>
#include <LocApiBase.h>
#include <geofence.h>
#include <LBSApiBase.h>
#include "fused_location_extended.h"

#define GTP_LP_MAX_ALLOWED_APS 80
#define GTP_LP_QMI_VERSION 1

using namespace loc_core;
using namespace lbs_core;

typedef struct
{
  uint64_t macaddress_48b;
  float latitude;
  float longitude;
  float horUncCircular;
} APInfo;

typedef struct
{
  uint8_t totalParts;
  uint8_t partNumber;
  uint8_t length;
  APInfo apnode[GTP_LP_MAX_ALLOWED_APS];
} APCacheData;

typedef struct
{
  uint64_t macaddress_48b;
} BlackListAPInfo;

typedef struct
{
  uint8_t totalParts;
  uint8_t partNumber;
  uint8_t length;
  BlackListAPInfo apnode[GTP_LP_MAX_ALLOWED_APS];
} APCacheBlacklistData;

namespace izat_core {

enum IzatApiReturnCode {
    IZAT_SUCCESS,
    IZAT_FAIL,
    IZAT_INVALID_ARGUMENTS,
};

class IzatAdapterBase;

class IzatApiBase {
    IzatAdapterBase* mIzatAdapters[MAX_ADAPTERS];
protected:
    LocApiProxyBase *mLocApiProxy;
public:
    IzatApiBase(LocApiProxyBase *locApiProxy);
    inline virtual ~IzatApiBase() {}

    void addAdapter(IzatAdapterBase* adapter);
    void removeAdapter(IzatAdapterBase* adapter);

    void saveGeofenceItem(uint32_t hwId, GeoFenceData& geofenceInfo);
    void removeGeofenceItem(uint32_t hwId);
    void pauseGeofenceItem(uint32_t hwId);
    void resumeGeofenceItem(uint32_t hwId);

    void geofenceBreach(int32_t hwId, FlpExtLocation& gpsLocation, int32_t transition);
    void geofenceStatus(uint64_t status);
    void geofenceResponse(GeofenceResp resp, int32_t status, uint32_t hwId);
    virtual int addGeofence(GeoFenceData geofenceInfo, bool needsResponse);
    virtual int removeGeofence(uint32_t hwId,int32_t afwId);
    virtual int pauseGeofence(uint32_t hwId,int32_t afwId);
    virtual int resumeGeofence(uint32_t hwId, int32_t afwId, uint32_t breachMask);
    virtual int modifyGeofence(uint32_t hwId, GeoFenceData data);
    virtual bool isMessageSupported(LocCheckingMessagesID msgID);
    // set user preference
    virtual int setUserPref(bool user_pref);
    virtual int injectApCache(APCacheData data);
    virtual int injectApCacheBlacklist(APCacheBlacklistData data);
    virtual int sendBestAvailablePosReq(GpsLocation &zppLoc);

    virtual void setBatchingSupport(uint32_t supportedLBFeatures);
    virtual void setBatchSize(int32_t size, bool hasSSR = false);
    virtual int cleanUpFlpSession();
    virtual int startFlpSession(const FlpExtBatchOptions& options,
                                int32_t accuracy,
                                int32_t timeout,
                                uint32_t hwId = FLP_INVALID_HW_ID);
    virtual int updateFlpSession(const FlpExtBatchOptions& options,
                                 int32_t accuracy,
                                 int32_t timeout,
                                 uint32_t hwId = FLP_INVALID_HW_ID);
    virtual int stopFlpSession(uint32_t hwId = FLP_INVALID_HW_ID,
                               LocApiSelectionType apiSelected = LOC_API_SELECTION_UN_SELECTED);
    virtual int getBatchedLocation(int32_t lastNLocations,
                                   LocBatchingReportedType reportType,
                                   void* cbForOnQueryRequest = NULL);
    virtual int injectLocation(FlpExtLocation location);
    void reportLocations(FlpExtLocation* location,
                        int32_t number_query,
                        int32_t last_n_locations,
                        LocBatchingReportedType reportType,
                        void* cbForOnQueryRequest = NULL);
    void readLocationsFromModem(int32_t number, LocBatchingReportedType reportType);
    void geofenceBreachLocation(FlpExtLocation &gpsLocation);
    void reportDBTPosition(UlpLocation &location,
                           GpsLocationExtended &locationExtended,
                           enum loc_sess_status status,
                           LocPosTechMask loc_technology_mask);

    // for TDP
    virtual int sendGtpEnhancedCellConfigBlocking(e_premium_mode mode);
    virtual int sendGtpCellConfigurationsBlocking(const char* data, uint32_t len);

    virtual int sendGdtUploadBeginResponse(int32_t service, int32_t session, int32_t status);
    virtual int sendGdtUploadEndResponse(int32_t service, int32_t session, int32_t status);

    // Delete aiding data
    virtual int deleteAidingData(GnssAidingData flags);

protected:
    void handleGdtUploadBeginEvent(int32_t service,
                                   int32_t session,
                                   const char* filePath,
                                   uint32_t filePath_len);
    void handleGdtUploadEndEvent(int32_t service, int32_t session, int32_t status);
};

}  // namespace izat_core

#endif //IZAT_API_BASE_H
