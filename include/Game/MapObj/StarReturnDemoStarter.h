#pragma once

#include "syati.h"

class StarReturnDemoStarter : public LiveActor {
public:
    StarReturnDemoStarter(const char*);
    virtual ~StarReturnDemoStarter();
    virtual void init(const JMapInfoIter&);
    virtual void appear();
    virtual void kill();
    virtual void control();
    ModelObj* createSubModel(const char*, const char*, bool);
    bool tryRegisterDemo(const char*, const JMapInfoIter&);
    bool tryStartStageResult();
    void exeAppearWait();
    void exeMove();
    void exeFlyWaitPowerStar();
    void exeFlyWaitGrandStar();
    void exeFall();
    void exeLand();
    void exeWait();
    void exeStageResult();
    void exeFadeOut();
    void exeStageResultAfter();
    
};

namespace NrvStarReturnDemoStarter {
    NERVE(StarReturnDemoStarterNrvStageResultAfter);
    NERVE(StarReturnDemoStarterNrvFadeOut);
    NERVE(StarReturnDemoStarterNrvStageResult);
    NERVE(StarReturnDemoStarterNrvWait);
    NERVE(StarReturnDemoStarterNrvLand);
    NERVE(StarReturnDemoStarterNrvFall);
    NERVE(StarReturnDemoStarterNrvFlyWaitGrandStar);
    NERVE(StarReturnDemoStarterNrvFlyWaitPowerStar);
    NERVE(StarReturnDemoStarterNrvMove);
    NERVE(StarReturnDemoStarterNrvAppearWait);
};