#include "Game/GameFonts.hpp"

GameFonts::GameFonts()
{
    // Game over fonts
    font_gameOver.loadFromFile("../assets/fonts/Endgame DEMO.otf");
    font_score.loadFromFile("../assets/fonts/Gameplay.ttf");
    font_menu.loadFromFile("../assets/fonts/menuFont.ttf");
}
