#pragma once

#include "Game/LiveActor/LiveActorGroup.h"

class BombTeresa;

class BombTeresaHolder : public DeriveActorGroup<BombTeresa> {
public:
	BombTeresaHolder();

	virtual ~BombTeresaHolder();

	void disperseAll();
};