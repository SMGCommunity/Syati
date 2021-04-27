#pragma once

#include "Actor/AreaObj/AreaForm.h"
#include "Actor/NameObj/NameObj.h"
#include "Map/Switch/StageSwitch.h"
#include "JGeometry/TVec3.h"

class AreaObj : public NameObj
{
public:
    AreaObj(const char *);
    AreaObj(AreaFormType, const char *);

    virtual ~AreaObj();
    virtual void init(const JMapInfoIter &);

    virtual bool isInVolume(const JGeometry::TVec3<f32> &) const;
    virtual s32 getAreaPriority() const;
    virtual const char* getManagerName() const;

    void initForm(const JMapInfoIter &);
    void onSwitchA();
    void offSwitchA();
    void isOnSwitchA() const;
    void isOnSwitchB() const;
    void isValidSwitchA() const;
    void isValidSwitchB() const;

    // unknown function at 80070BB0
    // setFollowMtx
    // getFollowMtx

    AreaForm* mAreaForm; // _14
    AreaFormType mAreaFormType; // 18
    bool mValidate; // _1C
    bool mFollowActorAlive; // _1D
    s32 mObjArg0; // 20
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

class AreaObjMgr : public NameObj {
public:
    AreaObjMgr(s32, const char *);

    virtual ~AreaObjMgr();
    
    void entry(AreaObj *);
    bool find_in(const JGeometry::TVec3<f32> &) const;
    // unknown function at 80070E30

    AreaObj** mAreas; // 14
    s32 mNumMaxAreas; // 18
    s32 mNumAreas; // 1C
    s32 mMaxAreasArg; // 20
};
