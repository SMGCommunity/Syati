#pragma once

#include "System/Resource/FileLoader.h"
#include "Singleton.h"
#include "JSystem/JKernel/JKRArchive.h"
#include "JSystem/JKernel/JKRDvdRipper.h"
#include "Util.h"

namespace Syati
{
    JKRArchive* loadArchive(const char *pArchivePath)
    {
        bool isExist = MR::isFileExist(pArchivePath, false);
       
        if (isExist)
        {
            void* rawData = MR::loadToMainRAM(pArchivePath, 0, MR::getStationedHeapNapa(), 1);
            OSReport("loaded into ram\n");
            OSReport("raw data ptr: %p\n");

            FileLoader* ldr = SingletonHolder<FileLoader>::sInstance;
            JKRArchive* arch = ldr->createAndAddArchive(rawData, 0, pArchivePath);
            OSReport("added archive\n");

            return arch;
        }
        
        OSReport("file %s not found!!\n", pArchivePath);
        return 0;
    }

    void* loadResourceFromArchive(const char *pArchivePath, const char *pFile)
    {
        FileLoader* ldr = SingletonHolder<FileLoader>::sInstance;
        JKRArchive* archive = ldr->mArchiveHolder->getArchive(pArchivePath);

        if (archive)
        {
            void* data = archive->getResource(pFile);

            if (data)
            {
                OSReport("data found! returning\n");
                return data;
            }
            else
            {
                OSReport("FILE %s NOT FOUND!!\n", pFile);
            }
        }

        return 0;
    }
};