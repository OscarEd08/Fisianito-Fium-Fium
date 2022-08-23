#include "Game/Maps.hpp"
#include <iostream>
#include <stdlib.h>
#include <ctime>

Maps::Maps(){

    initVariables();
    createLifeBar();
    createPlatforms();
    createObjects();
    createHearts();
}

void Maps::initVariables(){
    this->baseX = 0;
    this->baseY = 150;
    this->screenWidth = 1280;
    this->heightPlatform = 30.0f;
    this->heightObject = 30.0f;
}

//BackGround
void Maps::initBackground(){
    sp_background.setTexture(texture.bgTexture);
}

void Maps::renderBackground(sf::RenderTarget *target){
    target->draw(sp_background);
}

//Show score on screen
void Maps::initTextScore(){
    score_text.setFont(font.font_score);
    score_text.setCharacterSize(20);
    score_text.setPosition(1100,25);
}

void Maps::updateTextScore(Score score){
    score_text.setString("Score: "+std::to_string(score.getScore()));
}

void Maps::renderTextScore(sf::RenderTarget *target){
    target->draw(score_text);
}

//Create life bar
void Maps::createLifeBar(){
    lifeBar.initAttributes(50,25,300.0f,25.0f);
    lifeBarBack.initAttributes(50,25,300.0f,25.0f);
}

void Maps::initLifeBar(){
    lifeBar.initShape();
    lifeBar.initTexture(texture.lifeBarTexture);
    lifeBarBack.initShape();
}

void Maps::updateLifeBar(Player player){
    float hpPercent = static_cast<float>(player.live) / 100;
    lifeBar.initAttributes(50,25,300.f * hpPercent,25.0f);
    lifeBar.initShape();
}

void Maps::renderLifeBar(sf::RenderTarget *target){
    lifeBarBack.renderOnGame(target);
    lifeBar.renderOnGame(target);
}

// Create & Render Platforms
void Maps::createPlatforms()
{
    platforms = new EntityNode();
    EntityNode *head = platforms;

    for (int i = 0; i < 4; i++){
        int addY = 180 * i;
        switch (i){
            case 0: widthPlaform = 580.0f; break;
            case 1: widthPlaform = 200.0f; break;
            case 2: widthPlaform = 500.0f; break;
            case 3: widthPlaform = 1280.0f; heightPlatform = 100.0f; addY = 520; break;
        }
        for (int j = 0; j < 2; j++){
            Platform platform;
            int addX = (screenWidth-widthPlaform) * j;
            platform.initAttributes(baseX + addX, baseY + addY, widthPlaform, heightPlatform);
        
            head->value = platform;
            head->next_node = new EntityNode();
            head = head->next_node;

            if (i == 1 && j == 1){
                Platform centerPlatform;
                widthPlaform = 350.0f;
                centerPlatform.initAttributes((screenWidth - widthPlaform) / 2, baseY + 180, widthPlaform, heightPlatform + 20.0f);

                head->value = centerPlatform;
                head->next_node = new EntityNode();
                head = head->next_node;
            }
        }
    }
}

void Maps::initPlatforms(){
    EntityNode *head = platforms;
    while(head){
        head->value.initShape();
        head->value.initTexture(texture.platformTexture);
        head = head->next_node;
    }
}

void Maps::renderPlatforms(sf::RenderTarget *target){
    EntityNode *head = platforms;
    while(head){
        head->value.renderOnGame(target);
        head = head->next_node;
    }
}

//Create & Render Objects
void Maps::createObjects(){
    objects = new EntityNode();
    EntityNode *head = objects;
    baseX = 300.0f;
    baseY -= heightObject; 

    for (int i = 0; i < 2; i++){
        int addY = 360 * i;
        switch (i){
            case 0: widthObject = 80.0f; break;
            case 1: widthObject = 60.0f; break;
        }
        for (int j = 0; j < 2; j++){
            Entity object;
            int addX = 600 * j;
            object.initAttributes(baseX + addX, baseY + addY, widthObject, heightObject);
        
            head->value = object;
            head->next_node = new EntityNode();
            head = head->next_node;        
        }
    }
}

void Maps::initObjects(){
    EntityNode *head = objects;
    while (head)
    {   
        head->value.initShape();
        head->value.initTexture(texture.trampTexture);
        head = head->next_node;
    }
}

void Maps::renderObjects(sf::RenderTarget *target){
    EntityNode *head = objects;
    while(head){
        head->value.renderOnGame(target);
        head = head->next_node;
    }
}

void Maps::createHearts()
{
    hearts = new EntityNode();
    EntityNode *head = hearts;
    float c_posX, c_posY = 100.0f, sumX;

    for (int i = 0; i < 3; i++){
        int addY = 180 * i;
        switch (i){
            case 0: c_posX = 200.0f; sumX = 860; break;
            case 1: c_posX = 100.0f; sumX = 1060; break;
            case 2: c_posX = 50.0f; sumX = 1160; break;
        }
        for(int j = 0; j < 2; j++){
            Entity heart;
            int addX =  sumX * j;
            heart.initAttributes(c_posX + addX, c_posY + addY, 30, 30);
            head->value = heart;
            head->next_node = new EntityNode();
            head = head->next_node;  

            if (i == 1 && j == 1){
                Entity centerHeart;
                centerHeart.initAttributes(630, c_posY + 180, 30, 30);

                head->value = centerHeart;
                head->next_node = new EntityNode();
                head = head->next_node;
            }
        }      
    }
}

void Maps::initHearts()
{
    EntityNode *head = hearts;
    while (head)
    {
        head->value.initShape();
        head->value.initTexture(texture.heartTexture);
        head = head->next_node;
    }
}

void Maps::renderHearts(sf::RenderTarget *target)
{
    EntityNode *head = hearts;
    while (head)
    {
        head->value.renderOnGame(target);
        head = head->next_node;
    }
}