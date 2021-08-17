#pragma once

#include "JGeometry/TPosition3.h"
#include "JGeometry/TVec3.h"
#include "JMap/JMapInfoIter.h"

// Complete
namespace MR
{
    bool isValidInfo(const JMapInfoIter &);
    void getObjectName(const char **, const JMapInfoIter &);
    bool isObjectName(const JMapInfoIter &, const char *);

    bool getJMapInfoArgNoInit(const JMapInfoIter &, const char *, s32 *);
    bool getJMapInfoArgNoInit(const JMapInfoIter &, const char *, f32 *);
    bool getJMapInfoArgNoInit(const JMapInfoIter &, const char *, bool *);
    bool isExistJMapInfoArg0(const JMapInfoIter &);

    bool getJMapInfoShapeIdWithInit(const JMapInfoIter &, s32 *);
    bool getJMapInfoAreaIdWithInit(const JMapInfoIter &, s32 *);

    bool getJMapInfoTransLocal(const JMapInfoIter &, TVec3f *);
    bool getJMapInfoTrans(const JMapInfoIter &, TVec3f *);
    bool getJMapInfoRotateLocal(const JMapInfoIter &, TVec3f *);
    bool getJMapInfoRotate(const JMapInfoIter &, TVec3f *);
    bool getJMapInfoScale(const JMapInfoIter &, TVec3f *);
    bool getJMapInfoMatrixFromRT(const JMapInfoIter &, TPositionMtx *);
    bool getJMapInfoV3f(const JMapInfoIter &, const char *, TVec3f *);

    bool getJMapInfoArg0WithInit(const JMapInfoIter &, s32 *);
    bool getJMapInfoArg0WithInit(const JMapInfoIter &, f32 *);
    bool getJMapInfoArg0WithInit(const JMapInfoIter &, bool *);
    bool getJMapInfoArg1WithInit(const JMapInfoIter &, s32 *);
    bool getJMapInfoArg1WithInit(const JMapInfoIter &, f32 *);
    bool getJMapInfoArg1WithInit(const JMapInfoIter &, bool *);
    bool getJMapInfoArg2WithInit(const JMapInfoIter &, s32 *);
    bool getJMapInfoArg2WithInit(const JMapInfoIter &, f32 *);
    bool getJMapInfoArg2WithInit(const JMapInfoIter &, bool *);
    bool getJMapInfoArg3WithInit(const JMapInfoIter &, s32 *);
    bool getJMapInfoArg3WithInit(const JMapInfoIter &, bool *);
    bool getJMapInfoArg4WithInit(const JMapInfoIter &, bool *);
    bool getJMapInfoArg5WithInit(const JMapInfoIter &, s32 *);
    bool getJMapInfoArg6WithInit(const JMapInfoIter &, s32 *);
    bool getJMapInfoArg7WithInit(const JMapInfoIter &, s32 *);
    bool getJMapInfoArg7WithInit(const JMapInfoIter &, bool *);

    bool getJMapInfoArg0NoInit(const JMapInfoIter &iter, s32 *out);
    bool getJMapInfoArg0NoInit(const JMapInfoIter &iter, f32 *out);
    bool getJMapInfoArg0NoInit(const JMapInfoIter &iter, bool *out);
    bool getJMapInfoArg1NoInit(const JMapInfoIter &iter, s32 *out);
    bool getJMapInfoArg1NoInit(const JMapInfoIter &iter, f32 *out);
    bool getJMapInfoArg1NoInit(const JMapInfoIter &iter, bool *out);
    bool getJMapInfoArg2NoInit(const JMapInfoIter &iter, s32 *out);
    bool getJMapInfoArg2NoInit(const JMapInfoIter &iter, f32 *out);
    bool getJMapInfoArg2NoInit(const JMapInfoIter &iter, bool *out);
    bool getJMapInfoArg3NoInit(const JMapInfoIter &iter, s32 *out);
    bool getJMapInfoArg3NoInit(const JMapInfoIter &iter, f32 *out);
    bool getJMapInfoArg3NoInit(const JMapInfoIter &iter, bool *out);
    bool getJMapInfoArg4NoInit(const JMapInfoIter &iter, s32 *out);
    bool getJMapInfoArg4NoInit(const JMapInfoIter &iter, f32 *out);
    bool getJMapInfoArg4NoInit(const JMapInfoIter &iter, bool *out);
    bool getJMapInfoArg5NoInit(const JMapInfoIter &iter, s32 *out);
    bool getJMapInfoArg5NoInit(const JMapInfoIter &iter, f32 *out);
    bool getJMapInfoArg5NoInit(const JMapInfoIter &iter, bool *out);
    bool getJMapInfoArg6NoInit(const JMapInfoIter &iter, s32 *out);
    bool getJMapInfoArg6NoInit(const JMapInfoIter &iter, f32 *out);
    bool getJMapInfoArg6NoInit(const JMapInfoIter &iter, bool *out);
    bool getJMapInfoArg7NoInit(const JMapInfoIter &iter, s32 *out);
    bool getJMapInfoArg7NoInit(const JMapInfoIter &iter, f32 *out);
    bool getJMapInfoArg7NoInit(const JMapInfoIter &iter, bool *out);

    bool getJMapInfoFollowID(const JMapInfoIter &, s32 *);
    bool getJMapInfoGroupID(const JMapInfoIter &, s32 *);
    bool getJMapInfoClippingGroupID(const JMapInfoIter &, s32 *);
    bool getJMapInfoDemoGroupID(const JMapInfoIter &, s32 *);
    bool getJMapInfoLinkID(const JMapInfoIter &, s32 *);
    bool getJMapInfoPriorityWithInit(const JMapInfoIter &, s32 *);

    bool isConnectedWithRail(const JMapInfoIter &);
    bool isExistStageSwitchA(const JMapInfoIter &);
    bool isExistStageSwitchB(const JMapInfoIter &);
    bool isExistStageSwitchAppear(const JMapInfoIter &);
    bool isExistStageSwitchDead(const JMapInfoIter &);
    bool isExistStageSwitchAwake(const JMapInfoIter &);
    bool isExistStageSwitchParam(const JMapInfoIter &);
    bool isExistMessageId(const JMapInfoIter &);
    bool isEqualObjectName(const JMapInfoIter &, const char *);

    bool getJMapInfoCameraSetID(const JMapInfoIter &, s32 *);
    bool getJMapInfoViewGroupID(const JMapInfoIter &, s32 *);
    bool getJMapInfoMessageID(const JMapInfoIter &, s32 *);
    bool getParamScale(const JMapInfoIter &, f32 *);

    s32 getDemoCastID(const JMapInfoIter &);
    const char* getDemoName(const JMapInfoIter &);
    const char* getTimeSheetName(const JMapInfoIter &);
    s32 getDemoGroupID(const JMapInfoIter &);
    s32 getDemoGroupLinkID(const JMapInfoIter &);
    bool getDemoSkip(const JMapInfoIter &);

    bool getJMapInfoRailArg(const JMapInfoIter &, const char *, s32 *);
    bool getJMapInfoRailArg0NoInit(const JMapInfoIter &, s32 *);
    bool getRailId(const JMapInfoIter &, s32 *);
    bool getNextLinkRailId(const JMapInfoIter &, s32 *);
    bool isEqualRailUsage(const JMapInfoIter &, const char *);
    void getRailPointPos0(const JMapInfoIter &, TVec3f *);
    void getRailPointPos1(const JMapInfoIter &, TVec3f *);
    void getRailPointPos2(const JMapInfoIter &, TVec3f *);
    bool isLoopRailPathIter(const JMapInfoIter &);

    void getLinkObjID(const JMapInfoIter &, s32 *);
    void getMapPartsID(const JMapInfoIter &, s32 *);
    void getGeneratorID(const JMapInfoIter &, s32 *);
};
