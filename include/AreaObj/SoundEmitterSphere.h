#pragma once

#include "AreaObj/AreaObj.h"

class SoundEmitterSphere : public AreaObj
{
public:
	SoundEmitterSphere(const char *);

	virtual ~SoundEmitterSphere();
	virtual void init(const JMapInfoIter &);
	virtual void movement();

	u32* mSound; // _48
	TVec3f& mSoundPos; // _4C
};
