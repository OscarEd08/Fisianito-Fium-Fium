#include "Game/EnemyManager.hpp"

EnemyManager::EnemyManager(){
    initVariables();    
}

void EnemyManager::initVariables(){
    spawnTimerMax = 500.0f;
    spawnTimer = spawnTimerMax;
    maxEnemies = 10;
}

void EnemyManager::updateManager(){
    
    if(spawnTimer < spawnTimerMax)
        spawnTimer += 1.0f;
    else{
        if(enemies.size() < maxEnemies){
            enemies.push_back(Enemy());
            spawnTimer = 0.0f;
        }
    }
    for (int i = 0; i < enemies.size(); i++)
        {
            enemies[i].update();
            enemies[i].checkCollisionWithPlatforms(map.platforms);
        }
}

void EnemyManager::initEnemies(){
    for(int i = 0; i < enemies.size(); i++){
        enemies[i].initEnemy();
        enemies[i].initShape();
    }
}

void EnemyManager::renderEnemies(sf::RenderTarget *target){
    for(auto i: enemies){
        i.renderOnGame(target);
    }
}
