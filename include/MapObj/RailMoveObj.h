#pragma once

#include "Actor/LiveActor/LiveActor.h"
#include "MapObj/MapObjActor.h"
#include "MapObj/MapObjActorInitInfo.h"
#include "JGeometry/TVec3.h"

class RailMoveObj : public MapObjActor
{
public:
	RailMoveObj(const char *);

	virtual ~RailMoveObj();

	virtual void startClipped();
	virtual void endClipped();

	virtual u32 receiveOtherMsg(u32, HitSensor *, HitSensor *);

	virtual void initCaseUseSwitchB(const MapObjActorInitInfo &);
	virtual void initCaseNoUseSwitchB(const MapObjActorInitInfo &);

	virtual void initDemoAction(); //Located at 0x802E9BB0 USA
	virtual void setupInitInfo(const JMapInfoIter &, MapObjActorInitInfo &);
	virtual void tryStartMove();
	virtual void startMoveInner();
	virtual void move();
	virtual void doAtEndPoint();
	virtual void endMove();
	virtual void getSoundCalcPos();

	void exeDemo();
	void exeWait();
	void exeMove();

	TVec3f _D0; //Clipping related, used by the Init function for the MR::initAndSetRailClipping function call
	bool isRailMoverWorking; //_D4  -Only used in exeMove, it is always set to the result of MapObjActorUtil::isRailMoverWorking. Probably used to see if the rail mover hasn't started yet
};

namespace NrvRailMoveObj {
	class NrvWait : public Nerve
	{
		NrvWait() {}
		virtual void execute(Spine*) const;

		static NrvWait sInstance;
	};

	class NrvWaitForPlayerOn : public Nerve
	{
		NrvWaitForPlayerOn() {}
		virtual void execute(Spine*) const;

		static NrvWaitForPlayerOn sInstance;
	};

	class NrvMove : public Nerve
	{
		NrvMove() {}
		virtual void execute(Spine*) const;

		static NrvMove sInstance;
	};

	class NrvDone : public Nerve
	{
		NrvDone() {}
		virtual void execute(Spine*) const;

		static NrvDone sInstance;
	};

	class NrvDemoPlay : public Nerve
	{
		NrvDemoPla() {}
		virtual void execute(Spine*) const;

		static NrvDemoPla sInstance;
	};
}