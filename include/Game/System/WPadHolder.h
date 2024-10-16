#pragma once

#include "revolution.h"
#include "Game/System/WPad.h"

class WPad;
class KPADStatus;

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