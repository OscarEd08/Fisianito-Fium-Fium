

#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "Collision.hpp"
#include "GameTextures.hpp"
#include "Entity.hpp"
#include "DataStructures/EntityNode.hpp"

class Enemy : public Entity
{

public:
    // Constructor-Destructor
    Enemy();
    virtual ~Enemy();

private:
    void initVariables();
    void initObjects();

public:
    // Objects
    GameTextures texture;

    // Gravity & Speed Variables
    float initPosX;
    float initPosY;
    bool isJumping;
    float moveSpeed;
    float fallSpeed;
    bool isSpawn;

private:
    bool playerIsOnPlatform(Entity platform);

public:
    void checkCollisionWithPlatforms(EntityNode *platforms);
    // Functions
    void initEnemy();
    void moveEnemy();
    void updateInput();
    void update();
};