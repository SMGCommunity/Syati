#pragma once

#include "MapObj/MapParts/MapPartsFunction.h"

class MapPartsRotatorBase : public MapPartsFunction
{
public:
	virtual ~MapPartsRotatorBase();
	virtual Mtx* getRotateMtx() const = 0;
	virtual bool isMoving() const = 0;
	virtual bool isOnReverse() const;
	virtual f32 getRotateSpeed() const;
};
