#include "Game/Menu.hpp"

Menu::Menu(float width, float height)
{
    menuBg.setTexture(textures.menuTexture);

    menu[0].setFont(font.font_menu);
    menu[0].setString(">Jugar");
    menu[0].setCharacterSize(45);
    menu[0].setFillColor(sf::Color::Yellow);
    menu[0].setPosition(sf::Vector2f(width*0.27,0.63*height));

    menu[1].setFont(font.font_menu);
    menu[1].setString(">Ver Puntajes");
    menu[1].setCharacterSize(45);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setPosition(sf::Vector2f(width*0.27,0.73*height));

    menu[2].setFont(font.font_menu);
    menu[2].setCharacterSize(45);
    menu[2].setString(">Salir");
    menu[2].setFillColor(sf::Color::White);
    menu[2].setPosition(sf::Vector2f(width*0.27,0.83*height));
    
    selectedIndex=0;
}

Menu::~Menu(){

}

void Menu::draw(sf::RenderWindow &window)
{
    window.draw(menuBg);

    for(int i=0;i<MAX_OPTIONS_MENU;i++)
    {
        
        window.draw(menu[i]);
    }
}

void Menu::MoveUp()
{
    if(selectedIndex-1>=0)
    {
        menu[selectedIndex].setFillColor(sf::Color::White);
        selectedIndex--;
        menu[selectedIndex].setFillColor(sf::Color::Yellow);
    }
}

void Menu::MoveDown()
{
    if(selectedIndex+1<MAX_OPTIONS_MENU)
    {
        menu[selectedIndex].setFillColor(sf::Color::White);
        selectedIndex++;
        menu[selectedIndex].setFillColor(sf::Color::Yellow);
    }
}

void Menu::KeyboardReleased(sf::Event ev, sf::RenderWindow *window){
    switch (ev.key.code){
        case sf::Keyboard::Up:
            MoveUp();
            break;                
        case sf::Keyboard::Down:
            MoveDown();
            break;
        case sf::Keyboard::Enter:
            switch (selectedOption()){
                case 0:
                    //Empieza a jugar
                    std::cout<<"\nInicio Juego";
                    window->close(); break;

                case 1:
                    //Empieza a jugar
                    std::cout<<"\nAbrir Puntuaciones";
                    window->clear(sf::Color::Black);break;

                case 2:
                    //Empieza a jugar
                    std::cout<<"\nSalir";
                    window->close();  
            }
            break;            
    }
}