#pragma once

#include "kamek.h"
#include "JGeometry/TVec3.h"

class LiveActor;

namespace MR
{
    void initShadowFromCSV(LiveActor *, const char *, bool);

    void addShadowVolumeBox(LiveActor *, const char *, const TVec3f &, Mtx);

    void initShadowVolumeSphere(LiveActor *, f32);

    void initShadowVolumeCylinder(LiveActor *, f32);

    void setShadowDropLength(LiveActor *, const char *, f32);

    void setShadowVolumeSphereRadius(LiveActor *, const char *, f32);

    void setShadowVolumeStartDropOffset(LiveActor *, const char *, f32);
    void setShadowVolumeEndDropOffset(LiveActor *, const char *, f32);
};
