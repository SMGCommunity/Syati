#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"
#include "Game/LiveActor/Binder.h"
#include "Game/System/ResourceHolder.h"
#include "Game/Util/HashUtil.h"

class EffectKeeper {
public:
    EffectKeeper(const char *, ResourceHolder *, s32, const char *);

    void init(LiveActor *);
    void initAfterPlacementForAttributeEffect(Mtx *);
    void setBinder(Binder *);
    void addEffect(const char *, LiveActor *);
    void registerEffect(const char *, Mtx *, const char *, const char *);

    void updateAttributeEffect();
    void stopEmitterOnClipped();
    void playEmitterOffClipped();
    void clear();
    void changeBck();
    void onDraw();
    void offDraw();
    void enableSort();
    void finalizeSort();

    void update();

    const char* _0;
    const char* _4;
    ResourceHolder* mResourceHolder; // _8
    u32 **_C;
    u32 _10;
    u32 _14;
    HashSortTable* _18; // HashSortTable*
    u32 _1C;
    u32* _20; // SyncBckEffectChecker*
    Binder* mBinder; // _24
    u32 _28;
    u32 _2C;
    u32 _30;
};
