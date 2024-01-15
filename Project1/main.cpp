#include <iostream>
#include "mainmanager.h"
#include "mapposition.h"
#define MAP_SIZE 5
#include <cstdlib>
#include <thread>
#include <chrono>



void Dungeon(MainManager* mm, char map[MAP_SIZE][MAP_SIZE], char &direction);
void Combat(MainManager* mm);
void Chest(MainManager* mm);
void GameOver(MainManager* mm);

int main() {
	srand(time(NULL));
	MainManager* mm = new MainManager;
	mm->Initialize();
	char direction = ' ';

	char map[MAP_SIZE][MAP_SIZE]{
			{' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' '},
	};

	do {
		switch (mm->currentScene)
		{
		case DUNGEON:
			Dungeon(mm, map, direction);
			break;
		case COMBAT:
			Combat(mm);
			break;
		case CHEST:
			Chest(mm);
			break;
		case GAMEOVER:
			GameOver(mm);
			break;
		default:
			break;
		}
	} while (!mm->gameFinished);
}

void Dungeon(MainManager* mm, char map[MAP_SIZE][MAP_SIZE], char& direction) {

	system("cls");

	std::cout << "-----DUNGEON-----" << std::endl << std::endl;

	std::cout << "E -> Enemy";
	std::cout << "   ";
	std::cout << "P -> Player";
	std::cout << "   ";
	std::cout << "C -> Chest" << std::endl;

	std::cout << "Health: " << mm->player->health << "/" << mm->player->maxHealth << std::endl;
	std::cout << "Potions: " << mm->player->potions << "/" << mm->player->maxPotions << std::endl;
	std::cout << "Moves: " << mm->player->agility << "/" << mm->player->maxAgility << std::endl;

	std::cout << " ___  ___  ___  ___  ___" << std::endl;
	for (int i = 0; i < 5; ++i) {
		std::cout << "|   ||   ||   ||   ||   |" << std::endl;
		for (int j = 0; j < 5; ++j) {
			bool isPlayer = (i == mm->player->position.y && j == mm->player->position.x);
			bool isEnemy = false;
			bool isChest = false;
			for (const auto& enemy : mm->enemies) {
				if (i == enemy->position.y && j == enemy->position.x) {
					isEnemy = true;
					break;
				}
			}
			for (const auto& chest : mm->chests) {
				if (i == chest->position.y && j == chest->position.x) {
					isChest = true;
					break;
				}
			}
			if (isPlayer) {
				std::cout << "| P |";
			}
			else if (isEnemy) {
				std::cout << "| E |";
			}
			else if (isChest) {
				std::cout << "| C |";
			}
			else {
				std::cout << "| " << map[i][j] << " |";
			}
		}
		std::cout << std::endl;
		std::cout << "|___||___||___||___||___|" << std::endl;
	}

	std::cout << "W A S D --> Move" << std::endl;
	std::cout << "P --> Potion" << std::endl << std::endl;

	std::cout << "Enter your action: ";
	std::cin >> direction;

	switch (direction) {
	case 'W':
	case 'w':
		if (mm->player->position.y > 0) {
			mm->player->position.y--;
			mm->player->agility--;
		}
		break;
	case 'A':
	case 'a':
		if (mm->player->position.x > 0) {
			mm->player->position.x--;
			mm->player->agility--;
		}
		break;
	case 'S':
	case 's':
		if (mm->player->position.y < 4) {
			mm->player->position.y++;
			mm->player->agility--;
		}
		break;
	case 'D':
	case 'd':
		if (mm->player->position.x < 4) {
			mm->player->position.x++;
			mm->player->agility--;
		}
	case 'P':
	case 'p':
		if ((mm->player->maxHealth - mm->player->health) <= (mm->player->maxHealth * 0.6) && mm->player->potions > 0) {
			mm->player->health = mm->player->maxHealth;
			mm->player->potions--;
		}
		else if (mm->player->potions > 0){
			mm->player->health += mm->player->maxHealth * 0.4;
			mm->player->potions--;
		}
		else {
			std::cout << "You can't heal because you don't have potions!" << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		break;
	default:
		std::cout << "Invalid input. Please enter W/A/S/D to move." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		break;
	}

	mm->MoveEnemies();
	
	for (const auto& chest : mm->chests) {
		if (mm->player->position.x == chest->position.x && mm->player->position.y == chest->position.y) {
			mm->currentScene = CHEST;
		}
	}
}


void Combat(MainManager* mm) {

}
void Chest(MainManager* mm) {

	std::cout << "----- CHEST -----" << std::endl << std::endl;
	std::cout << "< You open the chest and contains the following:  " << std::endl << std::endl;
	if (!mm->chests.empty()) {
		RandomChest* randomChest = mm->chests[0];
		std::cout << ">" << randomChest->gold << "gold!";
		mm->player->gold += randomChest->gold;
		std::cout << "> The chest contains a Gear!";
		if (randomChest->gear == 1) {
			std::cout << "> Richard's Hatred: +200g, +20HP, +40 STAMINA, +1 AGILITY";
			mm->player->gold += 200;
			mm->player->health += 20;
			mm->player->stamina += 40;
			mm->player->agility += 1;
		}
		else if (randomChest->gear == 2) {
			std::cout << "> Swift Boots: +10g, -10HP, -5 STAMINA, +1 AGILITY";
			mm->player->gold += 10;
			mm->player->health += -10;
			mm->player->stamina += -5;
			mm->player->agility += 1;
		}
		else if (randomChest->gear == 3) {
			std::cout << "> White Powder: +150g, +20HP, +40 STAMINA, +1 AGILITY";
			mm->player->gold += 200;
			mm->player->health += 20;
			mm->player->stamina += 40;
			mm->player->agility += 1;
		}
		else if (randomChest->gear == 4) {
			std::cout << "> Radev's Mug: -300g, -20HP, -40 STAMINA, -1 AGILITY";
			mm->player->gold += -300;
			mm->player->health += -20;
			mm->player->stamina += -40;
			mm->player->agility += -1;
		}
		else if (randomChest->gear == 5) {
			std::cout << "> Raven Feather: 50g, -10HP, +2 AGILITY";
			mm->player->gold += 50;
			mm->player->health += -10;
			mm->player->agility += 2;
		}
		else if (randomChest->gear == 6) {
			std::cout << "> Red Mushroom: +170g, +30HP";
			mm->player->gold += 170;
			mm->player->health += 30;
		}
		else if (randomChest->gear == 7) {
			std::cout << "> Ugly Facemask: +10g, +5HP";
			mm->player->gold += 10;
			mm->player->health += 5;
		}
		else if (randomChest->gear == 8) {
			std::cout << "> Broken Shield: +25g, +10HP";
			mm->player->gold += 25;
			mm->player->health += 10;
		}
		else if (randomChest->gear == 9) {
			std::cout << "> Green Mushroom: -50g, -10 STAMINA";
			mm->player->gold += -50;
			mm->player->stamina += -10;
		}
		else if (randomChest->gear == 10) {
			std::cout << "> Naughty Book: 69g, +7 STAMINA";
			mm->player->gold += 69;
			mm->player->stamina += 7;
		}
	}
}
void GameOver(MainManager* mm) {

}