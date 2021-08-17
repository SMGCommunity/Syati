#pragma once

#include "MapObj/MapParts/MapPartsFunction.h"

class MapPartsRailPosture : public MapPartsFunction
{
public:
	MapPartsRailPosture(LiveActor *);

	virtual ~MapPartsRailPosture();
	virtual void init(const JMapInfoIter &);
	virtual bool isWorking() const;
	virtual void start();
	virtual void end();

	bool isPostureTypeRailDirRailUseShadowGravity() const;
	void exeMove();
	
	Mtx _28;
	s32 mPostureType; // _58
};
