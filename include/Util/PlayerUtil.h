#pragma once

#include "JGeometry/TVec3.h"

class LiveActor;
class HitSensor;

namespace MR
{
    bool isOnGroundPlayer();

    TVec3f* getPlayerPos();

    TVec3f* getPlayerRotate();

    TVec3f* getPlayerLastMove();
    void setPlayerJumpVec(const TVec3f &);

    void forceJumpPlayer(const TVec3f &);

    bool isOnPlayer(const HitSensor *);

    bool isPlayerSwingAction();

    bool isPlayerHipDropLand();

    bool isPlayerInBind();

    bool isPlayerElementModeIce();

    bool isPlayerStaggering();
    bool isPlayerSwimming();
    bool isPlayerSleeping();
    bool isPlayerJumpRising();

    void endBindAndPlayerJump(LiveActor *, const TVec3f &, u32);

    void startBckPlayer(const char *, const char *);

    void setPlayerSwingPermission(bool);
};
