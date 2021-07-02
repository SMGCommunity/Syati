#pragma once

#include "kamek.h"
#include "JMap/JMapInfoIter.h"
#include "Util/JMapLinkInfo.h"

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

    // Flag 0 = movement
    // Flag 1 = resume
    // Flag 2 = suspend
};

class NameObjFunction
{
public:
    static void requestMovementOn(NameObj *);
    static void requestMovementOff(NameObj *);
};
