#pragma once

#include "syati.h"
#include "JMap/JMapInfoIter.h"
#include "Util/JMapLinkInfo.h"

#define NAMEOBJ_FLAG_MOVEMENT 1
#define NAMEOBJ_FLAG_RESUME 2
#define NAMEOBJ_FLAG_SUSPEND 4

class NameObj
{
public:
    NameObj(const char *pActorName);

    virtual ~NameObj();
    virtual void init(const JMapInfoIter &);
    virtual void initAfterPlacement();
    virtual void movement();
    virtual void draw() const;
    virtual void calcAnim();
    virtual void calcViewAndEntry();
    virtual void unk1();
    virtual void unk2();

    void initWithoutIter();
    void setName(const char *);
    void setLinkedInfo(const JMapInfoIter &);

    void executeMovement();
    void requestSuspend();
    void requestResume();
    void syncWithFlags();

    const char* mName; // _4
    u16 mFlags; // _8
    s16 mExecuteIdx; // _A
    JMapLinkInfo mLinkedInfo; // _C
};

class NameObjFunction
{
public:
    static void requestMovementOn(NameObj *);
    static void requestMovementOff(NameObj *);
};
