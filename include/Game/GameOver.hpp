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
    sf::Text gameOverButton[3];

    int gameOverMenuSelected;

private:
    void updateInput();

public:
    void initVariables();
    void moveUp();
    void moveDown();
    int getPressedButton(){return gameOverMenuSelected;}
    void updateScore(Score score);
    void KeyboardReleased(sf::Event ev, sf::RenderWindow *window);
    void renderBackground(sf::RenderTarget *target);
};
