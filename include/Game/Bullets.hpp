#pragma once
#include "Game/Bullet.hpp"
#include "DataStructures/BulletNode.hpp"
class Bullets
{
    BulletNode *bulletsList = nullptr;
    // Bullet
public:
    void renderBullets(sf::RenderTarget *target);
    void shotBullet(float playerYCord, float playerXCord, float playerHeight, Directions playerDirection);
    void updateBullet();
};
