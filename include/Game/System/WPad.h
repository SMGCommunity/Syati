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

class WPad {
public:
    WPad(s32);

    u32 getValidStatusCount() const;
    KPADStatus* getKPadStatus(u32) const;

    void update();
    void resetPad();

    static void getInfoCallback(s32, s32);

    s32 mChannel;                           // _0
    u32 _4;
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