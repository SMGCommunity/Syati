#include "custom/Actor/ExtendedActorFactory.h"
#include "Util/StringUtil.h"

// patch is at 804564D4, we still have r3 as our name
void* getCreator(const char *pName)
{
	// first we return our first creator, if it does not exist, it will return nullptr
    void* creator = NameObjFactory::getCreator(pName);

    // original creator isn't there, so we may find it in our table
    if (!creator)
    {
		// go through our custom actor table
        for (s32 i = 0; i < NUM_ACTORS; i++)
        {
            const CreateActorEntry* e = &ExtendedActorFactory::cCreateTable[i];

			// if our entry is equal to the one we are looking for, we return its creator
            if (MR::isEqualStringCase(e->pActorName, pName))
            {
				// replace the orignal creator function ptr to our new one
                creator = e->mCreationFunc;
                break;
            }
        }
    }

	// return our new creator
    return creator;
}

kmCall(0x804564D4, getCreator);
