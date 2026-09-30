#pragma once

#include "Game/AreaObj/AreaObj.h"

class SoundEmitterSphere : public AreaObj {
public:
	SoundEmitterSphere(const char *pName);

	virtual ~SoundEmitterSphere();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();

	/* 0x48 */ u32* mSound;
	/* 0x4C */ TVec3f mSoundPos;
};
