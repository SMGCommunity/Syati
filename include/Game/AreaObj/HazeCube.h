#pragma once

#include "Game/AreaObj/AreaObj.h"

/* FINISHED */

class HazeCube : public AreaObj {
public:
	HazeCube(const char *pName);

	virtual ~HazeCube();
	virtual void init(const JMapInfoIter &rIter);
	virtual bool isInVolume(const TVec3f &rTranslation) const;
	virtual const char* getManagerName() const;

	/* 0x48 */ f32 mDistance;
};
