#include "Game/Player.hpp"
#include <iostream>

// Constructor-Destructor
Player::Player()
{
    this->initVariables();
    this->initPlayer();
    // this->shape.setTexture(&texture.playerTexture);
    this->initObjects();
}

Player::~Player()
{
}

// Private functions
void Player::initVariables()
{
    // Position
    groundHeight = 620;
    roofHeight = 300;
    // Speed
    moveSpeed = 80.f;
    gravitySpeed = 2.0f;
    // Status
    isJumping = false;
    //isOnPlatform = false;
}

void Player::initPlayer(){
    this->initAttributes(20, groundHeight, 50.f, 50.f);
    this->shape.setOrigin(shape.getSize() / 2.0f);
    this->shape.setFillColor(sf::Color::Green);
}

void Player::initObjects()
{
    this->animation = new Animation(&texture.playerTexture, sf::Vector2u(2, 5), 1.0f);
}

// Functions

void Player::gravity()
{
    if (getYCord() < groundHeight && !isJumping && !isOnPlatform)
    {
        moveEntity(0.f, gravitySpeed);
    }
}

void Player::updateInput()
{
    float deltaTime = 0.07f;
    sf::Vector2f movement(0.0f, 0.0f);
    // Keyboard inputs
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) or sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        movement.y -= moveSpeed * deltaTime;
        isJumping = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        movement.x -= moveSpeed * deltaTime;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        movement.x += moveSpeed * deltaTime;
    }

    if (movement.x == 0.0f)
    {
        row = 0;
    }
    else
    {
        row = 1;
        if (movement.x > 0.0f)
        {
            faceRight = true;
        }
        else
        {
            faceRight = false;
        }
    }
    animation->update(row, deltaTime, faceRight);
    shape.setTextureRect(this->animation->uvRect);
    shape.move(movement);
    updateCords();
}

void Player::update()
{   
    gravity();
    updateInput();
    windowsCollision();
}

//Collision Player
void Player::windowsCollision()
{
    // Left collision
    if (shape.getPosition().x < 0.0f)
        shape.setPosition(0.0f, shape.getPosition().y);
    // Top collision
    if (shape.getPosition().y < 0.0f)
        shape.setPosition(shape.getPosition().x, 0.0f);
    // RIght collision
    if (shape.getPosition().x + shape.getGlobalBounds().width > 1280.0f)
        shape.setPosition(1280.0f - shape.getGlobalBounds().width, shape.getPosition().y);
}

void Player::checkCollisionWithObjects(EntityNode *objects){
    EntityNode *head = objects;
    while (head)
    {
        if (shape.getGlobalBounds().intersects(head->value.getShape().getGlobalBounds()))
        {
            shape.setFillColor(sf::Color::Red);
            std::cout<<"muere"<<std::endl;
            return;
        }
        shape.setFillColor(sf::Color::Green);
        head = head->next_node;
    }
}

void Player::checkCollisionWithPlatforms(EntityNode *platforms)
{
    EntityNode *head = platforms;
    while (head)
    {
        if (playerIsOnPlatform(head->value))
        {
            isOnPlatform = true;
            return;
        }
        head = head->next_node;
    }
    isOnPlatform = false;
}

inline bool epsilonEquals(const float x, const float y, const float epsilon = 1E-5f)
{
    return abs(x - y) <= epsilon;
}


bool Player::playerIsOnPlatform(Entity platform)
{
    /*
    Si la coordenada Y de player es platform.y - 50
    y la coordenada X de player está entre platform.X y platform.X + platform.width
    entonces player está sobre platform
    */
    int minusLimitOnX = platform.getXCord() - width;
    int superiorLimitOnX = platform.getXCord() + platform.getWitdh();
    int limitOnY = platform.getYCord() - this->height;

    if (posX > minusLimitOnX && posX < superiorLimitOnX && epsilonEquals(posY, limitOnY))
        return true;
    return false;
}