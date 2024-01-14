#include "Player.h"
#include "time.h"
#include "stdlib.h"


void Player::Initialize() {

	position.x = 2;
	position.y = 3;

	isDead = false;

	health = 90 + rand() % (100 + 1 - 90);
	maxHealth = 110;

	stamina = 90 + rand() % (100 + 1 - 90);
	maxStamina = 110;

	agility = 3;
	maxAgility;

	potions = 0;
	maxPotions = 3;
}