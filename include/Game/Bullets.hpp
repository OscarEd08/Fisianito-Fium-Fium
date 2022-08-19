#pragma once
#include "Game/Bullet.hpp"
#include "DataStructures/BulletNode.hpp"
class Bullets
{
public:
    BulletNode *bulletsList = nullptr;
    // Bullet
    void renderBullets(sf::RenderTarget *target);
    void shotBullet(float playerYCord, float playerXCord, float playerHeight, Directions playerDirection);
    void updateBullets();
    void deleteBulletsFromList();
};
