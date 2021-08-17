#pragma once

#include "AreaObj/SoundEmitterCube.h"

class SoundEmitterCubeWorldMapSync : public SoundEmitterCube
{
public:
	SoundEmitterCubeWorldMapSync(const char *);

	virtual ~SoundEmitterCubeWorldMapSync();
	virtual void init(const JMapInfoIter &);
};
