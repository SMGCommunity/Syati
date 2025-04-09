#pragma once

#include "revolution.h"
#include "Game/NameObj/NameObj.h"
#include "Game/Player/MarioHolder.h"

/* FINISHED */

typedef NameObj* (CreateActorFunc)(const char *);
typedef void (PostCreationFunc)(const JMapInfoIter &);

struct CreateActorEntry {
    const char* pActorName;         // _0
    CreateActorFunc* mCreationFunc; // _4
};

struct PostCreationEntry {
    const char* pActorName;              // _0
    PostCreationFunc* mPostCreationFunc; // _4
};

class NameObjFactory {
public:
    static void* getCreator(const char *pName);
    static void callPostCreation(const char *pName, const JMapInfoIter &rIter);
    static NameObj* initChildObj(const JMapInfoIter &rIter, int index);

    static CreateActorEntry cCreateTable[1003];
    static PostCreationEntry cPostCreationTable[27];

    template<typename T>
    static NameObj* createNameObj(const char *pName) {
        return new T(pName);
    }

    template<typename T>
    static NameObj* createBaseOriginCube(const char *pName) {
        return new T(1, pName);
    }

    template<typename T>
    static NameObj* createCenterOriginCube(const char *pName) {
        return new T(0, pName);
    }

    template<typename T>
    static NameObj* createSphere(const char *pName) {
        return new T(2, pName);
    }

    template<typename T>
    static NameObj* createBaseOriginCylinder(const char *pName) {
        return new T(3, pName);
    }
};