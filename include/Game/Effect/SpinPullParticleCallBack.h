#pragma once

#include "Game/Effect/MultiEmitterParticleCallBack.h"

class SpinPullParticleCallBack : public MultiEmitterParticleCallBack {
public:
    SpinPullParticleCallBack();

    virtual void execute(JPABaseEmitter *pEmitter, JPABaseParticle *pParticle);

    /* 0x04 */ f32 _4;
};
