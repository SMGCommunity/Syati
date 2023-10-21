#pragma once

#include "Game/System/ResourceHolder.h"

struct XanimeGroupInfo;

class XanimeResourceTable
{
public:
	XanimeResourceTable(ResourceHolder*, XanimeGroupInfo*);

	void createSortTable();
	//J3DAnmTransform* findResMotion(const char*) const;
	const char* findStringMotion(const char*) const;
};