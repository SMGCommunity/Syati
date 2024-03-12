#pragma once

#include "syati.h"
#include "Game/Screen/ButtonPaneController.h"

class BackButton : public LayoutActor {
public: 
    BackButton(const char*, bool);
    virtual ~BackButton();
    virtual void init(const JMapInfoIter&);
    virtual void appear();
    virtual void control();
    void disappear();
    bool isHidden();
    bool isAppearing();
    bool isDisappearing();
    bool isPointing();

    ButtonPaneController* mButtonPaneCtrl;
    bool _30;
    bool _31;
    bool _32;
};

class BackButtonCancelB : public BackButton {
public:
    BackButtonCancelB(const char*, bool);
    virtual void control();
};