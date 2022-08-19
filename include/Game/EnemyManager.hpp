#pragma once

#include <SFML/Graphics.hpp>
#include "Enemy.hpp"
#include "Maps.hpp"
#include <vector>

class EnemyManager
{
private:
    /* data */
public:
    EnemyManager();

private:
    std::vector<Enemy> enemies;
    Maps map;
    float spawnTimerMax;
    float spawnTimer;
    float maxEnemies;

private:
    void initVariables();

public:
    sf::FloatRect getBounds();
    void initEnemies();
    void updateManager(BulletNode *bullets);
    void removeDeadEnemies();
    void renderEnemies(sf::RenderTarget *target);
};