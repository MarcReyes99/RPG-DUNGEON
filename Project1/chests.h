#pragma once
#include "MapPosition.h"

struct RandomChest {

	MapPosition position;
	int gold;
	bool isLooted;
	int gear;
	bool containsPotion;

	void Initialize();
};