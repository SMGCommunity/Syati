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
    bool tryDPDStop();
    virtual ~CollapsePlane();

    AnimScaleController* mAnimScaleController; // 0xD0
    WalkerStateBindStarPointer* mWalkerStateBindStarPointer; // 0xD4
    JointControlDelegator<CollapsePlane>* mJointControllerDelegator; // 0xD8
    s32 mCollapseTimer; // 0xDC
    s32 mCollapseSpeed; // 0xE0
};

namespace NrvCollapsePlane {
    NERVE(CollapsePlaneNrvWait);
    NERVE(CollapsePlaneNrvCollapse);
    NERVE(CollapsePlaneNrvDPDStop);
    NERVE(CollapsePlaneNrvEnd);
};
