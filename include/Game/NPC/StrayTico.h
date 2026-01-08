#pragma once

#include "Game/LiveActor/LiveActor.h"
#include "Game/LiveActor/PartsModel.h"

class CollectTico;

class StrayTico : public LiveActor {
public:
	StrayTico(const char*, CollectTico*);

	virtual ~StrayTico();
	virtual void init(const JMapInfoIter& rIter);
	virtual void appear();
	virtual void control();
	virtual void calcAndSetBaseMtx();
	virtual void attackSensor(HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveMsgPush(HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveOtherMsg(u32 msg, HitSensor* pSender, HitSensor* pReceiver);

	void initSensor();
	void initShadow();
	void startGlad();
	void launch(const TPos3f&);
	void updateWarp();
	void updateChase();
	bool tryStartBindMove() const;
	bool tryEndBindMove() const;
	bool tryNigeroDrop() const;
	bool requestCompleteDemo(const TVec3f&, const TVec3f&, f32); // Always returns true...

	void exeWait();
	void exeGlad();
	void exeChase();
	void exeLauncherCamera(); // Referring to MarioLauncher (player cannon)
	void exeBindMove();
	void exeBindEnd();
	void exeCompleteDemo();

	bool isNigeroTakeable() const;
	bool isEnableSpin() const;
	bool isRescued() const;
	bool isCompleteDemoEnd() const;
	void noticeEnd();

	CollectTico* mCollectTico; // 0x90
	PartsModel* mItemBubble; // 0x94
	TQuat4f _98; // 0x98
	TVec3f _A8; // 0xA8
	TVec3f _B4; // 0xB4
	TVec3f _C0; // 0xC0
	TVec3f _CC; // 0xCC
	TVec3f _D8; // 0xD8
	f32 _F0; // 0xF0
	f32 _F4; // 0xF4
};

namespace NrvStrayTico {
	NERVE(StrayTicoNrvWait);
	NERVE(StrayTicoNrvGlad);
	NERVE(StrayTicoNrvChase);
	NERVE(StrayTicoNrvLauncherCamera);
	NERVE(StrayTicoNrvCompleteDemo);
	NERVE(StrayTicoNrvBindMove);
	NERVE(StrayTicoNrvBindEnd);
}