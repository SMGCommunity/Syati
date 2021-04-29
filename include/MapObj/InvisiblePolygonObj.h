#pragma once

#include "Actor/LiveActor/LiveActor.h"

class InvisiblePolygonObj : public LiveActor
{
public:
	InvisiblePolygonObj(const char *);

	virtual void init(const JMapInfoIter &);
	virtual Mtx* getBaseMtx() const;

	void initBaseMtx();
	void initCollision(const JMapInfoIter &);

	Mtx _90;
};
