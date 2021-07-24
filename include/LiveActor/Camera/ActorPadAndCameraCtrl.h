#pragma once

#include "syati.h"
#include "LiveActor/Model/ModelManager.h"
#include "JGeometry/TVec3.h"

class ActorPadAndCameraCtrl
{
public:
    ActorPadAndCameraCtrl(const ModelManager *, const TVec3f *);

    static ActorPadAndCameraCtrl* tryCreate(const ModelManager *, const TVec3f *);
    void update();

    ModelManager* mModelManager; // _0
    const TVec3f* _4;
    ResourceHolder* mResourceHolder; // _8
    u8 _C[0x18-0xC];
};
