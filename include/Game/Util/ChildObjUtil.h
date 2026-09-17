#pragma once

#include "revolution/types.h"

/* FINISHED */

class JMapInfoIter;
class LiveActorGroup;
class NameObj;

namespace MR {
    LiveActorGroup* initChildObjGroup(const NameObj *pObj, const char *pGroupName, const JMapInfoIter &rIter);
};
