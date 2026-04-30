#pragma once

#include "Game/Camera/Camera.h"

class CameraTower : public Camera {
public:
    CameraTower(const char* pName = "塔カメラ");
    virtual ~CameraTower();

    virtual void reset();
    virtual CameraTargetObj* calc();
    virtual bool isEnableToRoundLeft() const;
    virtual bool isEnableToRoundRight() const;
    virtual CamTranslatorBase* createTranslator();
    virtual void arrangeRound();

    void arrangeRoundingPose();
    void arrangeHorizontalPose();
    bool isUpsideDownByRoll() const;

    TVec3f mWPoint;  // 0x54
    TVec3f mAxis;    // 0x60
    f32 mAngleB;     // 0x6C
    f32 mAngleA;     // 0x70
    f32 mDist;       // 0x74
    f32 _78;         // 0x78
    f32 _7C;         // 0x7C
    f32 _80;         // 0x80
    u8 _84;
    u32 _88;
    f32 _8C;
    u8 _90;
    u8 _91;
};