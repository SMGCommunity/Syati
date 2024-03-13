#pragma once

#include "revolution.h"
#include "syati.h"
#include "Game/System/AllData/SaveDataHandler.h"
#include "Game/Screen/SysInfoWindow.h"

class SysConfigFile;
class NANDErrorSequence;
class SaveIcon;

class SaveDataHandleSequence : public NerveExecutor {
public:
	SaveDataHandleSequence();
	virtual ~SaveDataHandleSequence();
	void initAfterResourceLoaded();
	void startPreLoad();
	void startCreateUserFile(int);
	void startDeleteUserFile(int);
	void startSaveAll();
	bool tryNANDErrorSequence(s32);
	bool isActive() const;
	bool isPermitToReset() const;
	void prepareReset();
	bool isPreparedReset() const;
	void restoreFromReset();
	bool isInitializedGameDataHolder() const;
	void restoreUserFile(UserFile*, int);
	void backupCurrentUserFile();
	void backupCurrentGameData();
	void exeNoOperation();
	void exeCheckEnableToCreate();
	void exeSaveConfirm();
	void exeSaveDoneKeyWait();
	void exeSaveAllWithoutKeyWait();
	void exePreLoadDone();
	void exeNoSaveConfirmRemind();
	void exeErrorHandling();
	SysConfigFile* getSysConfigFile();
	UserFile* getCurrentUserFile();
	void restoreUserFileConfigData(UserFile*, int);
	void restoreUserFileGameData(UserFile*, int);
	void restoreSysConfigFile(SysConfigFile*);
	bool trySave();
	bool tryConfirm(const char*, bool);
	bool tryProcessDoneKeyWait(const char*) const;
	bool tryNoSave();
	bool isEnablePointer() const;
	void executeSaveFinish(bool*, const Nerve*);
	void syncNoSaveFlagsFromErrorSequence();

	SysConfigFile* mSysConfigFile; // 8
	UserFile* mCurrentUserFile; // 0xC
	s32 mCurrentFileNum; // 0x10
	UserFile* mUserFile2; // 0x14
	SaveDataHandler* mSaveDataHandler; // 0x18
	NANDErrorSequence* mNANDErrorSequence; // 0x1C
	SysInfoWindow* mInfoWindow; // 0x20
	SysInfoWindow* mInfoWindowMini; // 0x24
	s32 _28;
	s32 _2C;
	s32 _30;
	s32 _34;
	s32 _38;
	s32 _3C;
	SaveIcon* mSaveIcon; // 0x40
};
