#pragma once
#include "Player.h"
#include "Enemies.h"
#include "Chests.h"
#include "vector"

enum Scene { DUNGEON, COMBAT, CHEST, GAMEOVER };

struct MainManager {

	Scene currentScene;
	bool gameFinished;

	Player* player;
	std::vector<Enemy*> enemies;
	std::vector<Chest*> chests;

	void Initialize();
	void MoveEnemies() {};
};
