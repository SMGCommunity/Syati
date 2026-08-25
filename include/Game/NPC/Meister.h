#pragma once

#include "revolution/types.h"
#include "Game/NPC/NPCActor.h"

class unk_803538C0;

// TODO: Document unknown functions and nerves

class Meister : public NPCActor {
public:
    Meister(const char *pName);
    virtual ~Meister();
    virtual void init(const JMapInfoIter &rIter);
    virtual void makeActorAppeared();
    virtual void makeActorDead();
    virtual void control();
    virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);

    u8 _164;
    u32 _168;
    unk_803538C0 *_16C;
};