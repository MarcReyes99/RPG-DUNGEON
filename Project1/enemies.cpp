#include "Enemies.h"
#include "time.h"
#include "stdlib.h"

void Enemy::Initialize() {

	do {
		position.x = 0 + rand() % (4 + 1 - 0);
		position.y = 0 + rand() % (4 + 1 - 0);

	} while (position.x == 2 && position.y == 3);

	isDead = false;

	health = 60 + rand() % (90 + 1 - 60);
	maxHealth = 90;

	stamina = 60 + rand() % (90 + 1 - 60);
	maxStamina = 90;
}