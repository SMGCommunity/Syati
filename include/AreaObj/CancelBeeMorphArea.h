#pragma once

#include "AreaObj/AreaObj.h"

class CancelBeeMorphArea : public AreaObj
{
public:
	CancelBeeMorphArea(const char *pName);

	virtual ~CancelBeeMorphArea();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();
};
