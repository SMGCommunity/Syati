#pragma once

#include "Game/NPC/NPCActor.h"

class Rabbit : public NPCActor {
public:
	Rabbit(const char* pName);

	virtual ~Rabbit();
	virtual void init(const JMapInfoIter& rIter);
	virtual void makeActorAppeared();
	virtual void control();
	virtual void calcAndSetBaseMtx();
	virtual bool isReactionNerve() const;

	s32 _164; // 0x164
	f32 _168; // 0x168
	f32 _16C; // 0x16C - leftover from SMG1
};

namespace NrvRabbit {
	NERVE(RabbitNrvJumpH);
	NERVE(RabbitNrvJumpV);
	NERVE(RabbitNrvTalk);
	NERVE(RabbitNrvReaction);
	NERVE(RabbitNrvAppearLand);
	NERVE(RabbitNrvAppear);
};