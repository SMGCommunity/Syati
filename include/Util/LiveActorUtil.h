#pragma once

#include "JGeometry/TVec3.h"
#include "JGeometry/TPosition3.h"
#include "JGeometry/TMatrix34.h"
#include "JMap/JMapInfoIter.h"

#include "kamek.h"

class LiveActor;
class HitSensor;

namespace MR
{
    void validateClipping(LiveActor *);
    void invalidateClipping(LiveActor *);

    void setPosition(LiveActor *, const JGeometry::TVec3<f32> &);

    void initCollisionParts(LiveActor *, const char *, HitSensor *, Mtx4 *);

    void setBaseTRMtx(LiveActor *, Mtx);
    void setBaseTRMtx(LiveActor *, const JGeometry::TPosition3<JGeometry::TMatrix34<JGeometry::SMatrix34C<f32> > > &);

    void initDefaultPos(LiveActor *, const JMapInfoIter &);

    void setClippingTypeSphere(LiveActor *, f32);

    void setClippingFarMax(LiveActor *);

    void setClippingTypeSphereContainsModelBoundingBox(LiveActor *, f32);

    bool isDead(const LiveActor *);

    bool isOnGround(const LiveActor *);
    bool isBindedGround(const LiveActor *);

    void calcGravity(LiveActor *, const JGeometry::TVec3<f32> &);

    JGeometry::TVec3<f32>* getGroundNormal(const LiveActor *);

    void startBck(const LiveActor *, const char *);
    bool tryStartBck(const LiveActor *, const char *, const char *);
    void stopBck(const LiveActor *);
    bool isBckStopped(const LiveActor *);

    void setBckRate(const LiveActor *, f32);

    bool isActionEnd(const LiveActor *);

    bool isFirstStep(const LiveActor *);
    bool isStep(const LiveActor *, s32);
    bool isGreaterStep(const LiveActor *, s32);

    void invalidateCollisionParts(LiveActor *);
    void validateCollisionParts(LiveActor *);

    void addToAttributeGroupSearchTurtle(const LiveActor *);
};