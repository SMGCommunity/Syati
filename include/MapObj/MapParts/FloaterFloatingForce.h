#pragma once

#include "MapObj/MapParts/MapPartsFunction.h"

class FloaterFloatingForce : public MapPartsFunction
{
public:
	FloaterFloatingForce(LiveActor *, const char *);

	virtual ~FloaterFloatingForce();
	virtual void init(const JMapInfoIter &);
	virtual void start();
	virtual void updateHostTrans(TVec3f *) const;
	virtual void updateHostVelocity(TVec3f *) const;
	virtual TVec3f& getCurrentVelocity() const;

	s32 _28;
	TVec3f _2C;
	TVec3f _38;
	f32 _44;
};
