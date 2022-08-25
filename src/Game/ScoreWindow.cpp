#include "Game/ScoreWindow.hpp"
#include <iostream>
ScoreWindow::ScoreWindow()
{
}

void ScoreWindow::initVariables()
{

    menuOptionSelected = 1;
    int textVerticalPos = 150;
    TextNode *head = scoreList;
    while (head)
    {
        head->textValue.setFont(font.font_menu);
        head->textValue.setCharacterSize(30);
        head->textValue.setPosition(500, textVerticalPos);
        head = head->next_node;
        textVerticalPos += 50;
    }

    scoresText.setString("Jugador        Puntaje");
    scoresText.setFillColor(sf::Color::Red);
    scoresText.setFont(font.font_menu);
    scoresText.setCharacterSize(30);
    scoresText.setPosition(500, 100);
}

void ScoreWindow::insertToScoreList(std::string text)
{
    if (!scoreList)
    {
        scoreList = new TextNode();
        scoreList->textValue.setString(text);
        return;
    }
    TextNode *head = scoreList;
    while (head->next_node)
        head = head->next_node;
    head->next_node = new TextNode();
    head->next_node->textValue.setString(text);
}

void ScoreWindow::fillScoreList(ScoreRecordNode *score)
{
    while (score)
    {
        std::string text = score->playerName + "    " + std::to_string(score->score);
        insertToScoreList(text);
        score = score->next_node;
    }
}

void ScoreWindow::moveUp()
{
    if (menuOptionSelected - 1 > 0)
        menuOptionSelected--;
    if (menuOptionSelected == 1)
    {
        backToStartText.setFillColor(sf::Color::Red);
        exitText.setFillColor(sf::Color::White);
    }
}

void ScoreWindow::moveDown()
{

    if (menuOptionSelected + 1 < 3)
        menuOptionSelected++;
    if (menuOptionSelected == 2)
    {
        backToStartText.setFillColor(sf::Color::White);
        exitText.setFillColor(sf::Color::Red);
    }
}

void ScoreWindow::KeyboardReleased(sf::Event ev, sf::RenderWindow *window)
{
    switch (ev.key.code)
    {
    case sf::Keyboard::Up:
        moveUp();
        break;
    case sf::Keyboard::Down:
        moveDown();
        break;
    case sf::Keyboard::Enter:
        switch (menuOptionSelected)
        {
        case 0:
            break;
        case 1:
            window->close();
            break;
        case 2:
            window->close();
            break;
        }
        break;
    }
}

void ScoreWindow::renderBackground()
{

    sf::Sprite bg;
    bg.setTexture(texture.bgScores);
    window->clear(sf::Color::Black);
    window->draw(bg);
    window->draw(scoresText);

    TextNode *head = scoreList;
    while (head)
    {
        window->draw(head->textValue);
        head = head->next_node;
    }

    window->display();
}