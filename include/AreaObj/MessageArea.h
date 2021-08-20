#pragma once

#include "AreaObj/AreaObj.h"

class MessageArea : public AreaObj
{
public:
	MessageArea(const char *pName);

	virtual ~MessageArea();
	virtual void init(const JMapInfoIter &rIter);

	s32 mZoneId;
};
