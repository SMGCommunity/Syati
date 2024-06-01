#pragma once

#include "syati.h"

class PauseButtonCheckerInGame {
public:
    PauseButtonCheckerInGame();
    void update();
    bool isPermitToPlusPause() const;
    bool isPermitToMinusPause() const;
    bool isPermitToPause() const;
    
    s32 _0;
    s32 _4;
};