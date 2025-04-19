#pragma once

#include "revolution/types.h"

class CometEventKeeper {
public:
    CometEventKeeper();
    ~CometEventKeeper();

    void init();
    bool isStartEvent(char const *) const;
    void startCometEventIfExist();
    void endCometEvent();
    void pauseCometTimer();
    void resumeCometTimer();
    void showCometTimer();
    void hideCometTimer();
    void addCometTimer(s32);
    void decCometTimer(s32);
    s32 getTimeLimitFromScenarioData();
    void initCometStatus();

    s32 _4;
    s32 _8;
    s32 _C;
};
