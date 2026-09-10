#pragma once

#include "Game/NPC/TicoEat.h"

class TicoShop : public TicoEat {
public:
    TicoShop(const char *pName);
    virtual ~TicoShop();
    virtual void init(const JMapInfoIter &rIter);
    virtual void kill();
    
    bool branchFunc(u32);
    bool eventFunc(u32);
    void startReactionSound();
    void exeDemo();
    
    BenefitItemObj *mOneUpMushroom; // _1B8
    BenefitItemObj *mLifeMushroom;  // _1BC
    bool mGiveOneUp;                // _1C0
    u8 mGiveLifeMushroom;           // _1C4
};

namespace NrvTicoShop {
    NERVE(TicoShopNrvDemo);
};