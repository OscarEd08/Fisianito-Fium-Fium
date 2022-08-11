#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "Collision.hpp"
#include "GameTextures.hpp"
#include "Entity.hpp"
#include "DataStructures/EntityNode.hpp"
class Player : public Entity
{

// Constructor-Destructor
public:
    Player();
    virtual ~Player();
// Atributos
public:
    bool isJumping;
private:
    // Objects
    GameTextures texture;
    Animation *animation;
    // Gravity Variables
    int groundHeight;
    int roofHeight;
    float gravitySpeed;

    // Animation variables
    unsigned int row;
    float moveSpeed;
    bool faceRight;

// Métodos
private:
    void initVariables();
    void initPlayer();
    void initObjects();
    void gravity();
    void updateInput();
    bool playerIsOnPlatform(Entity platform);
public:
    void update();
    void windowsCollision();
    void checkCollisionWithPlatforms(EntityNode *platforms);
    void checkCollisionWithObjects(EntityNode *objects);
    // other functions
    sf::Vector2f getPosition() { return shape.getPosition(); }
    //Collision getCollision(){ return Collision(shape); }
};