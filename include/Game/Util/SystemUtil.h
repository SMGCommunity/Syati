#pragma once

#include "Game/Util/Functor.h"
#include "Game/Util/JMapIdInfo.h"
#include "Game/NameObj/NameObj.h"
#include "Game/System/GameSystemObjHolder.h"

class ParticleResourceHolder;

typedef void (NameObj::*MethodFunc)();

namespace MR {
    bool isScreen16Per9();

    void setLayoutDefaultAllocator();

    void startFunctionAsyncExecute(const FunctorBase &, int, const char *);

    void startFunctionAsyncExecuteOnMainThread(const FunctorBase&, const char*);
    void waitForEndFunctionAsyncExecute(const char*);
    bool isEndFunctionAsyncExecute(const char*);
    bool tryEndFunctionAsyncExecute(const char*);
    void suspendAsyncExecuteThread(const char*);
    void resumeAsyncExecuteThread(const char*);
    bool isSuspendAsyncExecuteThread(const char*);

    void clearFileLoaderRequestFileInfo(bool);

    ParticleResourceHolder* getParticleResourceHolder();

    void destroySceneMessage();

    void requestChangeArchivePlayer(bool);

    JMapIdInfo* getPlayerRestartIdInfo();

    void waitEndChangeArchivePlayer();

    void initSceneMessage();

    void callMethodAllSceneNameObj(MethodFunc);

    GameSystemObjHolder *getGameSystemObjHolder();

};  // namespace MR
