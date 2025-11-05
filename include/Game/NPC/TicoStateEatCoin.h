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
    TicoEat* mHost;
    Coin** mCoins;
    s32  mAmount;
    TVec3f _1C;
    u32 _28;
    u32 _2C;
};

