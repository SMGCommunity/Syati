#pragma once

#include "Game/NameObj/NameObj.h"

class Camera;
class CamTranslatorBase;

class CameraHolder : public NameObj {
public:
    CameraHolder(const char*);

    CamTranslatorBase* getTranslator(s32);
    s32 getIndexOf(const char*) const;
    Camera* getDefaultCamera();
    s32 getIndexOfDefault() const;
    s32 getIndexOf(Camera*) const;
    void createCameras();
    Camera* getCameraInner(s32) const;

    s32 mDefaultCameraIndex; // 0x14
    Camera** mCameras; // 0x18
    CamTranslatorBase** mTranslators; // 0x1C
    Camera* mDefaultCamera; // 0x20
};
