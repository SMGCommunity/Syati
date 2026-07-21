#pragma once

#include "Game/NameObj.h"

class FirePressureBullet;

class FirePressureBulletHolder : public NameObj {
public:    
    FirePressureBulletHolder(const char *);
    ~FirePressureBulletHolder();
    virtual void init(const JMapInfoIter &rIter);
    FirePressureBullet* callEmptyBullet();

    FirePressureBullet* mBullets[20];
};