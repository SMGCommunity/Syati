#include "Actor/AreaObj/AreaObj.h"
#include "Util/PlayerUtil.h"
#include "Util/ScreenUtil.h"
#include "Util/StageUtil.h"
#include "kamek.h"
#include "os.h"

const char* pStages[2] = { "IslandFleetGalaxy", "RedBlueExGalaxy" };

void SceneChangeAreaControl(AreaObj *pArea)
{
    JGeometry::TVec3<f32>* pos = MR::getPlayerPos();

    if (pArea->isInVolume(*pos))
    {
        MR::closeSystemWipeFadeWithCaptureScreen(pArea->mObjArg1 == -1 ? 0 : pArea->mObjArg1);
        
        if (pArea->mObjArg0 != -1)
            MR::goToGalaxy(pStages[pArea->mObjArg0]);
        else
            MR::goToGalaxy("IslandFleetGalaxy");

        pArea->mValidate = 0;
    }
}

kmWritePointer(0x8066AE4C, SceneChangeAreaControl);
