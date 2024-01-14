#pragma once
#include "MapPosition.h"

struct Player {

	MapPosition position;

	bool isDead;

	int health;
	int maxHealth;

	int stamina;
	int maxStamina;

	int agility;
	int maxAgility;

	int potions;
	int maxPotions;

	int gold;

	void Initialize();

};