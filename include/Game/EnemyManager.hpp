#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Enemy.hpp"
#include "Player.hpp"
#include "Maps.hpp"

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
        void checkCollisionWithPlayer(Player player);
        void initEnemies();
        void updateManager();
        void renderEnemies(sf::RenderTarget *target);
};
