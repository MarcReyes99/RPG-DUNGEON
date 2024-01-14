#pragma once
#include "MapPosition.h"

struct Enemy {
	MapPosition position;

	bool isDead;

	int health;
	int maxHealth;

	int stamina;
	int maxStamina;

	int agility;
	int maxAgility;

	void Initialize();
};

