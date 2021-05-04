#pragma once

#include "Actor/Nerve/NerveExecutor.h"

struct AnimScaleParam;

class AnimScaleController : public NerveExecutor
{
public:
    AnimScaleController(AnimScaleParam *);

    virtual ~AnimScaleController();

    void startHitReaction();

    s32 _8;
    TVec3f mScale;
    f32 _18;
};