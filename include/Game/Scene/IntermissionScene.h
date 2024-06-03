#pragma once

#include "syati.h"

class IntermissionScene : public Scene {
public:
    IntermissionScene();
    virtual ~IntermissionScene();
    virtual void update();
    virtual void draw() const;
    void setCurrentSceneControllerState(const char*, ...);

    u8 _unk[64];
    s32 _54;
};

const s32 test = sizeof(IntermissionScene);