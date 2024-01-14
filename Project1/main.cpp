#include <iostream>
#include "mainmanager.h"
#include "mapposition.h"
#define MAP_SIZE 5
#include <cstdlib> 


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

	std::cout << "Enter direction: ";
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
		break;
	default:
		std::cout << "Invalid input. Please enter W/A/S/D to move." << std::endl;
		break;
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
		std::cout << "> The chest contains a Gear!";
		if (randomChest->gear == 1) {
			//std::cout << "< Richard's Hatred" << mm->player->gold += 200;
		}
	}
}
void GameOver(MainManager* mm) {

}