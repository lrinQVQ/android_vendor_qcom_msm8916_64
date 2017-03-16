#ifndef CNE_WQE_INTERFACE_H
#define CNE_WQE_INTERFACE_H

/*=============================================================================
               Copyright (c) 2014,2015 Qualcomm Technologies, Inc.
               All Rights Reserved.
               Qualcomm Technologies Confidential and Proprietary
=============================================================================*/

#include "CneCom.h"
#include "CneTimer.h"
#include "SwimNetlinkSocket.h"
#include "SocketWrapperClient.h"
#include "WqePolicyTypes.h"

#define INTERNET_PROFILE "profile-internet"

class SwimInterfaceSelection;
class BQSampling;
class IBitrateEstimator;
class IInterfaceSelection;
class IDefaultInterfaceSelector;
class CnePolicyConfig;
class CneDefaultDnsSelector;
class SwimSocketManager;
class ISocketManager;
class IWqeAgent;

class CneWqeInterface
{
  public:
    CneWqeInterface(){}
    virtual ~CneWqeInterface(){}
    virtual IWqeAgent* createWqeAgent(std::string profileType, CneTimer &timer, CneCom &com, const CQEClientOverrides *overrides = NULL)=0;
    virtual int destroyWqeAgent(IWqeAgent *iwqeA)=0;
    virtual void createWqe(CneCom &com, CneTimer &timer, bool isSwimEnabled)=0;
    virtual IBitrateEstimator* getBitrateEstimator()=0;
    virtual SwimNetlinkSocket *getNetlinkSocket()=0;
    virtual bool isBbdDisabled()=0;
    virtual CneRetType detectBrokenBackhaul(CneIpcReqMsg_t& req, int fd)=0;
    virtual bool isDefaultSelectorStateWlanGood()=0;
    virtual SwimNimsRetCodeType_t Select( int rfd, SwimNimsSockAddr_t& src, SwimNimsSockAddr_t& dst,
                                          int comfd, int client_fd_val, int uid, int pid)=0;
    virtual bool verifySockExists(int uid, int pid, int fd_val, int rfd)=0;
    virtual void updateAppSockFd(int uid, int pid, int fd_val, int rfd)=0;
    virtual void handleHangup(int comfd)=0;
    virtual void handleClose(int uid, int pid, int comfd, int client_fd_val)=0;
};
#endif
