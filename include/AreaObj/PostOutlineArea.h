#include "AreaObj/ImageEffectArea.h"

class PostOutlineArea : public ImageEffectArea
{
public:
	PostOutlineArea(const char *);

	virtual ~PostOutlineArea();
	virtual void init(const JMapInfoIter &);
	virtual const char* getManagerName() const;

	s32 getIntensity() const;
};
