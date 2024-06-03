#pragma once

#include "syati.h"

class LogoFader : public LayoutActor {
public:
    LogoFader();
    virtual ~LogoFader();
    virtual void draw() const;
    void exeFadeIn();
    void exeFadeOut();
    void setBlank();
    void startFadeIn();
    void startFadeOut();
    bool isFadeEnd() const;

    bool _2C;
    s32 _30;
    f32 _34;
};

class LogoScene : public Scene {
public:
    LogoScene();
    virtual ~LogoScene();
    virtual void init();
    virtual void update();
    virtual void calcAnim();
    virtual void draw() const;
    bool isDisplayStrapRemineder() const;
    void exeStrapFadein();
    void exeStrapDisplay();
    void exeMountGameData();
    void initLayout();

    SimpleLayout* mWiiRemoteStrap;
    LogoFader* mLogoFader;
    bool _1C;
};