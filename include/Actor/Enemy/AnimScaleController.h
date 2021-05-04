#pragma once

#include "Actor/Nerve/NerveExecutor.h"

struct AnimScaleParam
{
    f32 _0;
    f32 _4;
    f32 _8;
    f32 _C;
    f32 _10;
    f32 _14;
    f32 _18;
    f32 _1C;
    f32 _20;
    f32 _24;
    f32 _28;
    s32 _2C;
    f32 _30;
};

class AnimScaleController : public NerveExecutor
{
public:
    AnimScaleController(AnimScaleParam *);

    virtual ~AnimScaleController();

    void setParamTight();
    void startAnim();
    void startDpdHitVibration();
    void startHitReaction();
    void startScaleVelocityY(f32);
    void startAndAddScaleVelocityY(f32);
    void startCrush();
    void stopAndReset();

    void resetScale();
    void exeHitReaction();
    void exeDpdVibration();
    void exeCrush();
    bool isHitReaction(s32) const;
    bool tryStop();
    void update();
    void updateScale(f32, f32);

    s32 _8;
    TVec3f mScale; // _C;
    f32 _18;
};

namespace MR {
    void updateBaseScale(LiveActor *, AnimScaleController *);
};
