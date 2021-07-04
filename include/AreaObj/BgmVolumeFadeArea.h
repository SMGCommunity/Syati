#pragma once

#include "AreaObj/AreaObj.h"

class BgmVolumeFadeArea : public AreaObj
{
public:
	BgmVolumeFadeArea(const char *);

	virtual ~BgmVolumeFadeArea();
	virtual void init(const JMapInfoIter &);
	virtual void movement();
	virtual const char* getManagerName() const;

	s32 getFadeTime() const;
	f32 getVolume() const;

	bool _48;
	bool _49;
};
