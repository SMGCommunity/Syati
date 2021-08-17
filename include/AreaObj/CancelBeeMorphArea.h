#pragma once

#include "AreaObj/AreaObj.h"

class CancelBeeMorphArea : public AreaObj
{
public:
	CancelBeeMorphArea(const char *);

	virtual ~CancelBeeMorphArea();
	virtual void init(const JMapInfoIter &);
	virtual void movement();
};
