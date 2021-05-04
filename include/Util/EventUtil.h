#pragma once

#include "kamek.h"

namespace MR
{
	s32 getPlayerLeft();
	
	bool isPlayerLuigi();
	s32 getStarPieceNum();
	void addStarPiece(int);

	void incCoin(int);

	s32 getCoinNum();

	s32 getPurpleCoinNum();
};
