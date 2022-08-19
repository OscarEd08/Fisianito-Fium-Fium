#include <iostream>
#include "Game.hpp"
#include "MainMenu.hpp"

int main()
{
    sf::RenderWindow MENU(sf::VideoMode(1280,720),"MenuPrincipal",sf::Style::Default);
    MainMenu mainMenu(MENU.getSize().x,MENU.getSize().y);
    // Init Game
    /*
    Game game;
    //Variables de tiempo para la animación
    sf::Clock clock;
   
    clock.restart();

    // Game loop
    while (game.running())
    {
        // Update
        game.update(clock.getElapsedTime().asMicroseconds());
        // Render
        game.render();
        //Restart clock
        clock.restart();
    }
    */
    return 0;
}