#pragma once
#include "SFML/Graphics.hpp"
#include "GameTextures.hpp"

#define MAX_OPTIONS_MENU 3

class Menu
{
    public:
        Menu(float width, float height);
        ~Menu();

        void draw(sf::RenderWindow &window);
        void makingTextField(sf::RenderWindow &window);
        //Subir y Bajar Opcion Seleccionada
        void MoveUp();
        void MoveDown();
        //Presionar
        int selectedOption(){return selectedIndex;}
        
        //Text Name
        std::string namePlayerString="AAA";
        sf::Text namePlayer[2];
        sf::RectangleShape nameRectangle;
        bool nameEntered;

        sf::Sprite menuBg;
    
    private:
        int selectedIndex;
        GameTextures textures;
        sf::Text menu[MAX_OPTIONS_MENU];
};