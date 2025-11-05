#pragma once

#include "syati.h"
class TicoEat;
class EatDemoCoin;

class TicoStateEatCoin : public ActorStateBaseInterface {
public:
    TicoStateEatCoin(TicoEat* pTicoEat, s32 amount);

    virtual ~TicoStateEatCoin();
    virtual void appear();
    virtual void control();

    u32 _C;
    TicoEat* mHost;
    EatDemoCoin** mCoins;
    s32 mAmount;
    TVec3f _1C;
    u32 _28;
    u32 _2C;
};

