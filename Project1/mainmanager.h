#pragma once
#include "Player.h"
#include "Enemies.h"
#include "Chests.h"
#include "vector"
#include <thread>
#include <chrono>

enum Scene { DUNGEON, COMBAT, CHEST, GAMEOVER };

struct MainManager {

	Scene currentScene;
	bool gameFinished;

	Player* player;
	std::vector<Enemy*> enemies;
	std::vector<RandomChest*> chests;

	void Initialize();
	void MoveEnemies();
};
