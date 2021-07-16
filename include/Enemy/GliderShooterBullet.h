#include "LiveActor/LiveActorGroup.h"
#include "Enemy/WalkerStateBindStarPointer.h"

class GliderShooterBullet : public LiveActor
{
public:
	GliderShooterBullet();

	virtual ~GliderShooterBullet();
	virtual void init(const JMapInfoIter &);
	virtual void appear();
	virtual void kill();
	virtual void control();
	virtual void calcAndSetBaseMtx();
	virtual void attackSensor(HitSensor *, HitSensor *);
	virtual bool receiveMsgEnemyAttack(u32, HitSensor *, HitSensor *);

	void exeFly();
	void exeFreeze();

	TVec3f _90;
	TVec3f _9C;
	AnimScaleController* mAnimScaleCtrl; // _A8
	WalkerStateBindStarPointer* mBindStarPointer; // _AC
};

class GliderShooterBulletHolder : public LiveActorGroup
{
public:
	GliderShooterBulletHolder();

	virtual ~GliderShooterBulletHolder();
	virtual void init(const JMapInfoIter &);
};
