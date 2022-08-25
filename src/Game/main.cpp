#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "Game/Game.hpp"
#include "Game/Menu.hpp"
#include "Game/Score.hpp"
#include <stdlib.h>
#include <time.h>

int main()
{
    // Init Game
    srand(time(NULL));
    Game game;
    Menu menuPrincipal(game.window->getSize().x,game.window->getSize().y);
    sf::Clock clock;

    float accumulator = 0;
    const float timestep = 1.0f / 60.0f; // 60hz update frequency
    srand(time(NULL));

    //MENU FALTA UNIRLO CON GAME
    while (game.window->isOpen())
    {
        sf::Event event;
        while (game.window->pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::KeyReleased:
                    switch(event.key.code)
                    {
                        case sf::Keyboard::Up:
                                menuPrincipal.MoveUp();break;
                        case sf::Keyboard::Down:
                            menuPrincipal.MoveDown();break;

                        case sf::Keyboard::Return:
                            switch(menuPrincipal.selectedOption())
                            {
                                case 0:
                                    //Empieza a jugar
                                    std::cout<<"\nInicio Juego"<<std::endl;
                                    // Game loop
                                    while (game.running())
                                    {
                                            clock.restart();
                                            // Update
                                            game.update(clock.getElapsedTime().asMicroseconds());
                                            // Render
                                            game.render();
                                            //Restart clock
                                            clock.restart();
                                    } break;

                                case 1:
                                    //Ver puntuaciones
                                    Score().showScore();
                                    game.window->clear(sf::Color::Black);break;

                                case 2:
                                    //Salir
                                    std::cout<<"\nSalir";
                                    game.window->close();
                                    
                            }
                    }   break;
                case sf::Event::Closed:
                    game.window->close();
                break;
            }
        }    
        game.window->clear(sf::Color::Black);
        menuPrincipal.draw(*game.window);
        game.window->display();
    }

    return 0;
}