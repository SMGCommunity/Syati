#pragma once

#include "revolution/types.h"

class AudBgm;
class AudBgmMgr;
class AudSystem;
class AudSceneMgr;

class AudWrap {
public:
    static AudBgmMgr* getBgmMgr();
    static AudBgm* getStageBgm();

    static AudSystem* getSystem();

    static AudSceneMgr* getSceneMgr();

    static void setNextIdStageBgm(u32);

    static void startStageBgm(u32, bool);
};