#pragma once

#include "Game/NameObj/NameObj.h"
#include "Game/NameObj/NameObjGroup.h"
#include "Game/Util/Array.h"

/* FINISHED */

class MovementOnOffGroupHolder : public NameObj {
public:
    MovementOnOffGroupHolder(const char* pName);
    virtual ~MovementOnOffGroupHolder();

    // All of this was removed from SMG2.
    //NameObjGroup* joinToGroup(const char*, NameObj*, u32);
    //void onMovementGroup(const char*);
    //NameObjGroup* createGroup(const char*, u32);
    //NameObjGroup* findGroupFromName(const char*) const;

    MR::Vector<MR::FixedArray<NameObjGroup*, 32> > mGroups;
};