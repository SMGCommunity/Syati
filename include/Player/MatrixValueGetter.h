#pragma once

#include "NameObj/NameObj.h"
#include "Util/HashUtil.h"

struct MatrixValueEntry
{
	const char* mKey; // _0
	f32 mValue; // _4
};

typedef MatrixValueEntry MatrixValueTable[];

class MatrixValueGetter : public NameObj
{
public:
	MatrixValueGetter(const char *, MatrixValueTable *);

	virtual ~MatrixValueGetter();

	bool getValue(const char *, f32 *);

	MatrixValueTable* mTable; // _14
	HashSortTable* mHashTable; // _18
};
