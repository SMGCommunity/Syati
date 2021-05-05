#pragma once

#include "kamek.h"

class HashSortTable
{
public:
	HashSortTable(u32);

	bool add(const const char *, u32, bool);
	bool add(u32, u32);
	bool addOrSkip(u32, u32);
	void sort();
	bool search(u32, u32 *);
	bool search(const char *, u32 *);
	bool search(const char *, const char *, u32 *);
	void swap(const char *, const char *);
};

namespace MR
{
	u32 getHashCode(const char *);
	u32 getHashCodeLower(const char *);
};
