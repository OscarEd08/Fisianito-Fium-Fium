#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "Game/Game.hpp"
#include "Game/Menu.hpp"
#include "Game/Score.hpp"
#include <stdlib.h>
#include <time.h>
#include "api/DataBase.hpp"

int main()
{
    // Init Game
    srand(time(NULL));
    Score score;
    score.readScore();
    score.selection();
    score.scoreWindow.fillScoreList(score.points);
    Game game;
    Menu menuPrincipal(game.window->getSize().x, game.window->getSize().y);
    sf::Clock clock;

    float accumulator = 0;
    const float timestep = 1.0f / 60.0f; // 60hz update frequency
    srand(time(NULL));

    while (game.window->isOpen())
    {
        sf::Event event;
        while (game.window->pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    menuPrincipal.MoveUp();
                    break;
                case sf::Keyboard::Down:
                    menuPrincipal.MoveDown();
                    break;

                case sf::Keyboard::Return:
                    switch (menuPrincipal.selectedOption())
                    {
                    case 0:
                    {
                        // Pedir Nombre
                        while (!menuPrincipal.nameEntered)
                        {

                            for (sf::Event eventName; game.window->pollEvent(eventName);)
                            {

                                if (eventName.type == sf::Event::TextEntered)
                                {
                                    if (eventName.text.unicode == 8)
                                    { // BORRAR
                                        menuPrincipal.namePlayerString = menuPrincipal.namePlayerString.substr(0, menuPrincipal.namePlayerString.size() - 1);
                                    }
                                    else
                                    {
                                        menuPrincipal.namePlayerString += eventName.text.unicode;
                                    }
                                }

                                if (eventName.type == sf::Event::KeyReleased)
                                {
                                    if (eventName.key.code == sf::Keyboard::Enter)
                                        menuPrincipal.nameEntered = true;
                                }

                                game.window->clear(sf::Color::Black);
                                menuPrincipal.makingTextField(*game.window);
                                game.window->display();
                            }
                        }

                        game.setPlayerName(menuPrincipal.namePlayerString);

                        // Empieza a jugar
                        // Game loop
                        while (game.running())
                        {
                            clock.restart();
                            // Update
                            game.update(clock.getElapsedTime().asMicroseconds());
                            // Render
                            game.render();
                            // Restart clock
                            clock.restart();
                        }
                        break;
                    }

                    case 1:
                    {
                        score.scoreWindow.initVariables();
                        score.windowLogic();
                        break;
                    }

                    case 2:
                        // Salir
                        game.window->close();
                        break;
                    }
                }
            }
            game.window->clear(sf::Color::Black);
            menuPrincipal.draw(*game.window);
            game.window->display();
        }
    }
    return 0;
}