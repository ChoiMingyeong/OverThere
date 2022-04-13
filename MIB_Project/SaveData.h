#pragma once

#include <stdio.h>
#include <windows.h>

#include "Player.h"

struct SAV
{
	Player* p;
	POINT savepos;
	int room;
	int gamestate;
	long storystate;
};

void SaveFile(SAV** sav);
bool LoadFile(SAV** sav);