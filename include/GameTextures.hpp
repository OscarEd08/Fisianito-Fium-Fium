#pragma once

#include <SFML/Graphics.hpp>

class GameTextures
{
public:
    sf::Texture playerTexture;
    sf::Texture menuTexture;

    sf::Font menuFont;
    GameTextures();
};