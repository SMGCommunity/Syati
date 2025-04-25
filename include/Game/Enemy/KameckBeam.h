#pragma once

#include "Game/LiveActor/LiveActor.h"

class KameckBeamEventListener {
public:
    KameckBeamEventListener();

    virtual void hitBeam(s32);
};

class KameckBeamCollisionFilter {
public:
    KameckBeamCollisionFilter(const TVec3f*, f32);

    virtual bool isInvalidParts(const CollisionParts*) const;

    TVec3f* mPosition; // 0x04 (Used in vanilla to determine if it's inside a "ClipArea", which is used for the Matter Splatter effect)
    // 0x08 was removed in SMG2. Seems to not be needed anymore anyways
};

// This new new to SMG2
// Took quite a while to understand but I like how it works actually.
class AbstractKameckBeamActor {
public:
    AbstractKameckBeamActor(); //0x801A7E10

    virtual void summon(const TVec3f& position, const TVec3f& direction); // Called when the beam is supposed to spawn stuff (usually after hitting the ground)
    virtual bool tryStorm(); // Called when the beam is travelling, and the player spins nearby. Only used by the Koopa Shell beam. Return true to have the beam be killed by a spin attack, and false for being immune to spins
    virtual void reset(); // Called when the beam is being reset.
    virtual bool isDead(); // Called every frame that the actor is active

    void setEventListener(KameckBeamEventListener*);
    void callEventListener(); // Calls mHitBeamEventListener. Only used by Fireballs and Koopa Shells in vanilla.

    KameckBeamEventListener* mHitBeamEventListener; // 0x04
};


class KameckBeam : public LiveActor {
public:
    KameckBeam(const char*, s32, s32);

    virtual ~KameckBeam();
    virtual void init(const JMapInfoIter&);
    virtual void calcAnim();
    virtual void kill();
    virtual void control();
    virtual void attackSensor(HitSensor* pSender, HitSensor* pReceiver);
    virtual bool receiveOtherMsg(u32 msg, HitSensor* pSender, HitSensor* pReceiver);

    void setWandLocalPosition(const TVec3f&);
    void setEventListener(KameckBeamEventListener*);
    void resetBeam();
    bool requestFollowWand(MtxPtr, f32);
    //void requestShootToPlayerGround(f32); // Removed in SMG2, as it was only used by Kamella
    void requestShootToPlayerCenter(f32);
    void requestShoot(const TVec3f&, f32);
    void requestStorm(HitSensor*, HitSensor*);
    bool tryShootEnd();
    bool trySummon(); // New to SMG2

    void exeShoot();
    void exeExplosion();
    void exeActive(); // New to SMG2

    bool sendMsgEnemyAttack(HitSensor*, HitSensor*); // New to SMG2
    void startBeamLevelSound();
    void emitBeamReadyEffect();
    void emitBeamEffect();
    void emitBeamBreakEffect(); // New to SMG2

    KameckBeamEventListener* mHitBeamEventListener; // 0x90
    AbstractKameckBeamActor* mBeamActors[3]; // 0x94 - 0x9C
    MtxPtr mWandJointPos; // 0xA0 Should be a joint on a Kameck instance.
    TVec3f mTargetPos; // 0xA4 World Position that the beam is shot at
    TVec3f mWandLocalPosition; // 0xB0 A local position when being held by Kameck
    s32 mBeamType; // 0xBC
    s32 mProjCount; // 0xC0 LIMIT 3
};

namespace MR {
    void setKameckBeamCollisionFilter(LiveActor*);
}

namespace NrvKameckBeam {
    NERVE(KameckBeamNrvFollowWand);
    NERVE(KameckBeamNrvShoot);
    NERVE(KameckBeamNrvExplosion);
    NERVE(KameckBeamNrvActive); // New to SMG2. Used while the entity summoned is still alive.
}