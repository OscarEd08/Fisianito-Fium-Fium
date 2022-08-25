#pragma once

#include <SFML/Graphics.hpp>
#include "GameTextures.hpp"
#include "GameFonts.hpp"
#include "DataStructures/ScoreRecordNode.hpp"
#include "DataStructures/TextNode.hpp"

class ScoreWindow
{
public:
    ScoreWindow();

    sf::Event scoreEV;

private:
    sf::Text finalScore;
    GameTextures texture;
    sf::Sprite sp_gameOver;
    sf::Text scoresText;
    sf::Text exitText;
    sf::Text backToStartText;
    TextNode *scoreList = nullptr;

    // Text on screen
    GameFonts font;

    int menuOptionSelected;

private:
    void updateInput();
    void insertToScoreList(std::string text);

public:
    sf::RenderWindow *window; // = new sf::RenderWindow(1280, 720, "GAME TESTING", sf::Style::Titlebar | sf::Style::Close);

    void initVariables();
    void fillScoreList(ScoreRecordNode *score);
    void moveUp();
    void moveDown();
    void KeyboardReleased(sf::Event ev, sf::RenderWindow *window);
    void renderBackground();
};