#pragma once

#include <SFML/Graphics.hpp>
#include "GameTextures.hpp"
#include "GameFonts.hpp"

class GameOver
{
private:
    
public:
    GameOver();
public:
    bool restartGame;
private:
    GameTextures texture;
    sf::Sprite sp_gameOver;

    //Text on screen
    GameFonts font;
    sf::Text gameOverTitle;
    sf::Text retryButton;
    sf::Text exitButton;

    //Buttons
    bool isRetryButtonSelected;
    bool isRetryButtonPressed;

    bool isExitButtonSelected;
    bool isExitButtonPressed;

private:
    void updateInput();

public:
    void initVariables();
    void update(sf::RenderWindow *window);
    void renderBackground(sf::RenderTarget *target);


};
