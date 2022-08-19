#include "GameTextures.hpp"

GameTextures::GameTextures()
{
    //ASSETS DEBEN ESTAR EN MISMA CARPETA QUE EJECUTABLE
    //TEXTURAS
    playerTexture.loadFromFile("assets/img/spritePlayer1.png");
    menuTexture.loadFromFile("assets/img/menuTexture.png");

    //FONTS
    menuFont.loadFromFile("assets/fonts/menuFont.ttf");
}
