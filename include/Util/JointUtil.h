#pragma once

#include "kamek.h"
#include "JGeometry/TMatrix34.h"

class J3DModel;
class J3DJoint;
class LiveActor;

namespace MR
{
    J3DJoint* getJoint(J3DModel *, const char *);
    J3DJoint* getJoint(const LiveActor *, const char *);
    J3DJoint* getJoint(const LiveActor *, u16);
    JGeometry::TMatrix34<f32>* getJointMtx(J3DModel *, const char *);
    JGeometry::TMatrix34<f32>* getJointMtx(const LiveActor *, const char *);
    JGeometry::TMatrix34<f32>* getJointMtx(const LiveActor *, s32);
    // unknown function at 8002D5C0
    s16 getJointIndex(const LiveActor *, const char *);
    const char* getJointName(const LiveActor *, s32);
    s16 getJointNum(const LiveActor *);
    bool isExistJoint(const LiveActor *, const char *);

    void copyJointPos(const LiveActor *, const char *, TVec3f *);
};
