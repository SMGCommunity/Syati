#pragma once

// These classes are identical between games

#include "Game/LiveActor/LiveActor.h"

class HeatHazeEffect : public LiveActor {
public:
    /// @brief Creates a new `HeatHazeEffect`.
    /// @param pName A pointer to the null-terminated name of the object.
    HeatHazeEffect(const char* pName);

    virtual void init(const JMapInfoIter& rIter);
    virtual void appear();
    virtual void control();

    f32 mDistanceFromCamera; // 0x90
};

class HeatHazeDirector : public NameObj {
public:
    /// @brief Creates a new `HeatHazeDirector`.
    /// @param pName A pointer to the null-terminated name of the object.
    HeatHazeDirector(const char* pName);

    virtual void init(const JMapInfoIter& rIter);
    virtual void movement();

    HeatHazeEffect* mEffect; // 0x14
};