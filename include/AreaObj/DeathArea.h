#pragma once

#include "AreaObj/AreaObj.h"

class DeathArea : public AreaObj
{
public:
	DeathArea(const char *);

	virtual ~DeathArea();
	virtual void init(const JMapInfoIter &);
	virtual void movement();
	virtual bool isInVolume(const TVec3f &) const;
	virtual const char* getManagerName() const;

	s32 getDeathType() const;
};
