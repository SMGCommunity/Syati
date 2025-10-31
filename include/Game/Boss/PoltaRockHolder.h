#pragma once

#include "Game/LiveActor/LiveActorGroup.h"

class PoltaRock;

class PoltaRockHolder : public DeriveActorGroup<PoltaRock> {
public:
	PoltaRockHolder();

	virtual ~PoltaRockHolder();
};