#pragma once

#include "revolution.h"
#include "JSystem.h"

namespace Syati {
    JKRArchive* loadArchive(const char *pArchivePath);
    void* loadResourceFromArchive(const char *pArchivePath, const char *pFile);
};
