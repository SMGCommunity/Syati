#pragma once

#include "revolution.h"
#include "Game/System/WPad.h"

class WPad;
class KPADStatus;

class WPadReadDataInfo {
public:
    WPadReadDataInfo();

    KPADStatus* getKPadStatus(u32) const;
    u32 getValidStatusCount() const;

    KPADStatus* mStatusArray;      // _0 
    u32 mValidStatusCount;          // _4
};

class WPadHolder {
public:
    WPadHolder();

    void updateReadDataOnly();
    void updateProjectPadData();
    void updateInGame();
    void update();
    void resetPad();
    WPad* getWPad(s32);

    WPad* mPads[2];                           // _0
    WPadReadDataInfo* mDataInfoArray;       // _8
    u32 _C;
};

namespace MR {
    WPad* getWPad(s32);
}