#pragma once

#include "JGeometry/TVec3.h"
#include "JGeometry/TPosition3.h"
#include "JGeometry/TMatrix34.h"
#include "JMap/JMapInfoIter.h"

#include "kamek.h"

class LiveActor;
class HitSensor;
class PartsModel;

namespace MR
{
    void setPosition(LiveActor *, const JGeometry::TVec3<f32> &);
    void setPosition(LiveActor *, f32, f32, f32);
    void setRotation(LiveActor *, const JGeometry::TVec3<f32> &);
    void setRotation(LiveActor *, f32, f32, f32);
    void setRotation(LiveActor *, f32);

    void copyTransRotateScale(const LiveActor *, LiveActor *);

    void calcAnimDirect(LiveActor *);
    void setClippingTypeSphere(LiveActor *, f32);

    void setClippingFarMax(LiveActor *);

    void setClippingTypeSphereContainsModelBoundingBox(LiveActor *, f32);

    void setGroupClipping(LiveActor *, const JMapInfoIter &, int);
    void validateClipping(LiveActor *);
    void invalidateClipping(LiveActor *);

    void setBaseTRMtx(LiveActor *, Mtx4 *);
    void setBaseTRMtx(LiveActor *, const TPositionMtx &);

    void setBaseScale(LiveActor *, const JGeometry::TVec3<f32> &);

    f32 getBckFrame(const LiveActor *);
    f32 getBtkFrame(const LiveActor *);
    f32 getBrkFrame(const LiveActor *);
    f32 getBtpFrame(const LiveActor *);
    f32 getBvaFrame(const LiveActor *);
    f32 getBckRate(const LiveActor *);
    f32 getBtkRate(const LiveActor *);
    f32 getBrkRate(const LiveActor *);
    f32 getBtpRate(const LiveActor *);
    f32 getBpkRate(const LiveActor *);
    f32 getBvaRate(const LiveActor *);
    f32 getBckFrameMax(const LiveActor *);
    f32 getBtkFrameMax(const LiveActor *);
    f32 getBrkFrameMax(const LiveActor *);
    f32 getBtpFrameMax(const LiveActor *);
    f32 getBvaFrameMax(const LiveActor *);

    void initLightCtrl(LiveActor *);

    bool isStep(const LiveActor *, s32);
    bool isFirstStep(const LiveActor *);
    bool isLessStep(const LiveActor *, s32);
    bool isLessEqualStep(const LiveActor *, s32);
    bool isGreaterStep(const LiveActor *, s32);
    bool isGreaterEqualStep(const LiveActor *, s32);
    bool isIntervalStep(const LiveActor *, s32);
    bool isNewNerve(const LiveActor *, s32);
    f32 calcNerveRate(const LiveActor *, s32);
    f32 calcNerveRate(const LiveActor *, s32, s32);
    f32 calcNerveEaseInRate(const LiveActor *, s32);
    f32 calcNerveEaseOutRate(const LiveActor *, s32);
    f32 calcNerveEaseOutRate(const LiveActor *, s32, s32);
    f32 calcNerveEaseInOutRate(const LiveActor *, s32);
    f32 calcNerveEaseInOutRate(const LiveActor *, s32, s32);
    f32 calcNerveValue(const LiveActor *, s32, f32, f32);
    f32 calcNerveValue(const LiveActor *, s32, s32, f32, f32);

    bool isOnGround(const LiveActor *);

    bool isBindedGround(const LiveActor *);

    JGeometry::TVec3<f32>* getGroundNormal(const LiveActor *);
    JGeometry::TVec3<f32>* getWallNormal(const LiveActor *);
    JGeometry::TVec3<f32>* getRoofNormal(const LiveActor *);
    JGeometry::TVec3<f32>* getBindedNormal(const LiveActor *);

    bool isDead(const LiveActor *);

    void showModel(LiveActor *);

    void hideModel(LiveActor *);

    bool isNoBind(const LiveActor *);
    void onBind(const LiveActor *);
    void offBind(const LiveActor *);
    bool isCalcGravity(const LiveActor *);
    void onCalcGravity(const LiveActor *);
    void offCalcGravity(const LiveActor *);

    void joinToGroup(LiveActor *, const char *);
    void joinToGroupArray(LiveActor *, const JMapInfoIter &, const char *, s32);

    void addToAttributeGroupSearchTurtle(const LiveActor *);

    void calcGravity(LiveActor *);
    void calcGravity(LiveActor *, const JGeometry::TVec3<f32> &);

    void initCollisionParts(LiveActor *, const char *, HitSensor *, Mtx4 *);

    void validateCollisionParts(LiveActor *);

    void invalidateCollisionParts(LiveActor *);

    PartsModel* createPartsModelNoSilhouettedMapObj(LiveActor *, const char *, const char *, Mtx4 *);

    void tryRumblePadAndCameraDistanceStrong(const LiveActor *, f32, f32, f32);
};
