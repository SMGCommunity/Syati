#include "AreaObj/ImageEffectArea.h"

class BloomArea : public ImageEffectArea
{
public:
	BloomArea(const char *);

	virtual ~BloomArea();
	virtual void init(const JMapInfoIter &);
	virtual const char* getManagerName() const;

	s8 _4C;
	s8 _4D;
	s32 _50;
	s32 _54;
};
