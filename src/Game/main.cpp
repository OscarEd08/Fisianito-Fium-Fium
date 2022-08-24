#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "Game/Game.hpp"
#include "Game/Menu.hpp"
#include <stdlib.h>
#include <time.h>

int main()
{
    // Init Game
    srand(time(NULL));
    Game game;
    Menu menuPrincipal(1280,720);
    sf::RenderWindow *windowMenu = new sf::RenderWindow(sf::VideoMode(1280,720),"AAA MENU");
    sf::Clock clock;
    float accumulator = 0;
    const float timestep = 1.0f / 60.0f; // 60hz update frequency
    srand(time(NULL));

    //MENU FALTA UNIRLO CON GAME
    while (windowMenu->isOpen())
    {
        sf::Event event;
        while (windowMenu->pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::KeyReleased:
                    menuPrincipal.KeyboardReleased(event,windowMenu);
                    break;

                case sf::Event::Closed:
                    windowMenu->close(); break;
            }
        }

        windowMenu->clear(sf::Color::Black);
        menuPrincipal.draw(*windowMenu);
        windowMenu->display();
    }

    if(menuPrincipal.selectedOption()!=2){
        // Game loop
        while (game.running())
        {
            // Update
            accumulator += clock.restart().asSeconds();
            while (accumulator >= timestep)
            {
                accumulator -= timestep;
                game.update(clock.getElapsedTime().asMicroseconds());
            }

            // Render
            game.render();
        }
    }

    return 0;
}