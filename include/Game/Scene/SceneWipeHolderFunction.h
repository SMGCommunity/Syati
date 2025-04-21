#pragma once

#include "revolution/types.h"

class SceneWipeHolder;

namespace SceneWipeHolderFunction {
    SceneWipeHolder *getSceneWipeHolder();
    void openWipe(const char *, s32);
    void closeWipe(const char *, s32);
    void forceOpenWipe(const char *);
    void forceCloseWipe(const char *);
}