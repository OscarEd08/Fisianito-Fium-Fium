#include "Game/Bullets.hpp"
#include <iostream>
void Bullets::shotBullet(Player player)
{
    std::cout << "Fire fire piu piu piu " << std::endl;
    float bulletYPos = player.getYCord();
    float bulletXPos = player.getXCord();
    float playerHeight = player.getHeight();
    bulletYPos += playerHeight / 3.0f;
    Directions bulletDirection;
    if (player.isFacingRight())
    {
        bulletXPos += playerHeight;
        bulletDirection = Directions::Right;
    }
    else
    {
        bulletXPos -= playerHeight;
        bulletDirection = Directions::Left;
    }
    if (player.getFaceDirection() == Directions::Up)
    {
        std::cout << "Disparando pa arriba" << std::endl;
        bulletDirection = Directions::Up;
    }
    Bullet newBullet;
    newBullet.initAttributes(bulletXPos, bulletYPos, 10.0f, 10.0f);
    newBullet.initShape();
    newBullet.setBulletDirection(bulletDirection);
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