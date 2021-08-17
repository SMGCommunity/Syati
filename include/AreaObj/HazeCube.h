#pragma once

#include "AreaObj/AreaObj.h"

class HazeCube : public AreaObj
{
public:
	HazeCube(const char *);

	virtual ~HazeCube();
	virtual void init(const JMapInfoIter &);
	virtual bool isInVolume(const TVec3f &) const;
	virtual const char* getManagerName() const;
};
