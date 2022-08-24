#include <iostream>
#include "Menu.hpp"
#include "Game.hpp"

int main()
{
    sf::RenderWindow window1(sf::VideoMode(1280,720),"AAA MENU");
    Menu menuPrincipal(1280,720);
    Game game;
    //Variables de tiempo para la animación
    sf::Clock clock;
   
    clock.restart();

    //MENU FALTA UNIRLO CON GAME
    while (window1.isOpen())
    {
        sf::Event event;
        while (window1.pollEvent(event))
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
                                    std::cout<<"\nInicio Juego";
                                    window1.close(); break;

                                case 1:
                                    //Empieza a jugar
                                    std::cout<<"\nAbrir Puntuaciones";
                                    window1.clear(sf::Color::Black);break;

                                case 2:
                                    //Empieza a jugar
                                    std::cout<<"\nSalir";
                                    window1.close();
                                    
                            }
                    }break;

                case sf::Event::Closed:
                    window1.close(); break;
            }
        }

        window1.clear(sf::Color::Black);
        menuPrincipal.draw(window1);
        window1.display();
    }
    // Game loop
    if(menuPrincipal.selectedOption()!=2){
    while (game.running())
    {
        // Update
        game.update(clock.getElapsedTime().asMicroseconds());
        // Render
        game.render();
        //Restart clock
        clock.restart();
    }
    }
    return 0;
}