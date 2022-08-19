#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameTextures.hpp"

class MainMenu{

    private:
        int mainMenuSelected;
        sf::Text mainMenuText[3];
        enum gameOptions {startGame,viewPoints,exit};

    public:
        MainMenu(float width,float height);
        ~MainMenu();

        void drawMenu(sf::RenderWindow& windowMenu);
        void moveUp();
        void moveDown();

        int mainMenuPressed(){
            return mainMenuSelected;
        }
};