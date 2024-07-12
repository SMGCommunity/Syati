#pragma once

#include "Game/LiveActor/LiveActor.h"

class StarPieceMother : public LiveActor {
public:
    StarPieceMother(const char *);
    virtual void init(const JMapInfoIter &);
    virtual void kill();
    virtual void control();
    virtual void attackSensor(HitSensor *, HitSensor *);

    void exeMoveOnRail();
    void placementPieceOnRail(f32);
    void onSwitchA();
    void offSwitchA();
    void emitStarPieces(HitSensor *, HitSensor *);
    ~StarPieceMother();

    u32 _0[0x2A];
};

namespace NrvStarPieceMother {
	NERVE(NrvWait);
	NERVE(NrvMoveOnRail);
};