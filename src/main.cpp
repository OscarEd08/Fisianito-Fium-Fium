#include <iostream>
#include "Menu.hpp"
#include "Game.hpp"

int main()
{
    Game game;
    Menu menuPrincipal(game.window->getSize().x,game.window->getSize().y);
    //Variables de tiempo para la animación
    sf::Clock clock;
   

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
                                    //Pedir Nombre
                                    while(!menuPrincipal.nameEntered){
                                    
                                    for (sf::Event eventName; game.window->pollEvent(eventName);){

                                        if(eventName.type == sf::Event::TextEntered){
                                            if (eventName.text.unicode == 8){   // BORRAR
                                                menuPrincipal.namePlayerString =menuPrincipal.namePlayerString.substr(0, menuPrincipal.namePlayerString.size() - 1);
                                            }
                                            else menuPrincipal.namePlayerString += eventName.text.unicode;
                                        }

                                        if(eventName.type == sf::Event::KeyReleased){
                                            if (eventName.key.code == sf::Keyboard::Enter) menuPrincipal.nameEntered=true;
                                        }

                                        game.window->clear(sf::Color::Black);
                                        menuPrincipal.makingTextField(*game.window);
                                        game.window->display();
                                        }
                                    }
                                    
                                    std::cout<<"\nInicio Juego";
                                    std::cout<<"\nNOMBRE "<<menuPrincipal.namePlayerString;
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
                                    std::cout<<"\nAbrir Puntuaciones";
                                    game.window->clear(sf::Color::Black);break;

                                case 2:
                                    //Salir
                                    std::cout<<"\nSalir";
                                    game.window->close();
                                    
                            }
                    }break;
            }
        }

        game.window->clear(sf::Color::Black);
        menuPrincipal.draw(*game.window);
        game.window->display();
    }
  
    return 0;
}