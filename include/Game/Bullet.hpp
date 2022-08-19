#pragma once
#include "Entity.hpp"
class Bullet : public Entity
{
    int damage;
    float directionX;
    float directionY;
    void checkCollisionWithBorders();

public:
    bool hasCollide;
    void setBulletDirection(Directions direction);
    void updateBullet();
    void initBullet();
    Bullet();
};