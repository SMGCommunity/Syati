#pragma once

#include "AreaObj/AreaObj.h"

class SoundEmitterCube : public AreaObj
{
public:
	SoundEmitterCube(const char *);

	virtual ~SoundEmitterCube();
	virtual void init(const JMapInfoIter &);
	virtual void movement();

	u32* mSound; // _48
	TVec3f& mSoundPos; // _4C
};
