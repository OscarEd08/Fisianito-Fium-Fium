#pragma once

#include "Platform.hpp"
#include "GameTextures.hpp"
#include "Player.hpp"
#include "GameFonts.hpp"
#include "Score.hpp"
#include "DataStructures/EntityNode.hpp"

class Maps : public Entity
{
    // Constructor
public:
    Maps();

private:
    // Variables platform
    int baseX;
    int baseY;
    int screenWidth;
    float heightPlatform;
    float widthPlaform;

    // Variables object
    float heightObject;
    float widthObject;

    // Init functions
    void initVariables();
    // Platform functions
    void createPlatforms();
    // Objects
    void createObjects();
     //Hearts
    void createHearts();
    //Life bar
    void createLifeBar();

public:
    // Platform attributes & functions
    EntityNode *platforms;
    EntityNode *objects;
    EntityNode *hearts;
    GameTextures texture;
    sf::Sprite sp_background;
    //Life bar && Score on screen
    GameFonts font;
    sf::Text score_text;
    Entity lifeBar;
    Entity lifeBarBack;
    void initBackground();
    void renderBackground(sf::RenderTarget *target);
    void initTextScore();
    void updateTextScore(Score score);
    void renderTextScore(sf::RenderTarget *target);
    void initLifeBar();
    void updateLifeBar(Player player);
    void renderLifeBar(sf::RenderTarget *target);
    void initObjects();
    void renderObjects(sf::RenderTarget *target);
    void initPlatforms();
    void renderPlatforms(sf::RenderTarget *target);
    void initHearts();
    void renderHearts(sf::RenderTarget *target);
};