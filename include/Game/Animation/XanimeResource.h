#pragma once

#include "Game/System/ResourceHolder.h"

struct XanimeGroupInfo;

class XanimeResourceTable
{
public:
	XanimeResourceTable(ResourceHolder*);

	void createSortTable();
	//J3DAnmTransform* findResMotion(const char*) const;
	const char* findStringMotion(const char*) const;
	u32 getSimpleIndex (const char *) const;
	u32 getSingleIndex (const char *) const;
	u8 _0[0x70];
};