#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"
#include "Game/LiveActor/LodCtrl.h"
#include "Game/LiveActor/PartsModel.h"
#include "Game/Enemy/AnimScaleController.h"
#include "Game/Player/YoshiLockOnTarget.h"
#include "Game/NPC/TalkMessageCtrl.h"

class NPCActorItem;
class NPCActorCaps;
class JointController;
class JointControllerInfo;

class NPCActor : public LiveActor {
public:
    NPCActor(const char *pName);
    
    virtual ~NPCActor();
    virtual void init(const JMapInfoIter &rIter);
    virtual void initAfterPlacement();
    virtual void makeActorAppeared();
    virtual void kill();
    virtual void makeActorDead();
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual void attackSensor(HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveMsgEnemyAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveOtherMsg(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    virtual bool isReactionNerve() const;
    virtual bool isSensorSpinCloudBlock(const HitSensor *pSensor) const;

    void setBaseMtx(const TPos3f &);
    void setInitPose();
    void initialize(const JMapInfoIter &, const NPCActorCaps &, const char *, const char *, bool);
    void equipment(const NPCActorItem &, bool);
    void initTalkCtrl(const JMapInfoIter &, const char *, const TVec3f &, MtxPtr);
    void initTalkCtrlDirect(const JMapInfoIter &, const char *, const TVec3f &, MtxPtr);
    bool calcJointScale(TPos3f*, const JointControllerInfo &);
    void turnToPlayer();
    void turnToPlayer(f32);
    void turnToPlayer(f32, f32, f32);
    void turnToDefault(f32);
    void setToDefault();

    void pushNerve(const Nerve *);
    void popAndPushNerve(const Nerve *);
    void popNerve();
    void tryPushNullNerve();
    bool isEmptyNerve() const;
    bool isScaleAnim() const;
    bool isPointingSe() const;
    void updateReaction();
    void updateScaleCtrl();
    void exeWait();
    void exeTalk();

    LodCtrl* mLodCtrl;               // _90
    TalkMessageCtrl* mTalkCtrl;      // _94
    PartsModel* mGoodsModel0;        // _98
    PartsModel* mGoodsModel1;        // _9C
    s32 mTrampleAttackDelay;         // _A0
    TQuat4f mTurnDir;                // _A4
    TQuat4f _B4;
    TVec3f _C4;
    TVec3f _D0;
    bool mReactTrampleAttack;        //  0xDC
    bool mReactSpinAttack;           //  0xDD
    bool mReact2PPointerAttached;    //  0xDE
    bool mReactStarPieceAttack;      //  0xDF
    bool mReactJetTurtleAttack;      //  0xE0
    bool mConsumedTrampleAttack;     //  0xE1
    bool mConsumedSpinAttack;        //  0xE2
    bool mConsumed2PPointerAttached; //  0xE3
    bool mConsumedStarPieceAttack;   //  0xE4
    bool mConsumedJetTurtleAttack;   //  0xE5
    bool mRequestTrampleAttack;      //  0xE6
    bool mRequestSpinAttack;         //  0xE7
    bool mRequest2PPointerAttached;  //  0xE8
    bool mRequestStarPieceAttack;    //  0xE9
    bool mRequestJetTurtleAttack;    //  0xEA
    bool mRequestSupportTicoSpin;    //  0xEB
    bool mEnableTurn;                //  0xEC
    bool mEnableTalkTurn;            //  0xED
    f32 mTurnDist;                   //  0xF0 : How close to the NPC you have to be for it to rotate to face the player
    f32 mTurnSpeed;                  //  0xF4 : How fast the NPC turns to face the player
    f32 _F8;                         //  0xF8 : turning-related
    f32 _FC;                         //  0xFC : turning-related
    const char* mActionWait;         // 0x100
    const char* mActionWaitTurn;     // 0x104
    const char* mActionTalk;         // 0x108
    const char* mActionTalkTurn;     // 0x10C
    f32 _110;                        // 0x110 : Walk speed, but changing this doesn't instantly change the speed, it interpolates
    f32 _114;
    f32 _118;
    f32 _11C;
    const char* mActionWalkName; // Walk Animation name
    const char* mActionWalkTalkName; // Walk Talk animation name
    bool mRailSnapToGround; // if true, the NPC is moved along the Rail at the nearest ground point
    bool _129; // unused
    bool _12A; // unused
    bool _12B; // unused
    bool _12C; // AnimScale related. (NPCActor::updateScaleCtrl)
    f32 mSpinDist;                         // 0x130 : How close to the NPC you have to be to be able to spin them.
    const char* mActionSpinName;           // 0x134
    const char* mActionTrampledName;       // 0x138
    const char* mActionPointingName;       // 0x13C
    const char* mActionReactionName;       // 0x140
    AnimScaleController* mAnimScaleCtrl;   // 0x144
    JointController* mJointCtrlParam;      // 0x148
    YoshiLockOnTarget* mYoshiLockOnTarget; // 0x14C
    const Nerve* mPushedNerve;             // 0x150
    const Nerve* mWaitNerve;               // 0x154
    const Nerve* mTalkNerve;               // 0x158
    const Nerve* mReactionNerve;           // 0x15C
    s32 mReact2PPointerAttachedDelay;      // 0x160
};

namespace NrvNPCActor {
	NERVE(NPCActorNrvReaction);
	NERVE(NPCActorNrvWait);
	NERVE(NPCActorNrvTalk);
	NERVE(NPCActorNrvNull);
};

class NPCActorItem {
public:
    inline NPCActorItem(const char *pName, const char* __4, const char* __8, const char *__C, const char* __10) {
        mName = pName;
        _4 = __4;
        _8 = __8;
        _C = __C;
        _10 = __10;
    }

    const char* mName;  // _0
    const char* _4;
    const char* _8;
    const char* _C;
    const char* _10;
};

class NPCActorCaps {
public:
    NPCActorCaps(const char *);

    void setDefault();

    const char* _0;
    bool mInitModel;                     // _4
    const char* mModelName;              // _8
    bool mInitAppear;                    // _C
    bool _D;
    bool mInitTalkCtrl;                  // _E
    bool mUseDirectTalk;                 // _F
    const char* mTalkMsgLabel;           // _10
    TVec3f mTalkOffset;                  // _14
    MtxPtr mTalkMtx;                     // _20
    const char* mTalkJoint;              // _24
    bool _28;
    bool mInitScene;                     // _29
    bool mInitLightCtrl;                 // _2A
    bool mInitEffectKeeper;              // _2B
    bool mInitSound;                     // _2C
    const char* mSoundObjName;           // _30
    s32 mSoundObjsCount;                 // _34
    bool mInitSearchTurtle;              // _38
    bool mInitDefaultPos;                // _39
    bool mInitLodCtrlNPC;                // _3A
    bool mInitSpine;                     // _3B
    s32 mSpineStateCount;                // _3C
    bool mInitBinder;                    // _40
    f32 mBinderRadius;                   // _44
    bool mInitHitSensor;                 // _48
    const char* mBodySensorJoint;        // _4C
    f32 mBodySensorRadius;               // _50
    TVec3f mBodySensorOffset;            // _54
    s32 mHitSensorCount;                 // _60
    bool mInitSphereShadow;              // _64
    bool mInitBcsvShadow;                // _65
    f32 mSphereShadowRadius;             // _68
    bool mInitRailRider;                 // _6C
    bool mUseSwitchWriteDead;            // _6D
    bool mUseStageSwitchSyncAppear;      // _6E
    bool mInitDead;                      // _6F
    bool mInitStarPointerTarget;         // _70
    const char* mStarPointerTargetJoint; // _74
    const char* mJointCtrlName;          // _78
    bool _7C;
    TVec3f mStarPointerTargetOffset;     // _80
    f32 mStarPointerTargetRadius;        // _8C
    s32 mSceneType;                      // _90
    bool mReactSupportTicoSpin;          // _94
    bool mInitYoshiLockOnTarget;         // _95
    Nerve* mWaitNerve;                   // _98
    Nerve* mTalkNerve;                   // _9C
    Nerve* mReactionNerve;               // _A0
};

namespace MR {
    void startMoveAction(NPCActor* actor);
    bool tryStartReactionAndPushNerve(NPCActor* actor, const Nerve* nerve);
    bool tryTalkNearPlayerAndStartMoveTalkAction(NPCActor* actor);
}