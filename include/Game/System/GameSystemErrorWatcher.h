#pragma once

#include "revolution.h"
#include "Game/System/NerveExecutor.h"
#include "Game/Util/TriggerChecker.h"
#include "Game/Screen/BatteryInfo.h"

class ErrorMessageWindow;

namespace nw4r {
    namespace lyt {
        class TexMap;
    };
};

class GameSystemErrorWatcher : public NerveExecutor {
public:
    GameSystemErrorWatcher(const char *pName);
    ~GameSystemErrorWatcher();
    void initAfterResourceLoaded();
    void movement();
    void draw() const;
    bool isWarning() const;
    void setPermissionUpdateWiiRemoteStatus(bool);
    void exeNoError();
    void exeErrorWindowIn();
    void exeErrorWindowDisplay();
    void exeErrorWindowOut();
    void updateWiiRemoteStatus();
    const char *getProperMessageId() const;
    u32 getProperErrorTexMap();

    ErrorMessageWindow *mErrorMessageWindow;    // _8
    u32 _C;
    nw4r::lyt::TexMap *_10;                     // ErrorMessageImage.arc/FreeStyleUnplagged.bti
    BatteryLayout *mBatteryLayout;              // _14
    u32 _18;
    TriggerChecker *mTriggerChecker;            // _1C
    u32 _20;
    u32 _24;
    u32 _28;                                    // gets initialized to 16
    u32 _2C;                                    // gets initialized to 120
    u32 _30;                                    // gets initialized to 4
    bool _34;
};