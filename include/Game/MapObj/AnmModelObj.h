#pragma once

#include "revolution.h"
#include "Game/MapObj/MapObjActor.h"

class AnmModelObj : public MapObjActor {
public:
	AnmModelObj(const char* pName);

	virtual ~AnmModelObj();
	virtual void init(const JMapInfoIter&);

	virtual void control();

	virtual void initCaseUseSwitchA(const MapObjActorInitInfo&);
	virtual void initCaseNoUseSwitchA(const MapObjActorInitInfo&);
	virtual void initCaseUseSwitchB(const MapObjActorInitInfo&);
	virtual void initCaseNoUseSwitchB(const MapObjActorInitInfo&);

	virtual bool isOnStartAnmTrigger() const = 0;
	virtual bool isDone() const;
	virtual bool isKilledAtMoveDone() const;
	virtual bool isInvalidateCollision() const;
	virtual bool isRepeat() const;
	virtual void onStartMove();
	virtual void onLoopMove();
	virtual void onStopMove();
	virtual void onDone();

	TVec3f _D0;
};

namespace NrvAnmModelObj {
	NERVE(HostTypeWait);
	NERVE(HostTypeMove);
	NERVE(HostTypeDone);
}