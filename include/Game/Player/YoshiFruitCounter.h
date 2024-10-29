#pragma once

#include "Game/NameObj.h"

class YoshiFruitCounter : public NameObj {
public:
    YoshiFruitCounter();
    virtual ~YoshiFruitCounter();
    virtual void movement();
    void increment();

    u32 _14;
    u32 _18;
};