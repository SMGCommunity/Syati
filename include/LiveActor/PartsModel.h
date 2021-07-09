#pragma once

#include "LiveActor/LiveActor.h"
#include "Util/FixedPosition.h"

class PartsModel : public LiveActor
{
public:
    PartsModel(LiveActor *, const char *, const char *, Mtx, s32, bool);

    virtual ~PartsModel();
    virtual void init(const JMapInfoIter &);
    virtual void movement();
    virtual void calcAnim();
    virtual void calcViewAndEntry();
    virtual void makeActorAppeared();
    virtual void makeActorDead();
    virtual void calcAndSetBaseMtx();

    void initFixedPosition(const TVec3f &, const TVec3f &, const char *);
    void initFixedPosition(const char *);
    void initFixedPosition(Mtx4*, const TVec3f &, const TVec3f &);
    void loadFixedPosition(const char*, const LiveActor*);
    void offFixedPosNormalizeScale();

    LiveActor* mHost; // _90
    FixedPosition* mFixedPos; // _94
    Mtx4* _98;
    bool mCalcOwnMatrix; // _9C
    bool _9D;
    bool _9E;
};
