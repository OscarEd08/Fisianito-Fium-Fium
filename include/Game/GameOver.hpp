#pragma once

#include <SFML/Graphics.hpp>
#include "GameTextures.hpp"
#include "GameFonts.hpp"
#include "Player.hpp"
#include "Score.hpp"

class GameOver
{
private:
    
public:
    GameOver();
public:
    bool isRetryButtonPressed;
    sf::Text finalScore;
private:
    Player player;
    GameTextures texture;
    sf::Sprite sp_gameOver;

    //Text on screen
    GameFonts font;
    sf::Text gameOverTitle;
    sf::Text retryButton;
    sf::Text exitButton;

    //Buttons
    bool isRetryButtonSelected;
    //bool isRetryButtonPressed;

    bool isExitButtonSelected;
    bool isExitButtonPressed;

private:
    void updateInput();

public:
    void initVariables();
    void updateScore(Score score);
    void update(sf::RenderWindow *window);
    void renderBackground(sf::RenderTarget *target);


};
