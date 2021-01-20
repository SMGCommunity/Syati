#pragma once

#include "JGeometry/TVec3.h"

class LiveActor;

namespace MR
{
    JGeometry::TVec3<f32>* getPlayerPos();

    JGeometry::TVec3<f32>* getPlayerVelocity();

    bool isPlayerSwingAction();

    bool isPlayerHipDropLand();

    bool isPlayerInBind();

    void endBindAndPlayerJump(LiveActor *, const JGeometry::TVec3<f32> &, u32);

    void startBckPlayer(const char *, const char *);

    void setPlayerSwingPermission(bool);
};