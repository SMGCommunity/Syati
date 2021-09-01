#include "custom/archive.h"
#include "syati.h"

void doLoadingShit()
{
    Syati::loadArchive("/ProjectTemplate/Font.arc");
    Syati::loadResourceFromArchive("/ProjectTemplate/Font.arc", "/PictureFont.brfnt");
}

kmBranch(0x804B8284, doLoadingShit);