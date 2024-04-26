#pragma once

#include "revolution.h"
#include "Game/Screen/LayoutActor.h"

class CollectCounter : public LayoutActor {
public:
	CollectCounter(const char*, f32);

	virtual ~CollectCounter();
	virtual void init(const JMapInfoIter& rIter);
	virtual void control();

	void setCount(s32);
	bool tryEndShow();
	void setPosition();

	f32 _2C; //_2C
	f32 _30; //_30
	f32 _34; //_34  This one is only in SMG2, and is assigned using the Constructor's f32 parameter
};

namespace NrvCollectCounter {
	NERVE(CollectCounterNrvShow);
	NERVE(CollectCounterNrvHide);
};