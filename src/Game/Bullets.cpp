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

void Bullets::updateBullets()
{
    BulletNode *head = bulletsList;
    int cont = 0;
    while (head)
    {
        head->value.updateBullet();
        head = head->next_node;
        cont++;
    }
    // std::cout << "Number of bullets: " << cont << std::endl;
    deleteBulletsFromList();
}

void Bullets::deleteBulletsFromList()
{
    if (!bulletsList)
    {
        return;
    }

    // If head bullet has colide
    if (bulletsList->value.hasCollide)
    {
        bulletsList = bulletsList->next_node;
    }
    BulletNode *head = bulletsList;

    while (head)
    {

        Bullet currentBullet = head->value;
        if (currentBullet.hasCollide)
        {
            if (head->next_node)
            {

                head = head->next_node;
            }
        }

        head = head->next_node;
    }
}