#pragma once

#include "Game/NameObj.h"
#include "Game/Screen/LayoutActor.h"
#include "Game/LiveActor/ModelManager.h"

class MultiSceneEffectKeeper;

class MultiSceneActor : public NameObj {
public:
    MultiSceneActor(const char *, const char *, s32, bool);
    virtual ~MultiSceneActor();
    virtual void init(const JMapInfoIter &rIter);
    virtual void movement();
    virtual void calcAnim();
    virtual void calcViewAndEntry();
    virtual void appear();
    virtual void kill();
    void initEffect(EffectSystem *, s32, const char *);
    void setNerve(const Nerve *);
    bool isNerve(const Nerve *) const;
    void initNerve(const Nerve *);

    TVec3f mTranslation;                    // _14
    TVec3f mRotation;                       // _20
    TVec3f mScale;                          // _2C;
    bool _38;
    ModelManager* mModelManager;            // _3C
    EffectSystem* mEffectSystem;            // _40
    MultiSceneEffectKeeper* mEffectKeeper;  // _44
    Spine* mSpine;                          // _48
};