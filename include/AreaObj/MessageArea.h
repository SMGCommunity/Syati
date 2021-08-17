#pragma once

#include "AreaObj/AreaObj.h"

class MessageArea : public AreaObj
{
public:
	MessageArea(const char *);

	virtual ~MessageArea();
	virtual void init(const JMapInfoIter &);

	s32 mZoneId;
};
