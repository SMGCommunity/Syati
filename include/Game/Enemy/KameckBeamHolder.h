#pragma once

#include "Game/LiveActor/LiveActorGroup.h"
#include "Game/Enemy/KameckBeam.h"

class KameckBeamHolder : public DeriveActorGroup<KameckBeam> {
public:
	KameckBeamHolder(s32 beamType, s32 numBeams, s32 numBeamActors); // numBeamActors LIMIT 3

	virtual ~KameckBeamHolder();

	KameckBeam* startFollowKameckBeam(MtxPtr jointMtx, f32 size, const TVec3f& localOffset, KameckBeamEventListener* hitBeamEventListener); // New to SMG2... technically. This used to be an MR function in SMG1
};