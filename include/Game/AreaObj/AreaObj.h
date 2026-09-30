#pragma once

#include "Game/NameObj.h"
#include "Game/Util/Array.h"

/* FINISHED */

class AreaForm;
class StageSwitchCtrl;

class AreaObj : public NameObj {
public:
    AreaObj(const char *pName);
    AreaObj(int shapeNo, const char *pName);

    virtual ~AreaObj();
    virtual void init(const JMapInfoIter &rIter);
    virtual bool isInVolume(const TVec3f &rPosition) const;
    virtual s32 getAreaPriority() const;
    virtual const char* getManagerName() const;

    void validate();
    void invalidate();
    void awake();
    void sleep();

    void initForm(const JMapInfoIter &rIter);
    bool isNotHemisphere() const;

    void onSwitchA();
    void offSwitchA();
    bool isOnSwitchA() const;
    bool isOnSwitchB() const;
    bool isValidSwitchA() const;
    bool isValidSwitchB() const;

    void setFollowMtx(const MtxPtr pFollowMtx);
    MtxPtr getFollowMtx() const;

    /* 0x14 */ AreaForm* mAreaForm;
    /* 0x18 */ int mFormType;
    /* 0x1C */ bool mValidate;
    /* 0x1D */ bool mFollowActorAlive;
    /* 0x20 */ s32 mObjArg0;
    /* 0x24 */ s32 mObjArg1;
    /* 0x28 */ s32 mObjArg2;
    /* 0x2C */ s32 mObjArg3;
    /* 0x30 */ s32 mObjArg4;
    /* 0x34 */ s32 mObjArg5;
    /* 0x38 */ s32 mObjArg6;
    /* 0x3C */ s32 mObjArg7;
    /* 0x40 */ s32 mPriority;
    /* 0x44 */ StageSwitchCtrl* mStageSwitchCtrl;
};

class AreaObjMgr : public NameObj {
public:
    AreaObjMgr(s32 size, const char *pName);

    virtual ~AreaObjMgr();
    
    void entry(AreaObj *pArea);
    bool find_in(const TVec3f &rPosition) const;
    void requestMovementOnAll();

    /* 0x14 */ MR::Vector<MR::AssignableArray<AreaObj*> > mAreas;
    /* 0x20 */ s32 mMaxAreas;
};
