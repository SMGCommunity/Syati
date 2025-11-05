#pragma once

#include "syati.h"
class TicoEat;
class TicoStateEatCoin : public ActorStateBaseInterface {
public:
    TicoStateEatCoin(TicoEat* pTicoEat, s32 amount);

    virtual ~TicoStateEatCoin();
    virtual void appear();
    virtual void control();

    u32 _8;
    u32 _C;
    u32 _10;
    u32 _14;
    u32 _18;
    u32 _1C;
    u32 _20;
    u32 _24;
    u32 _28;
    u32 _2C;
};

