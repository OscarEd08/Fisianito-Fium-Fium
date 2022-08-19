#pragma once
#include "Entity.hpp"
class Bullet : public Entity
{
    int damage;
    bool hasCollide;
    float directionX;
    float directionY;
    void checkCollisionWithBorders();

public:
    void setBulletDirection(Directions direction);
    void updateBullet();
    void initBullet();
    Bullet();
};