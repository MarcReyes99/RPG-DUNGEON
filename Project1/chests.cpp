#include "Chests.h"
#include "time.h"
#include "stdlib.h"

void Chest::Initialize() {
	srand(time(NULL));



	gold = 50 + rand() % (200 + 1 - 50);

	isLooted = false;

	gear = 1 + rand() % (10 + 1 - 1);

	if (1 + rand() % (4 + 1 - 1) == 1) {
		containsPotion = true;
	}
	else {
		containsPotion = false;
	}
}