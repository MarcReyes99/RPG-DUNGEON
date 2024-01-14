#pragma once
#include "MapPosition.h"

struct Chest {

	MapPosition position;
	int gold;
	bool isLooted;
	int gear;
	bool containsPotion;

	void Initialize();
};