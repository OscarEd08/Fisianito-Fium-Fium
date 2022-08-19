#include "Game/Bullets.hpp"
#include <iostream>
void Bullets::shotBullet(float playerYCord, float playerXCord, float playerHeight, Directions playerDirection)
{
    float bulletYPos = playerYCord;
    float bulletXPos = playerXCord;
    if (playerDirection == Directions::Left)
    {
        bulletXPos -= playerHeight + 5.0f;
    }
    else
    {
        bulletXPos += playerHeight + 5.0f;
    }
    Bullet newBullet;
    newBullet.initAttributes(bulletXPos, bulletYPos, 25.0f, 25.0f);
    newBullet.initShape();
    newBullet.setBulletDirection(playerDirection);
    if (!bulletsList)
    {
        bulletsList = new BulletNode();
        bulletsList->value = newBullet;
        return;
    }
    BulletNode *head = bulletsList;
    while (head->next_node)
    {
        head = head->next_node;
    }
    head->next_node = new BulletNode();
    head->next_node->value = newBullet;
    head->next_node->value.logEntity();
}

void Bullets::renderBullets(sf::RenderTarget *target)
{
    BulletNode *head = bulletsList;
    while (head)
    {
        Entity bullet = head->value;
        bullet.renderOnGame(target);
        head = head->next_node;
    }
}

void Bullets::updateBullet()
{
    BulletNode *head = bulletsList;
    while (head)
    {
        head->value.updateBullet();
        head = head->next_node;
    }
}