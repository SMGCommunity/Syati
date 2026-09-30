#pragma once

#include "Game/AreaObj/AreaObj.h"

class SoundEmitterCube : public AreaObj {
public:
	SoundEmitterCube(const char *pName);

	virtual ~SoundEmitterCube();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();

	/* 0x48 */ u32* mSound;
	/* 0x4C */ TVec3f mSoundPos;
};
