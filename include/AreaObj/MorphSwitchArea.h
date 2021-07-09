#pragma once

#include "AreaObj/AreaObj.h"

class MorphSwitchArea : public AreaObj
{
public:
	MorphSwitchArea(const char *);

	virtual ~MorphSwitchArea();
	virtual void init(const JMapInfoIter &);
	virtual void movement();
	
	bool checkCondition() const;

	s32 mZoneId;
};
