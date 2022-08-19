#include "MainMenu.hpp"

MainMenu::MainMenu(float width, float height)
{
    //Opciones___
    //Game Start
    mainMenuText[startGame].setFillColor(sf::Color::Black);
    mainMenuText[startGame].setString(">Empezar");
    mainMenuText[startGame].setCharacterSize(50);
    mainMenuText[startGame].setPosition(480,490);

    //Puntajes

    mainMenuText[viewPoints].setFillColor(sf::Color::Black);
    mainMenuText[viewPoints].setString(">Puntuacion");
    mainMenuText[viewPoints].setCharacterSize(50);
    mainMenuText[viewPoints].setPosition(480,580);

    //Salir
    mainMenuText[exit].setFillColor(sf::Color::Black);
    mainMenuText[exit].setString(">Salir");
    mainMenuText[exit].setCharacterSize(50);
    mainMenuText[exit].setPosition(480,670);

    mainMenuSelected=-1;
};

MainMenu::~MainMenu(){
};

//Dibujar el Menu
void MainMenu::drawMenu(sf::RenderWindow& window){
    for(int i=0; i<3;++i){
        window.draw(mainMenuText[i]);
    }
};

//ARRIBA
void MainMenu::moveUp(){
    if(mainMenuSelected-1>=0){
        mainMenuText[mainMenuSelected].setFillColor(sf::Color::White);
        mainMenuSelected--;
        if(mainMenuSelected==-1){
            mainMenuSelected=2;
        }
        mainMenuText[mainMenuSelected].setFillColor(sf::Color::Yellow);
    }
};

//ABAJO
void MainMenu::moveDown(){
    if(mainMenuSelected+1<=3)
    {
        mainMenuText[mainMenuSelected].setFillColor(sf::Color::White);
        mainMenuSelected++;

        if(mainMenuSelected==3){
            mainMenuSelected=0;
        }
        mainMenuText[mainMenuSelected].setFillColor(sf::Color::Yellow);
    }
};
