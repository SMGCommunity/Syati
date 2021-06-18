#pragma once

#include "kamek.h"

class JMapInfoIter;

// Complete
class JMapLinkInfo
{
public:
	JMapLinkInfo();
	JMapLinkInfo(const JMapInfoIter & rIter, bool isLinked);

	void setLinkedInfo(const JMapInfoIter & rIter);
	bool isValid() const;
	void invalidate();
	void setLinkInfo(const JMapInfoIter & rIter);

	s16 mLinkId; // _0
	s16 mZoneId; // _2
	s16 mContext; // _4
};
