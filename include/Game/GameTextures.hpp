#pragma once

#include <SFML/Graphics.hpp>

class GameTextures
{
public:
    GameTextures();
    sf::Texture playerTexture;
    sf::Texture platformTexture;
    sf::Texture trampTexture;
    sf::Texture bulletTexture;
    sf::Texture ghostTexture;
    sf::Texture bgTexture;
    sf::Texture bgScores;
    sf::Texture gameOverTexture;
    sf::Texture heartTexture;
    sf::Texture lifeBarTexture;
    sf::Texture menuTexture;
};
