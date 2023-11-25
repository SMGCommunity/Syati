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

    void exeReturn(); // NEW

    AnimScaleController* mAnimScaleController; // 0xD0
    WalkerStateBindStarPointer* mWalkerStateBindStarPointer; // 0xD4
    JointControlDelegator<CollapsePlane>* mJointControllerDelegator; // 0xD8
    s32 mCollapseTimer; // 0xDC
    s32 mCollapseSpeed; // 0xE0
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
