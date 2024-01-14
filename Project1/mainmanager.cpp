#include "MainManager.h"
#include "time.h"
#include "stdlib.h"
#include "Enemies.h"
#include <iostream>


void MainManager::Initialize() {
    currentScene = DUNGEON;
    gameFinished = false;

    player = new Player;
    player->Initialize();

    for (int i = 0; i < rand() % 3 + 5; ++i) {
        Enemy* newEnemy = new Enemy;
        newEnemy->Initialize();
        while (newEnemy->position.x == player->position.x && newEnemy->position.y == player->position.y) {
            newEnemy->Initialize();
        }
        for (const auto& existingEnemy : enemies) {
            if (newEnemy->position.x == existingEnemy->position.x && newEnemy->position.y == existingEnemy->position.y) {
                newEnemy->Initialize();
            }
        }
        enemies.push_back(newEnemy);
    }
    for (int i = 0; i < 2; ++i) {
        RandomChest* newChest = new RandomChest;
        newChest->Initialize();
        while (newChest->position.x == player->position.x && newChest->position.y == player->position.y) {
            newChest->Initialize();
        }
        for (const auto& existingEnemy : enemies) {
            if (newChest->position.x == existingEnemy->position.x && newChest->position.y == existingEnemy->position.y) {
                newChest->Initialize();
            }
        }
        for (const auto& existingChest : chests) {
            if (newChest->position.x == existingChest->position.x && newChest->position.y == existingChest->position.y) {
                newChest->Initialize();
            }
        }
        chests.push_back(newChest);
    }

    MoveEnemies();
}