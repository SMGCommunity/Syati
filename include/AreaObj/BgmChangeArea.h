#pragma once

#include "AreaObj/AreaObj.h"

class BgmChangeArea : public AreaObj
{
public:
	BgmChangeArea(const char *);

	virtual ~BgmChangeArea();
	virtual void init(const JMapInfoIter &);
	virtual void movement();
	virtual const char* getManagerName() const;

	s32 getFadeTime() const;

	bool _48;
};
