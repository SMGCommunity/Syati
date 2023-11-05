#pragma once

#include "syati.h"

class CollapsePlane : public MapObjActor {
public:
    CollapsePlane(const char* pName);
    virtual void init(const JMapInfoIter& rIter);
    void exeWait();
    void exeCollapse();
    void exeDPDStop();
    virtual void calcAndSetBaseMtx();
    virtual void control();
    void calcJointPlane(TMtx34f* pMtx, const JointControllerInfo& info);

    void exeWaitAfterCollapsed(); // NEW
    void exeReturn(); // NEW

    s32 _D0;
    s32 _D4;
    s32 _D8;
    s32 _DC;
    s32 _E0;
    s32 mRespawnTime; // 0xE4 NEW
};

#if defined USA || defined PAL || defined JPN
namespace NrvCollapsePlane {
    NERVE(CollapsePlaneNrvWait);
    NERVE(CollapsePlaneNrvCollapse);
    NERVE(CollapsePlaneNrvDPDStop);
    NERVE(CollapsePlaneNrvEnd);
};

namespace NewNrvCollapsePlane {
    NERVE(NrvReturn);
};
#endif