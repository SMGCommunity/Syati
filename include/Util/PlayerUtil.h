#pragma once

#include "JGeometry/TVec3.h"

class LiveActor;
class HitSensor;

namespace MR
{
    bool isOnGroundPlayer();

    JGeometry::TVec3<f32>* getPlayerPos();

    JGeometry::TVec3<f32>* getPlayerRotate();

    void setPlayerJumpVec(const JGeometry::TVec3<f32> &);

    void forceJumpPlayer(const JGeometry::TVec3<f32> &);

    bool isOnPlayer(const HitSensor *);

    bool isPlayerSwingAction();

    bool isPlayerHipDropLand();

    bool isPlayerInBind();

    bool isPlayerStaggering();
    bool isPlayerSwimming();
    bool isPlayerSleeping();
    bool isPlayerJumpRising();

    void endBindAndPlayerJump(LiveActor *, const JGeometry::TVec3<f32> &, u32);

    void startBckPlayer(const char *, const char *);

    void setPlayerSwingPermission(bool);
};
