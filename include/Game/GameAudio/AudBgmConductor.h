#pragma once

#include "Game/NameObj.h"

class AudBgmConductor : public NameObj {
public: 
    AudBgmConductor();
    ~AudBgmConductor();
    virtual void init(const JMapInfoIter &);
    virtual void movement();
    void setStateBit(u32);
    void movementMorphBgm();
    
    s32 _14;
    u32 _18;
    u32 _1C;
    s32 _20;
    s32 _24;
    u8 _28;
};