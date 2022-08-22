#pragma once

#include "Platform.hpp"
#include "GameTextures.hpp"
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

public:
    // Platform attributes & functions
    EntityNode *platforms;
    EntityNode *objects;
    GameTextures texture;
    sf::Sprite sp_background;
    void initBackground();
    void renderBackground(sf::RenderTarget *target);
    void initObjects();
    void renderObjects(sf::RenderTarget *target);
    void initPlatforms();
    void renderPlatforms(sf::RenderTarget *target);
};