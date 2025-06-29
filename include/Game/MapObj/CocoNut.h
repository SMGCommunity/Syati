#pragma once

#include "Game/LiveActor/LiveActor.h"

class CocoNut : public LiveActor {
public:
	CocoNut(const char*);

	virtual ~CocoNut();
	virtual void init(const JMapInfoIter&);
	virtual void initAfterPlacement();
	virtual void startClipped();
	virtual void calcAndSetBaseMtx();
	virtual void attackSensor(HitSensor*, HitSensor*);
	virtual bool receiveMsgPush(HitSensor*, HitSensor*);
	virtual bool receiveMsgPlayerAttack(u32, HitSensor*, HitSensor*);
	virtual bool receiveOtherMsg(u32, HitSensor*, HitSensor*);

	void initMapToolInfo(const JMapInfoIter&);
	void initSensor();
	void initEffect();
	void updateRotate(f32);
	void updateGravity();
	void processMove();
	bool isOnGround() const;
	f32 calcMoveSpeed() const;
	void setFrontVec(const TVec3f&);
	bool getWallNormal(TVec3f*) const;
	
	bool sendMsgToBindedSensor();
	bool sendMsgEnemyAttackToBindedSensor(HitSensor*);
	
	bool tryHit(HitSensor*, HitSensor*);
	bool isPossibleToHit(const TVec3f&, const TVec3f&, const TVec3f&) const;
	void calcHitSpeedAndFrontVec(f32*, f32*, TVec3f*, TVec3f*, const TVec3f&, const TVec3f&) const;
	void hit(const TVec3f&, f32);
	bool tryPushedFromActor(HitSensor*, HitSensor*);

	void reviseFrontVec();
	void statusToWait();
	bool isValidReceiveMsg(const HitSensor*) const;
	void statusToHide();
	void emitEffectSpinHit(const HitSensor*, const HitSensor*);
	bool tryMoveEnd();
	bool tryDisappear();
	bool isContactWithOtherCocoNut() const;
	bool isValidPushedFromPlayer(const HitSensor*, const HitSensor*) const;

	const char* getModelName();
	const char* getBreakEffectName();

	void exeWait();
	void exeWaitOnBind();
	void exeMove();
	void exeInWater();
	void exeBreak();

	f32 _90;
	f32 _94; // something gravity/speed related
	TVec3f mFrontVec; // 0x98
	TMtx34f _A4;
	f32 mRadius; // 0xD4 (55.0f * mScale.x)
	bool mIsWaiting; // 0xD8
	TMtx34f mEffectHostMtx; // 0xDC
	TMtx34f _10C;
	s32 _13C;
	bool _140; // something gravity related
	TVec3f mSpawnPos; // 0x144
	bool _150;
	TVec3f _154;
	bool mUseSphericalShadow; // 0x160 (obj_arg0)
	bool mRespawnOutOfView; //  0x161 (obj_arg1)
	bool _162; // something clipping related
	bool mContinueRolling; // 0x163 (obj_arg2)
};

namespace NrvCocoNut {
	NERVE(CocoNutNrvWait);
	NERVE(CocoNutNrvWaitOnBind);
	NERVE(CocoNutNrvMove);
	NERVE(CocoNutNrvInWater);
	NERVE(CocoNutNrvBreak);
	NERVE(CocoNutNrvReplaceReady);
}
