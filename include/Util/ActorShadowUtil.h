#pragma once

#include "kamek.h"
#include "JGeometry/TVec3.h"

class LiveActor;

namespace MR
{
    void setShadowVolumeStartDropOffset(LiveActor *, const char *, f32);
    void setShadowDropLength(LiveActor *, const char *, f32);

    void addShadowVolumeBox(LiveActor *, const char *, const JGeometry::TVec3<f32> &, Mtx);
};