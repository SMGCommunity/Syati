#pragma once

#include "revolution.h"
#include "Game/System/WPadButton.h"

class WPadPointer;
class WPadAcceleration;
class WPadHVSwing;
class WPadRumble;
class WPadStick;
class WPadLeaveWatcher;
class WPadInfoChecker;
class KPADStatus;

class WPadReadDataInfo {
public:
    WPadReadDataInfo();

    KPADStatus* getKPadStatus(u32) const;
    u32 getValidStatusCount() const;

    KPADStatus* mStatusArray;      // _0 
    u32 mValidStatusCount;          // _4
};

class WPad {
public:
    WPad(s32);
    void setReadInfo(WPadReadDataInfo *);
    void update();
    WPadRumble *getRumbleInstance() const;
    bool startLeaveWatcher();
    s32 getBattery() const;
    void connected();
    void disconnected();
    void connectCallback(s32, s32);
    void extensionCallback(s32, s32);
    static void getInfoCallback(s32, s32);
    bool isDeviceFreeStyle(KPADStatus *);
    void getPadDataForExceptionNoInit(u32, u32 *, u32 *);
    KPADStatus* getKPadStatus(u32) const;
    u32 getValidStatusCount() const;
    u32 getEnableAccelPastCount(u32) const;
    void getAcceleration(TVec3f *, u32) const;
    void getPastAcceleration(TVec3f *, s32, u32) const;

    s32 mChannel;                           // _0
    WPadReadDataInfo *mReadDataInfo;        // _4                                 // WPadReadDataInfo
    WPadButton* mButtons;                   // _8
    WPadPointer* mPointer;                  // _C
    WPadAcceleration* _10;
    WPadHVSwing* _14;
    WPadRumble* _18;
    WPadRumble* _1C;
    WPadStick* mStick;                      // _20
    WPadAcceleration* _24;
    WPadHVSwing* _28;
    WPadLeaveWatcher* mLeaveWatcher;        // _2C
    WPadInfoChecker* mChecker;              // _30
    u8 _34;
    u8 _35;
    u8 _36;
};