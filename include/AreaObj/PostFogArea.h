#include "AreaObj/ImageEffectArea.h"

class PostFogArea : public ImageEffectArea
{
public:
	PostFogArea(const char *);

	virtual ~PostFogArea();
	virtual void init(const JMapInfoIter &);
	virtual const char* getManagerName() const;

	s32 getMinRange() const;
	s32 getMaxRange() const;
	s32 getAlpha() const;
	s32 getRed() const;
	s32 getGreen() const;
	s32 getBlue() const;
	s32 getGradType() const;
};
