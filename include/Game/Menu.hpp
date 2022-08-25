#pragma once
#include "SFML/Graphics.hpp"
#include "GameTextures.hpp"
#include "GameFonts.hpp"
#include <iostream>

#define MAX_OPTIONS_MENU 3

class Menu
{
    public:
        Menu(float width, float height);
        ~Menu();

        void draw(sf::RenderWindow &window);
        //Subir y Bajar Opcion Seleccionada
        void MoveUp();
        void MoveDown();
        //Presionar
        int selectedOption(){return selectedIndex;}

        sf::Sprite menuBg;
    
    private:
        int selectedIndex;
        GameTextures textures;
        GameFonts font;
        sf::Text menu[MAX_OPTIONS_MENU];
};