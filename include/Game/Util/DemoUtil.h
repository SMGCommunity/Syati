#pragma once

#include "revolution.h"
#include "Game/Util/Functor.h"

class LayoutActor;
class LiveActor;
class NameObj;
class Nerve;
class TalkMessageCtrl;

namespace MR {
	bool tryRegisterDemoCast(LiveActor *, const JMapInfoIter &);
	void registerDemoActionFunctor(const LiveActor *, const MR::FunctorBase &, const char *);
	void registerDemoActionNerve(const LiveActor *, const Nerve *, const char *);
	bool tryRegisterDemoActionFunctor(const LiveActor *, const MR::FunctorBase &, const char *);
	bool tryRegisterDemoActionNerve(const LiveActor *, const Nerve *, const char *);
	bool tryRegisterDemoCast(LiveActor *, const char *, const JMapInfoIter &);
	bool registerDemoCast(LiveActor *, const char *, const JMapInfoIter &);
	bool initTalkAnimDemoCast(LiveActor *, const JMapInfoIter &, const char *, const char *);
	bool registerDemoActionFunctorDirect(const LiveActor *, const MR::FunctorBase &, const char *, const char *);

	void tryRegisterDemoActionFunctorDirect(const LiveActor *, bool, const MR::FunctorBase &, const char *, const char *);
	bool tryStartDemoRegistered(LiveActor *, const char *);
	bool tryStartDemoRegisteredMarioPuppetable(LiveActor *, const char *);
	void registerDemoSimpleCastAll(LiveActor *);
	void registerDemoSimpleCastAll(LayoutActor *);
	void registerDemoSimpleCastAll(NameObj *);
	bool isDemoCast(const LiveActor *, const char *);
	bool isRegisteredDemoActionAppear(const LiveActor *);
	bool isRegisteredDemoActionNerve(const LiveActor *);
	bool tryStartDemo(LiveActor *, const char *);
	bool tryStartDemo(LayoutActor *, const char *);

	bool tryStartDemoWithoutCinemaFrame(LiveActor *, const char *);

	bool tryStartDemoMarioPuppetable(LiveActor *, const char *);
	bool tryStartDemoMarioPuppetableWithoutCinemaFrame(LiveActor *, const char *);

	bool tryStartTimeKeepDemo(NameObj *, const char *, const char *);

	bool tryStartTimeKeepDemoMarioPuppetable(NameObj *, const char *, const char *);
	bool tryStartTimeKeepDemoMarioPuppetable(LiveActor *, const char *, const char *);

	bool requestStartDemo(LiveActor *, const char *, const Nerve *, const Nerve *);

	bool requestStartDemoWithoutCinemaFrame(LiveActor *, const char *, const Nerve *, const Nerve *);
	bool requestStartDemoWithoutCinemaFrame(LayoutActor *, const char *, const Nerve *, const Nerve *);
	bool requestStartDemoMarioPuppetable(LiveActor *, const char *, const Nerve *, const Nerve *);

	bool requestStartTimeKeepDemo(NameObj *, const char *, const char *);
	bool requestStartTimeKeepDemoMarioPuppetable(NameObj *, const char *, const char *);

	bool requestStartDemoRegisteredMarioPuppetable(LiveActor *, const Nerve *, const Nerve *, const char *);
	void endDemo(NameObj *, const char *);
	void endDemoWaitCameraInterpolating(NameObj *, const char *);

	void initDemoSheetTalkAnim(LiveActor *, JMapInfoIter const &, char const *, char const *, TalkMessageCtrl *, TVec3f, MtxPtr);
	bool tryInitDemoSheetTalkAnim(LiveActor *, JMapInfoIter const &, char const *, char const *, TalkMessageCtrl *, TVec3f, MtxPtr);

	bool isDemoExist(const char *);
	bool isDemoActive();
	bool isDemoActive(const char *);
	bool canStartDemo();
	bool isTimeKeepDemoActive();
	bool isDemoActiveRegistered(const LiveActor *);
	bool isDemoPartExist(const LiveActor *, const char *);
	bool isDemoLastStep();
	bool isDemoPartActive(const char *);
	bool isDemoPartStep(const char *, s32);
	bool isDemoPartFirstStep(const char *);
	bool isDemoPartLastStep(const char *);
	bool isDemoPartGreaterStep(const char *, s32);
	s32 getDemoPartTotalStep(const char *);
	f32 calcDemoPartStepRate(const char *);
	s32 getDemoPartStep(const char *);
	void pauseTimeKeepDemo(LiveActor *);
	void resumeTimeKeepDemo(LiveActor *);
	bool isPauseTimeKeepDemo(LiveActor *);
	bool isPowerStarGetDemoActive();

	const char* getCurrentDemoPartNameMain(const char *);

	bool isSystemTalking();
	bool isNormalTalking();
	LiveActor* getTalkingActor();
};

namespace DemoStartInfo {
	enum DemoType {
		DEMOTYPE_0,
	};

	enum CinemaFrameType {
		CINEMAFRAMETYPE_0,
		CINEMAFRAMETYPE_1,
	};

	enum StarPointerType {
		STARPOINTERTYPE_0,
	};

	enum DeleteEffectType {
		DELETEEFFECTYPE_0,
		DELETEEFFECTYPE_1,
	};
}

namespace DemoStartRequestUtil {
	void startDemoSystem(LiveActor*, const char*, s32, DemoStartInfo::DemoType, DemoStartInfo::CinemaFrameType, DemoStartInfo::StarPointerType, DemoStartInfo::DeleteEffectType, const char*);
};