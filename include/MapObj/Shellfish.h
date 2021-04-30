#pragma once

#include "Actor/LiveActor/LiveActor.h"
#include "Actor/Enemy/AnimScaleController.h"
#include "Actor/Enemy/WalkerStateBindStarPointer.h"

class Shellfish : public LiveActor
{
public:
	Shellfish(const char *);

	virtual ~Shellfish();
	virtual void init(const JMapInfoIter &);
	virtual void initAfterPlacement();
	virtual void control();
	virtual void calcAndSetBaseMtx();
	virtual void attackSensor(HitSensor *, HitSensor *);
	virtual u32 receiveMsgPlayerAttack(u32, HitSensor *, HitSensor *);

	void exeWait();
	void exeOpen();
	void exeCloseSignal();
	void exeClose();
	void exeShock();
	void initItem(const JMapInfoIter &);
	void initCoin(const JMapInfoIter &);
	void initYellowChip(const JMapInfoIter &);
	void initKinokoOneUp(const JMapInfoIter &);
	void startBindItem();
	void endBindItem();
	void putItem();

	AnimScaleController* mAnimScaleController;
	WalkerStateBindStarPointer* mBindStarPointer;
	LiveActor* mItem;
	s32 mItemType;
	bool mBindItem;
	u32* mBodyCollision;
};
