#pragma once

#include "NameObj/NameObj.h"

struct CreateActorEntry
{
    const char* pActorName; // _0
    NameObj* (*mCreationFunc)(const char *); // _4
};

struct PostCreationEntry
{
    const char* pActorName; // _0
    void (*mPostCreationFunc)(const JMapInfoIter &); // _4
};

template<typename T>
NameObj* createNameObj(const char*);

template<typename T>
NameObj* createBaseOriginCube(const char*);

template<typename T>
NameObj* createCenterOriginCube(const char*);

template<typename T>
NameObj* createSphere(const char*);

template<typename T>
NameObj* createBaseOriginCylinder(const char*);

class NameObjFactory
{
public:
    static void* getCreator(const char *);
    static void callPostCreation(const char *, const JMapInfoIter &);
    static NameObj* initChildObj(const JMapInfoIter &, int);

    static CreateActorEntry cCreateTable[1003];
    static PostCreationEntry cPostCreationTable[27];
};
