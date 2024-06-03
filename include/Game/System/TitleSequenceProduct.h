#pragma once

#include "syati.h"

class EncouragePal60Window; // LayoutActor
class DemoTitleAnim; // LayoutActor

namespace TitleSequenceProductSub {
    class LogoLayout : public LayoutActor {
        LogoLayout();
        virtual ~LogoLayout();
    };
};

class TitleSequenceProduct : public NerveExecutor {
public:
    TitleSequenceProduct();
    virtual ~TitleSequenceProduct();
    void exeLogoFadein();
    void exeLogoWait();
    void exeLogoDisplay();
    void exeDecide();
    void exeDead();
    void appear();
    void kill();
    bool isActive() const;
    void updateButtonReaction(TriggerChecker*, const char*);
    void updatePressStartReaction();

    TitleSequenceProductSub::LogoLayout* mLogoLayout; // 0x8
    SimpleLayout* mPressStart;
    EncouragePal60Window* mEncouragePal60Window; // 0x10
    TriggerChecker* mTriggerCheckerA; // 0x14
    TriggerChecker* mTriggerCheckerB; // 0x18
    DemoTitleAnim* mDemoTitleAnim; // 0x1C
};

//namespace NrvTitleSequenceProduct {
//    // 3 unknown nerves
//    NERVE(TitleSequenceProductNrvLogoFadeinFv);
//    NERVE(TitleSequenceProductNrvLogoWaitFv);
//    NERVE(TitleSequenceProductNrvLogoDisplayFv);
//    NERVE(TitleSequenceProductNrvDecideFv);
//    NERVE(TitleSequenceProductNrvDeadFv);
//    // 1 unknown nerve
//};