#pragma once

#include "syati.h"

class EatDemoCoin : public LiveActor {
public:
    EatDemoCoin(const char* pName);
    virtual ~EatDemoCoin();
    virtual void calcAndSetBaseMtx();

    u32 _90;
    u32 _94;
    u32 _98;
    u32 _9C;
    u32 _B0;
    u32 _B4;
    u32 _B8;
    u32 _BC;
};