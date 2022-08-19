#pragma once
#include "Game/Bullet.hpp"
#include "Game/Player.hpp"
#include "DataStructures/BulletNode.hpp"
class Bullets
{
public:
    BulletNode *bulletsList = nullptr;
    // Bullet
    void renderBullets(sf::RenderTarget *target);
    void shotBullet(Player player);
    void updateBullets();
    void deleteBulletsFromList();
};
