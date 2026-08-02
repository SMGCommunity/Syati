#include "syati.h"

class EventSequence;
typedef void (EventSequence::*EventFunc)(u16, u16 time);
typedef bool (EventSequence::*EventFunc2)(u16);

class EventSequence {
    public:
    EventSequence(u32);
    void clearFlag(void);
    void addEventOnTime(char const *, EventFunc, u16);
    void addEventInTime(char const *, EventFunc, u16, u16);
    void addEventInStatus(char const *, EventFunc, EventFunc2);
    void addEventInPhase(char const *, EventFunc, u16);
    void checkAndRun(u32);
    void updateBefore(void);
    void updateAfter(void);
    void playSound(char const *);
    void playAnimation(char const *);
    bool isMissLayoutClosed(u16);
    void decLeft(u16,u16);
    void doCloseWipe(u16, u16);
    void doWaitAfterWipe(u16, u16);
};

class EventRaceDown : public EventSequence {
public:
    EventRaceDown(void);
    bool checkCloseWipeStart(u16);
    void init(u16,u16);
    void missLayoutOpen(u16,u16);
    void sound(u16, u16 time);
};