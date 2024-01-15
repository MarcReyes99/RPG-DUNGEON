#include "Chests.h"
#include "time.h"
#include "stdlib.h"

void RandomChest::Initialize() {

	do {
		position.x = 0 + rand() % (4 + 1 - 0);
		position.y = 0 + rand() % (4 + 1 - 0);
	} while (position.x == 2 && position.y == 3);

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