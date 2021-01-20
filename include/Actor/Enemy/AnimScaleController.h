#pragma once

#include "Actor/Nerve/NerveExecutor.h"

struct AnimScaleParam;

class AnimScaleController : public NerveExecutor
{
public:
    AnimScaleController(AnimScaleParam *);

    virtual ~AnimScaleController();

    u8 _8[0x1C-0x8];
};