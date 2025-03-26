#pragma once

#include "revolution.h"

class YoshiLockOnTarget;

namespace YoshiFunction {
    bool tryYoshiEat(YoshiLockOnTarget*);
    bool tryYoshiLick(YoshiLockOnTarget*);
    bool tryYoshiCapture(YoshiLockOnTarget*, bool);
    bool tryYoshiPull(YoshiLockOnTarget*);
    bool tryYoshiProjectile(YoshiLockOnTarget*);
    void emitGlowEffect();
    void deleteGlowEffect();
    bool isYoshiLightMode(); // Returns true if the Bulb Berry is currently active. Only used by the camera area category detection in vanilla

    // More functions to investigate...


}

namespace MR {
    bool isMsgYoshiStartTongue(u32 msg);
    bool isMsgYoshiLoopTongue(u32 msg);
    bool isMsgYoshiReleaseEaten(u32 msg);
    bool isMsgYoshiStartEaten(u32 msg);
    bool isMsgYoshiCancelEaten(u32 msg);
    bool isMsgYoshiReleaseOrCancelEaten(u32 msg);
    bool isMsgYoshiAutoEatStart(u32 msg);
    bool isMsgYoshiAutoEatEnd(u32 msg);
    bool isMsgDashYoshiAttack(u32 msg);
    MtxPtr getYoshiMouthMtx();
    void incYoshiFruitEaten();

    // Eventually the "IsPlayerModeYoshiLight" and it's variants for the other yoshi types should be moved into here, as they are part of this file I believe.
}