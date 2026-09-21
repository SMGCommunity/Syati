#pragma once

#include "Game/AreaObj/AreaObj.h"

class SoundPlayArea : public AreaObj {
public:
	SoundPlayArea(const char *pName);

	virtual ~SoundPlayArea();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();

	void setupSoundPos();

	/* 0x48 */ TVec3f mSoundPos;
	/* 0x54 */ bool _54;
	/* 0x55 */ bool _55;
	/* 0x58 */ u32* mSound;
};
