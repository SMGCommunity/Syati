#pragma once

#include "revolution.h"

class ActorStateKeeper;
class Spine;

class Nerve {
public:
    virtual void execute(Spine *) const = 0;
    virtual void executeOnEnd(Spine *) const;
};

#define NERVE(name)\
class name : public Nerve {\
    public:\
    virtual void execute(Spine *) const;\
    static name sInstance;\
};\

#define ENDABLE_NERVE(name)\
class name : public Nerve {\
public:\
    virtual void execute(Spine *) const;\
    virtual void executeOnEnd(Spine *) const;\
    static name sInstance;\
};\

/* Declares a nerve and also defines the body of the nerve's execution function, which calls a specified member function */
#define NERVE_DECL_EXE(name, parent_class, executor_name)\
class name : public Nerve\
{\
public:\
    name() {\
    };\
    virtual void execute(Spine *pSpine) const {\
        parent_class* actor = reinterpret_cast<parent_class*>(pSpine->mExecutor);\
        actor->exe##executor_name();\
    };\
    static name sInstance;\
};\

class Spine {
public:
    Spine(void *pExecutor, const Nerve *pNerve, s32 stateKeeperSize);

    void update();
    void setNerve(const Nerve *pNextNerve);
    const Nerve* getCurrentNerve() const;
    void changeNerve();

    void* mExecutor;                // _0
    const Nerve* mCurNerve;         // _4
    const Nerve* mNextNerve;        // _8
    u32 mStep;                      // _C
    ActorStateKeeper* mStateKeeper; // _10
};
