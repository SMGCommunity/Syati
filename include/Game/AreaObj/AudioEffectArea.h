#pragma once

#include "Game/AreaObj/AreaObj.h"

/* FINISHED */

class AudioEffectArea : public AreaObj {
public:
	AudioEffectArea(const char *pName);

	virtual ~AudioEffectArea();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();
	virtual const char* getManagerName() const;

	/* 0x48 */ s32 mAudEffectArg0;
	/* 0x4C */ s32 mAudEffectArg1;
};

namespace MR {
	bool isStageTwisterTowerGalaxy();
}
