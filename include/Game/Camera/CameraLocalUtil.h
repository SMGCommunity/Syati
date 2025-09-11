#pragma once

#include "JSystem/JGeometry/TVec.h"

class CameraMan;

namespace CameraLocalUtil {
    TVec3f *getWatchPos(CameraMan *);
    TVec3f *getPos(CameraMan *);
    TVec3f *getUpVec(CameraMan *);
    TVec3f *getWatchUpVec(CameraMan *);
    f32 getFovy(CameraMan *);
    TVec3f *getGlobalOffset(CameraMan *);
    TVec3f *getLocalOffset(CameraMan *);
    f32 getRoll(CameraMan *);

    void setWatchPos(CameraMan *, const TVec3f &);
    void setPos(CameraMan *, const TVec3f &);
    void setUpVec(CameraMan *, const TVec3f &);
    void setWatchUpVec(CameraMan *, const TVec3f &);
    void setFovy(CameraMan *, f32);
    void setGlobalOffset(CameraMan *, const TVec3f &);
    void setLocalOffset(CameraMan *, const TVec3f &);
    void setFrontOffset(CameraMan *, f32);
    void setUpperOffset(CameraMan *, f32);
    void setRoll(CameraMan *, f32);
};