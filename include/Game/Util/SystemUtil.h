#pragma once

#include "revolution/types.h"

class NameObj;
class JMapIdInfo;
class GameSystemObjHolder;
class ParticleResourceHolder;

namespace nw4r {
    namespace ut {
        class Font;
    }
}

typedef void (NameObj::*MethodFunc)();

namespace MR {
    class FunctorBase;

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

    nw4r::ut::Font *getFontOnCurrentLanguage();
    nw4r::ut::Font *getMenuFontNW4R();
    nw4r::ut::Font *getNumberFontNW4R();

};  // namespace MR
