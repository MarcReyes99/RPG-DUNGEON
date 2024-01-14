#include "Enemies.h"
#include "time.h"
#include "stdlib.h"

void Enemy::Initialize() {

	position.x = 0 + rand() % (4 + 1 - 0);
	position.y = 0 + rand() % (4 + 1 - 0);

	isDead = false;

	health = 60 + rand() % (90 + 1 - 60);
	maxHealth = health;

	stamina = 60 + rand() % (90 + 1 - 60);
	maxStamina = stamina;
}