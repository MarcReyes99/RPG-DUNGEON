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
			if (i == mm->player->position.y && j == mm->player->position.x) {
				std::cout << "| P |";
			}
			/*else if (i == mm->enemies->position.y && j == mm->enemies->position.x) {
				std::cout << "| E |";
			}
			else if (i == mm->chests->position.y && j == mm->chests->position.x) {
				std::cout << "| C |";
			}*/
			else {
				std::cout << "| " << map[i][j] << " " << "|";
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
			std::cout << "You went north" << std::endl;
		}
		break;
	case 'A':
	case 'a':
		if (mm->player->position.x > 0) {
			mm->player->position.x--;
			mm->player->agility--;
			std::cout << "You went west" << std::endl;
		}
		break;
	case 'S':
	case 's':
		if (mm->player->position.y < 4) {
			mm->player->position.y++;
			mm->player->agility--;
			std::cout << "You went south" << std::endl;
		}
		break;
	case 'D':
	case 'd':
		if (mm->player->position.x < 4) {
			mm->player->position.x++;
			mm->player->agility--;
			std::cout << "You went east" << std::endl;
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

}
void GameOver(MainManager* mm) {

}