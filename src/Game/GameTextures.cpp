#include "Game/GameTextures.hpp"

GameTextures::GameTextures()
{
    // ASSETS DEBEN ESTAR EN MISMA CARPETA QUE EJECUTABLE
    playerTexture.loadFromFile("../assets/img/spritePlayer1.png");
    trampTexture.loadFromFile("../assets/img/tramp.png");
    bulletTexture.loadFromFile("../assets/img/bullet.png");
    ghostTexture.loadFromFile("../assets/img/ghost.png");
    bgTexture.loadFromFile("../assets/img/bgTexture.png");
    gameOverTexture.loadFromFile("../assets/img/gameOver.png");
    bgScores.loadFromFile("../assets/img/puntajesBg.png");
    heartTexture.loadFromFile("../assets/img/heart.png");
    lifeBarTexture.loadFromFile("../assets/img/life_bar.png");
    menuTexture.loadFromFile("../assets/img/menuTexture.png");
    // Platforms
    platformTexture.loadFromFile("../assets/img/plataformTexture.png");
    platformTexture.setRepeated(true);
}
