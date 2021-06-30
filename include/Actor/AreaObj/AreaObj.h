#pragma once

#include "Actor/AreaObj/AreaForm.h"
#include "Actor/NameObj/NameObj.h"
#include "Map/Switch/StageSwitch.h"
#include "Util/AssignableArray.h"

class AreaObj : public NameObj
{
public:
    AreaObj(const char *);
    AreaObj(int, const char *);

    virtual ~AreaObj();
    virtual void init(const JMapInfoIter &);
    virtual bool isInVolume(const TVec3f &) const;
    virtual s32 getAreaPriority() const;
    virtual const char* getManagerName() const;

    void validate();
    void invalidate();
    void awake();
    void sleep();

    void initForm(const JMapInfoIter &);
    bool isNotHemisphere() const;

    void onSwitchA();
    void offSwitchA();
    bool isOnSwitchA() const;
    bool isOnSwitchB() const;
    bool isValidSwitchA() const;
    bool isValidSwitchB() const;

    void setFollowMtx(const TPositionMtx *);
    Mtx* getFollowMtx() const;

    AreaForm* mAreaForm; // _14
    int mAreaFormType; // 18
    bool mValidate; // _1C
    bool mFollowActorAlive; // _1D
    s32 mObjArg0; // _20
    s32 mObjArg1; // _24
    s32 mObjArg2; // _28
    s32 mObjArg3; // _2C
    s32 mObjArg4; // _30
    s32 mObjArg5; // _34
    s32 mObjArg6; // _38
    s32 mObjArg7; // _3C
    s32 mPriority; // _40
    StageSwitchCtrl* mStageSwitchCtrl; // 44
};

class AreaObjMgr : public NameObj
{
public:
    AreaObjMgr(s32, const char *);

    virtual ~AreaObjMgr();
    
    void entry(AreaObj *);
    bool find_in(const TVec3f &) const;
    void requestMovementOnAll();

    MR::AssignableArray<AreaObj*> mAreas; // 14
    s32 mNumAreas; // 1C
    s32 mMaxAreasArg; // 20
};
