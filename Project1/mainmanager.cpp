#include "MainManager.h"
#include "time.h"
#include "stdlib.h"
#include "Enemies.h"


void MainManager::Initialize() {
    currentScene = DUNGEON;
    gameFinished = false;

    player = new Player;
    player->Initialize();

    MoveEnemies();
}