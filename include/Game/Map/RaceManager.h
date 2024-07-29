#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"
#include "Game/Screen/LayoutActor.h"
#include "JSystem/JGeometry/TVec.h"
#include "Game/Map/StartCountdownLayout.h"

class AbstractRacer;
class PlayerRacer;
class AbstractAudience;
class RaceLayout;

class RaceManager : public LiveActor {
public:
    RaceManager();

    virtual ~RaceManager();
    virtual void init(const JMapInfoIter& rIter);
    virtual void movement();

    void exeWait();
    void exePrep();
    void exeWipeOut();
    void exeWipeWait();
    void exeWipeIn();
    void exeIntro();
    void exeCount();
    void exeRace();
    void exeDemo();
    void exeGoal();
    void exeRank();

    void prepRace();
    void startRace();
    void goalRace();
    void resetRace();
    void prepBind();
    void entry(AbstractRacer*);
    void entry(PlayerRacer*);
    void entry(AbstractAudience*);
    bool isGoal(const AbstractRacer*) const;
    s32 getRank(const AbstractRacer*) const;
    void renewTime();

    s32 _90; //_90
    StartCountdownLayout* mStartCountdownLayout; //_94
    RaceLayout* mRaceLayout; //_98
    s32 _9C;
    s32 _A0;
    s32 _A4;
    s32 _A8;
    s32 _AC;
    s32 _B0;
    s32 _B4;
    s32 _B8;
    s32 _BC;
    s32 _C0;
    s32 _C4;
    s32 _C8;
    s32 _CC;
    s32 _D0;
    s32 _D4;
    s32 _D8;
    s32 _DC;
    s32 _E0;
    s32 _E4;
    s32 _E8;
    s32 _EC;
    s32 _F0;
    s32 _F4; //RaceRank - Counts how many racers have finished the race
    s32 _F8;
    s32 _FC;
    LiveActor* _100; //Certainly the RaceRail*
    s32 _104;
    s32 _108;
};

namespace NrvRaceManager {
    NERVE(RaceManagerNrvPstWipeIn);
    NERVE(RaceManagerNrvPstWipeWait);
    NERVE(RaceManagerNrvPstWipeOut);
    NERVE(RaceManagerNrvRank);
    NERVE(RaceManagerNrvGoal);
    NERVE(RaceManagerNrvDemo);
    NERVE(RaceManagerNrvRace);
    NERVE(RaceManagerNrvCount);
    NERVE(RaceManagerNrvIntro);
    NERVE(RaceManagerNrvPreWipeIn);
    NERVE(RaceManagerNrvPreWipeWait);
    NERVE(RaceManagerNrvPreWipeOut);
    NERVE(RaceManagerNrvPrepImme);
    NERVE(RaceManagerNrvPrepWipe);
    NERVE(RaceManagerNrvWait);
    NERVE(RaceManagerNrvWaitAfterMiss);
};

class AbstractRacer {
public:
    virtual void initRacer();

    virtual void prepRacer(const RaceManager*) = 0;
    virtual void startRacer() = 0;
    virtual bool updateRacer(const RaceManager*) = 0;
    virtual bool goalRacer() = 0;
    virtual void loseRacer() = 0;
    virtual void resetRacer(const RaceManager*) = 0;
    virtual void exitRacer() = 0;
    //This is new to SMG2. Don't know what the actual name should be
    virtual void requestMovementOn() = 0;

    f32 _4; //_4  Position along the race path
    f32 _8; //_8
    TVec3f _C; //_C
    TVec3f _18; //_18
};

class RaceManagerFunction {
public:
    static void entryRacerOthers(AbstractRacer*);
    static void entryAudience(AbstractAudience*);
    static void entryRacerPlayer(PlayerRacer*);
    static void entryPlayerRide(LiveActor*);
    //there's one here that's missing still
    static void startRaceWithWipe();
    static void startRaceImmediately();
    static s32 getRaceRank();
    static s32 getRaceTime();
    static const char* getRaceName(s32);
    static s32 getRaceId(const char*);
    static void updateRank();
};