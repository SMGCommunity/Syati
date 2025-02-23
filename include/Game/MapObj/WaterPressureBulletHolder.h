#pragma once

#include "Game/NameObj.h"

class WaterPressureBullet;

class WaterPressureBulletHolder : public NameObj {
public:    
    WaterPressureBulletHolder(const char *);
    ~WaterPressureBulletHolder();
    virtual void init(const JMapInfoIter &rIter);
    WaterPressureBullet *callEmptyBullet();
};