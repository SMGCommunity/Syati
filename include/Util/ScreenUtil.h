#pragma once

#include "kamek.h"

namespace MR
{
	void openSystemWipeCircle(s32 Fadetime); // Located at 0x80058C00 in USA. I don't want to change the symbol map
	void closeSystemWipeCircle(s32 Fadetime);
	void openSystemWipeFade(s32 Fadetime);
	void closeSystemWipeFade(s32 Fadetime);
	void closeSystemWipeCircleWithCaptureScreen(s32 Fadetime);
	void closeSystemWipeFadeWithCaptureScreen(s32 Fadetime);
	// Activate the Game Over wipe
	void startGameOverWipe();
	// Activate the Bowser wipe used when the player dies
	void startDownWipe();
	void openSystemWipeMario(s32 Fadetime);
	void closeSystemWipeMario(s32 Fadetime);
	bool isWipeActive();
	bool isWipeBlank();
	bool isWipeOpen();
	bool isSystemWipeActive();
};