#pragma once

#include "Game/Screen/LayoutActor.h"
#include "Game/Util/BitArray.h"
#include "Game/Map/FileSelectIconID.h"
#include "Game/Screen/ButtonPaneController.h"

namespace nw4r {
    namespace lyt {
        class TexMap;
    };
};

namespace MiiSelectSub {
    class Page;
};

class MiiSelect : public LayoutActor {
public:
    MiiSelect(const char*);
    virtual ~MiiSelect();
    virtual void init(JMapInfoIter const &);
    virtual void appear();
    virtual void disappear();
    virtual void calcAnim();
    void isAppearing() const;
    void isSelected();
    void isDummySelected();
    void getSelectedID(FileSelectIconID *);
    void getSelectedMiiTexMap();
    void admitIcon();
    void prohibitIcon(FileSelectIconID const &);
    void invalidateSpecialMii(FileSelectIconID::EFellowID);
    void validateAllSpecialMii();
    void exeAppear();
    void exeWait();
    void exeScrollLeft();
    u16 getIconNum();
    void exeScrollRight();
    void exeDisappear();
    void control();
    void createButtons();
    void callbackLeft();
    void callbackRight();
    void appearButtons();
    void disappearButtons();
    void updateButtons();
    void collectValidMiiIndex();
    void createPage();
    void flipPage();
    void setCurrentPageGroupA();
    void setCurrentPageGroupB();
    void setCurrentPageNum();
    void validateAllIcon();
    void refresh();
    u16 getIconID(FileSelectIconID*, long) const;
    void onSelect(long, nw4r::lyt::TexMap*);
    void onSelectDummy();

    ButtonPaneController* mButtonPaneController; // 0x2C
    s32 _30;
    MR::BitArray* mBitFlags; // 0x34
    u16 mNumIcons; // 0x38
    s16 _3A;
    char unk1[0x24];
    s16 _64;
    char unk2[0x194];
    s32 _1F8;
    s32 _1FC;
    s32 _200; // TexMap?
    MiiSelectSub::Page* mPage1; // 0x204
    MiiSelectSub::Page* mPage2; // 0x208
    bool mIsProhibit; // 0x20C
    FileSelectIconID* mFileSelectIconID;
};