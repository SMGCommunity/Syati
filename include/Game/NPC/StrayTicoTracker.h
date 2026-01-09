#pragma once

#include "Game/LiveActor/LiveActorGroup.h"
class CollectTico;

// Not sure if this belongs in Game/NPC

// Holds every instance of CollectTico
class StrayTicoTracker : public DeriveActorGroup<CollectTico> {
public:
	StrayTicoTracker();
};

namespace MR {
	void registerCollectTico(CollectTico*);
	void launchRescuedStrayTico(const TPos3f&);
}