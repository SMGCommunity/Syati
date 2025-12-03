#pragma once

#include "syati.h"

class TreasureSpot : public MapObjActor {
public:
    TreasureSpot(const char* pName);

    virtual ~TreasureSpot();
    virtual void init(const JMapInfoIter& rIter);
    virtual void control();
    virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);

    void exeAppear();
    void switchEmitGlow();

    bool mIsCoinFlower;
};

namespace NrvTreasureSpot {
    NERVE(TreasureSpotNrvWait);
    NERVE(TreasureSpotNrvEnd);
    NERVE(TreasureSpotNrvSpout);
};