#pragma once

#include "Game/LiveActor.h"

class ExterminationSwitch : public LiveActor {
public:
    ExterminationSwitch(const char *pName);
    virtual ~ExterminationSwitch();
    virtual void init(const JMapInfoIter &rIter);

    void exeWait();
    void exeReady();
    void exeAllDeadPowerStar();
    void exeAllDead();

    LiveActorGroup *mEnemies;   // _90
    u32 mSpawnsPowerStar;       // _94
    u32 _98;
    u8 _9C;
    u32 _A0;
};

namespace NrvExterminationSwitch {
    NERVE(ExterminationSwitchNrvWait);              // 807D91B8
    NERVE(ExterminationSwitchNrvReady);             // 807D91BC
    NERVE(ExterminationSwitchNrvAllDeadPowerStar);  // 807D91C0
    NERVE(ExterminationSwitchNrvAllDead);           // 807D91C4
};