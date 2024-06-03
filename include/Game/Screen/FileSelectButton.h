#pragma once

#include "syati.h"

class GalaxyMapGalaxyPlain;

class FileSelectButton : public LayoutActor {
    FileSelectButton(const char*);
    virtual ~FileSelectButton();
    void init(const JMapInfoIter&);
    void appear();
    void kill();
    void disappear();
    void setCallbackFunctor(const MR::FunctorBase&, const MR::FunctorBase&, const MR::FunctorBase&, const MR::FunctorBase&);
    void shiftSelect();
    void exeSelect();
    void exeDisappear();
    void control();
    void createPaneControl();
    void createButtonController();
    void createOthers();

    ButtonPaneController* mButtonStart; // 0x2C
    ButtonPaneController* mButtonMii; // 0x30
    ButtonPaneController* mButtonDelete; // 0x34
    ButtonPaneController* mButtonManual2P; // 0x38
    MR::FunctorBase* mFunc1; // 0x3C
    MR::FunctorBase* mFuncCallbackMii; // 0x40;
    MR::FunctorBase* mFunc3; // 0x44
    MR::FunctorBase* mFunc4; // 0x48
    s32 _50;
    s32 _54;
    s32 _58;
    s32 _5C;
    GalaxyMapGalaxyPlain* mGalaxyMapGalaxyPlain; // 0x60
};

namespace NrvFileSelectButton {
    NERVE(FileSelectButtonNrvSelect);
    NERVE(FileSelectButtonNrvWait);
    NERVE(FileSelectButtonNrvDisappear);
};