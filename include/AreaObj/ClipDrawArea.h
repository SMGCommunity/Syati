#pragma once

#include "AreaObj/AreaObj.h"

class ClipDrawArea : public AreaObj
{
public:
	ClipDrawArea(const char *);

	virtual ~ClipDrawArea();
	virtual void init(const JMapInfoIter &);
};
