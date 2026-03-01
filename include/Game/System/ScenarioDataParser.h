#pragma once

#include "revolution.h"

#include "Game/NameObj/NameObj.h"
#include "Game/Util/Array.h"

class GalaxyStatusAccessor;
class JMapInfo;
class ScenarioData;

typedef MR::FixedArray<ScenarioData*, 64> ScenarioDataType; // I don't know why this is needed but I cannot compile without it...

class ScenarioDataParser : public NameObj {
public:
    /// @brief Creates a new `ScenarioDataParser`.
    /// @param pName A pointer to the null-terminated name of the object.
    ScenarioDataParser(const char* pName);

    const ScenarioData* getScenarioData(const char*) const;
    // const ScenarioData* getScenarioData(s32) const; // Got removed in SMG2
    GalaxyStatusAccessor makeAccessor(const char*) const;

    MR::Vector<ScenarioDataType> mScenarioData; // Not bound-checked in vanilla
};

class ScenarioDataIter {
public:
    ScenarioDataIter(const ScenarioDataParser*, int);

    // there's a really weird virtual here that seems to detect if the world ID of a galaxy is greater than 0 but I don't know why this would be needed...

    bool isEnd() const;
    void goNext();
    GalaxyStatusAccessor makeAccessor() const;

    /* 0x00 */ const ScenarioDataParser* mParser;
    /* 0x04 */ int mCur;
};

class ScenarioData {
public:
    ScenarioData(const char*);

    void initialize(const char*);

    s32 getNormalPowerStarNum() const;
    s32 getPowerStarNum() const;
    bool getValueString(const char*, s32, const char**) const;

    // I cannot verify the next two functions

    bool isPowerStarTypeHidden(s32) const; // new to SMG2
    bool isPowerStarTypeGreen(s32) const; // new to SMG2
    s32 getZoneNum() const;
    const char* getZoneName(s32) const;
    s32 getZoneId(const char*) const;
    s32 getWorldNo() const;

    ScenarioDataIter getScenarioDataIter(s32) const;
    void getScenarioString(const char*, s32, const char**);

    /* 0x00 */ char* mGalaxyName;
    /* 0x04 */ JMapInfo* mScenarioData;
    /* 0x08 */ JMapInfo* mZoneList;
    /* 0x0C */ JMapInfo* mGalaxyInfo;
};

namespace ScenarioDataFunction {
    ScenarioDataParser* getScenarioDataParser();
    u32 getCurrentCommonLayers(const char*);
    u32 getCurrentScenarioLayers(const char*, s32);
};  // namespace ScenarioDataFunction

namespace MR {
    ScenarioDataIter makeBeginScenarioDataIter();
}