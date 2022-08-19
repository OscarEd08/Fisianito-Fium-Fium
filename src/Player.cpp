#include "Player.hpp"
#include <iostream>

// Constructor-Destructor
Player::Player()
{
    this->initVariables();
    this->shape.setOrigin(shape.getSize() / 2.0f);
    this->shape.setTexture(&texture.playerTexture);
    this->initObjects();
}

Player::~Player()
{
}

// Private functions
void Player::initVariables()
{
    // Position
    groundHeight = 600;
    roofHeight = 300;
    // Dimensions
    this->initAttributes(20, groundHeight, 50.f, 50.f);
    // Speed
    moveSpeed = 80.f;
    gravitySpeed = 0.98f;
    // Status
    isJumping = false;
    isOnPlatform = false;
    isMoving=false;
    

}

void Player::initObjects()
{  
    //Animacion general inicio
    this->animation = new Animation(getWitdh(),getHeight(),4,3);
    shape.setTextureRect(this->animation->uvRect);
    
    //creando ciclos de animacion
    this->createAnimationCycle();


}

// Functions

void Player::gravity()
{
    if (getYCord() < groundHeight && !isJumping && !isOnPlatform)
    {
        moveEntity(0.f, gravitySpeed);
    }
    if (getYCord() > roofHeight)
    {
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
        faceRight=false;
        isMoving=true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        movement.x += moveSpeed * deltaTime;
        faceRight=true;
        isMoving=true;
    }
    else{
        isMoving=false;
        isJumping =false;
    }
    getAction();
    shape.move(movement);
    updateCords();
    
}

void Player:: getAction()
{
    if(isMoving){

        if(faceRight){
            animationRow=runR;
        }
        else animationRow=runL;
        currentCycle=runJump;
    }

    else if(isJumping){

        if(faceRight){
            animationRow=jumpR;
        }
        else animationRow=jumpL;

        currentCycle=runJump;
    }

    else{
        if(faceRight){
            currentCycle=iddleR;
        }
        else currentCycle=iddleL;

        animationRow=iddleRow;
    }
}

void Player::update(float dt)
{
    gravity();
    updateInput();
    
    //Animacion
    //std::cout<<"\nEje X:"<<this->animation->uvRect.width;
    animation->update(animationRow,frameCycles[currentCycle],dt);
    shape.setTextureRect(this->animation->uvRect);
}


//INCERTAR EN LISTA CIRCULARES
void Player::createAnimationCycle()
{
    int numFrames=0;
    int startX;

    for(int frameCount=0; frameCount<5;frameCount++){

        if(frameCount!=2){
            numFrames=3;
        }
        else numFrames=7;

        if(frameCount==1 || frameCount==4)startX=150;
        else startX=0;

        // Crea la lista circular a utilizar
        // Primer frame
        frameCycles[frameCount] = new Frame();
        frameCycles[frameCount]->leftX = startX;
        frameCycles[frameCount]->nextFrame=frameCycles[frameCount];

        // Copias para recorrer... por donde recorres? ლ(ಠ_ಠ ლ)
        Frame *head=frameCycles[frameCount]; // Cabeza del ciclo

        // Llenando los frames segun numFrames
        for (int j = 1; j < numFrames; j++)
        {

            Frame *temp = new Frame();
            temp->leftX = j*50 + startX;        // se coloca el valor

            temp->nextFrame=frameCycles[frameCount];               //iguala al siguiente de la lista
            head->nextFrame=temp;
            head = head->nextFrame;
            //frameCycles[frameCount]=temp;                       //se incerta el nuevo en la cabecera
        }

    }
}

