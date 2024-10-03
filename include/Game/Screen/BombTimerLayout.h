#include "syati.h"

class BombTimerLayout : public LayoutActor { 
public:

    BombTimerLayout();
    virtual ~BombTimerLayout();
    virtual void init(JMapInfoIter const &);
    virtual void appear();
    void setTimeLimit(u32);
    void suspend();
    void resume();
    bool isReadyToTimeUp() const;
    void addFrame();
    void update();
    s32 getRestTime() const;
    void updateTextBox();
    void exeAppear();
    void exeWait();
    void exeDanger();

    u32 mTime; // 0x2C
    s32 mInitialTime; // 0x30
    u32 _34; // 0x34
    bool mIsSuspended; // 0x38
};

namespace NrvBombTimerLayout {
    NERVE(BombTimerLayoutNrvAppear);
    NERVE(BombTimerLayoutNrvWait);
    NERVE(BombTimerLayoutNrvDanger);
    NERVE(BombTimerLayoutNrvEnd);
};