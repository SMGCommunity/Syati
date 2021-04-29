#include "Actor/NameObj/NameObj.h"
#include "kamek.h"

class PlanetCreator : public NameObj
{
public:
	PlanetCreator(const char *);

	bool doesProductMapObjExist(const char *);
	void* getObjClassName(const char *);

	u32** mElements;
	s32 mNumElements;
};

namespace MR {
	bool doesProductMapObjExist(const char *);
	void* getObjClassName(const char *);
};
