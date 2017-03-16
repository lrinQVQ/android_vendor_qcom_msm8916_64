/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
  Copyright (c) 2013-2015 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/
#ifndef GPS_GEOFENCE_CALLBACKS_H
#define GPS_GEOFENCE_CALLBACKS_H

#include "GeofenceCallbacks.h"

class GpsGeofenceCb : public GeofenceCallbacks{

    GpsGeofenceCallbacks* gCallbacks;

public:

    inline GpsGeofenceCb(GpsGeofenceCallbacks* callbacks) : GeofenceCallbacks()
    {
        gCallbacks = callbacks;
    }
    inline ~GpsGeofenceCb() {}

    inline void geofence_transition_callback (int32_t geofence_id,
                                             FlpExtLocation* location,
                                             int32_t transition,
                                             int64_t timestamp,
                                             uint32_t sources_used)
    {
        gCallbacks->geofence_transition_callback(geofence_id,
                                                (GpsLocation*)location,
                                                transition, timestamp);
    }
    inline void geofence_status_callback (int32_t status,
                                         uint32_t source,
                                         FlpExtLocation* last_location)
    {
        gCallbacks->geofence_status_callback(status, (GpsLocation*)last_location);
    }
    inline void geofence_add_callback (int32_t geofence_id, int32_t result)
    {
        gCallbacks->geofence_add_callback(geofence_id, result);
    }
    inline void geofence_remove_callback (int32_t geofence_id, int32_t result)
    {
        gCallbacks->geofence_remove_callback(geofence_id, result);
    }
    inline void geofence_pause_callback (int32_t geofence_id, int32_t result)
    {
        gCallbacks->geofence_pause_callback(geofence_id, result);
    }
    inline void geofence_resume_callback (int32_t geofence_id, int32_t result)
    {
        gCallbacks->geofence_resume_callback(geofence_id, result);
    }
};

#endif /* GPS_GEOFENCE_CALLBACKS_H */
