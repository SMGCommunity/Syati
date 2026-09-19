#pragma once

#include "revolution/types.h"

class JPABaseParticle;
class JPABaseEmitter;

class JPAParticleCallBack {
public:
    virtual ~JPAParticleCallBack();
    virtual void execute(JPABaseEmitter*, JPABaseParticle*) {}

    virtual void draw(JPABaseEmitter*, JPABaseParticle*) {}
};
