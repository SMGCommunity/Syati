#pragma once

#include "kamek.h"
#include "JGeometry/TVec3.h"

class LiveActor;
class HitSensor;

namespace MR
{
    HitSensor* getSensor(LiveActor *, const char *);
    void addBodyMessageSensorMapObj(LiveActor *);
    HitSensor* addHitSensorMapObj(LiveActor *, const char *, u16, f32, const JGeometry::TVec3<f32> &);
    HitSensor* addHitSensorMapObjMoveCollision(LiveActor *, const char *, u16, f32, const JGeometry::TVec3<f32> &);
    void addBodyMessageSensor(LiveActor *, u32);

    void addHitSensor(LiveActor *, const char *, u32, u16, float, const JGeometry::TVec3<f32> &);

    bool isSensorPlayer(const HitSensor *);
    void sendMsgPush(HitSensor *, HitSensor *);

    bool isMsgPlayerUpperPunch(u32);

    bool isMsgPlayerHipDropFloor(u32);

    bool isMsgJetTurtleAttack(u32);
};