#pragma once

#include "syati.h"

class TimeLimitLayout : public LayoutActor {
public:
    TimeLimitLayout();
    virtual ~TimeLimitLayout();
    virtual void init(const JMapInfoIter& rIter);
    virtual void appear();
    virtual void kill();
    virtual void control();
    void setTimeLimit(u32 time);
    void setDisplayModeOnNormal(bool);
    bool isReadyToTimeUp() const;
    void resetFrame();
    void exeAppear();
    void exeCountDown();
    void updateTextBox();
    void exeScaleUp();
    void exeScaleKeep();
    void exeScaleDown();
    void exeFadeout();
    s32 getCurrentTiming() const;
    void updateNormal();

    u32 mTime; // 0x2C
    u32 mInitialTime; // 0x30
    ValueControl* mValueControl; // 0x34
    ValueControl* mValueControl2; // 0x38
    s32 _3C;
    bool mIsPaused; // 0x40
    bool mDisplayMode; // 0x41
};

