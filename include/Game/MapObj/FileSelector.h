#pragma once

#include "syati.h"
#include "Game/Map/FileSelectIconID.h"
#include "Game/Map/FileSelectItem.h"
#include "Game/Map/FileSelectModel.h"
#include "Game/Screen/BackButton.h"
#include "Game/Screen/MiiSelect.h"
#include "Game/System/TitleSequenceProduct.h"

class RFLCreateID;
class MiiConfirmIcon;
class Manual2P;
class FileSelectEffect;
class FileSelectCameraController;
class FileSelectButton;

class FileSelector : public LiveActor {
public: 
    FileSelector(const char* pName);
    virtual void init(const JMapInfoIter& rIter);
    virtual void appear();
    virtual void kill();
    void callbackMii();
    void notifyItem(FileSelectItem*, s32);
    virtual void control();
    virtual bool receiveOtherMsg(u32, HitSensor*, HitSensor*);
    void initUserFileArray();
    void createCameraController();
    void createFileItems();
    void createOperationButton();
    void createBackButton();
    void createFileInfo();
    void createTitle();
    void createMiiSelect();
    void createManual();
    void appearAllItems();
    void disappearAllLayout();
    void isHiddenAllLayout() const;
    void updateFileInfo();
    void appearAllIndex();
    void disappearAllIndex();
    void invalidateSelectAll();
    void validateSelectAll();
    void initUserFile();
    void restoreUserFile();
    void checkAllComplete();
    void onPoint(FileSelectItem*);
    void onSelect(FileSelectItem*);
    void clearPointing();
    void setFileInfo(s32);
    void checkSelectedBackButton();
    void goToNearPoint();
    void calcBasePos(f32);
    void initAllItems();
    void validateRotateAllItems();
    void getUserFileFellowID(s32) const;
    void isUserFileMiiIdValid(s32) const;
    void getUserFileMiiIndex(s32) const;
    // Unknown Symbol sub_80250F50
    void storeSetMiiIdUserFile(s32, const FileSelectIconID&);
    void getMiiId(RFLCreateID*, const FileSelectIconID&) const;
    void getIconId(FileSelectIconID*, s32) const;
    void getMissCount(s32) const;
    void getGrandStarNum(s32) const;
    void playSelectedME();
    void updateBgm();
    // Unknown Symbol sub_802515A0
    void exeTitle();
    void exeTitleEnd();
    void exeCreate();
    void exeMiiTip();
    void exeMiiSelectStart();
    void exeMiiSelect();
    void exeMiiCancel();
    void exeMiiConfirmWait();
    void exeMiiConfirm();
    void exeMiiCreateWait();
    void exeMiiCreateDemo();
    void exeMiiCaution();
    void exeMiiInfoStart();
    void exeMiiInfo();
    void exeDeleteConfirmStart();
    void exeDeleteConfirm();
    void exeDelete();
    void exeDeleteDemo();
    void exeManualStart();

    FileSelectCameraController* mFileSelectCameraController; // 0x90
    s32 _94;
    DeriveActorGroup<FileSelector>* mLiveActorGroup; // 0x98
    s32 _9C;
    FileSelectButton* mFileSelectButton; // 0xA0
    BackButtonCancelB* mBackButtonCancelB; // 0xA4
    SysInfoWindow* mSysInfoWindow; // 0xA8
    SysInfoWindow* mSysInfoWindowMini; // 0xAC
    FileSelectItem* mFileSelectItem; // 0xB0
    s32 _B4;
    s32 _B8;
    s32 _BC;
    FileSelectInfo* mFileSelectInfo; // 0xC0
    UserFile** mUserFileArray; // 0xC4
    s32** _C8;
    TitleSequenceProduct* mTitleSequenceProduct; // 0xCC
    MiiSelect* mMiiSelect; // 0xD0
    MiiConfirmIcon* mMiiConfirmIcon; // 0xD4
    RFLCreateID* mRFLCreateID; // 0xD8
    Manual2P* mManual2P; // 0xDC
    s32 _E0;
    s32 _E4;
    FileSelectEffect* mFileSelectEffect; // 0xE8
    s32 _EC;
    s32 _F0;
    s32 _F4;
    s32 _F8;
    s32 _FC;
    s32 _100;
    s32 _104;
};