#include "Actor/NameObj/NameObj.h"
#include "kamek.h"

class ProductMapCreator : public NameObj
{
public:
	ProductMapCreator(const char *);

	bool doesProductMapObjExist(const char *);
	void* getObjClassName(const char *);

	u32** mElements;
	s32 mNumElements;
};

namespace MR {
	bool doesProductMapObjExist(const char *);
	void* getObjClassName(const char *);
};
