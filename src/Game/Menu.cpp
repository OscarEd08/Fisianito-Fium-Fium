#include "Game/Menu.hpp"

Menu::Menu(float width, float height)
{
    menuBg.setTexture(textures.menuTexture);

    menu[0].setFont(font.font_menu);
    menu[0].setString(">Jugar");
    menu[0].setCharacterSize(45);
    menu[0].setFillColor(sf::Color::Yellow);
    menu[0].setPosition(sf::Vector2f(width * 0.27, 0.63 * height));

    menu[1].setFont(font.font_menu);
    menu[1].setString(">Ver Puntajes");
    menu[1].setCharacterSize(45);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setPosition(sf::Vector2f(width * 0.27, 0.73 * height));

    menu[2].setFont(font.font_menu);
    menu[2].setCharacterSize(45);
    menu[2].setString(">Salir");
    menu[2].setFillColor(sf::Color::White);
    menu[2].setPosition(sf::Vector2f(width * 0.27, 0.83 * height));

    selectedIndex = 0;
    // Naming Screen
    nameEntered = false;

    namePlayer[0].setFont(font.font_menu);
    namePlayer[0].setString("Ingrese Nombre");
    namePlayer[0].setCharacterSize(50);
    namePlayer[0].setFillColor(sf::Color::White);
    namePlayer[0].setPosition(sf::Vector2f(width / 3, height / 4));

    namePlayer[1].setFont(font.font_menu);
    namePlayer[1].setCharacterSize(45);
    namePlayer[1].setFillColor(sf::Color::Black);
    namePlayer[1].setPosition(sf::Vector2f(width / 3.2, 2 * height / 4));

    nameRectangle.setSize(sf::Vector2f(width - 2 * width / 1.4, 50));
    nameRectangle.setFillColor(sf::Color::White);
    nameRectangle.setPosition(sf::Vector2f(width / 1.4, 2 * height / 4));
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
    window.draw(menuBg);

    for (int i = 0; i < MAX_OPTIONS_MENU; i++)
    {

        window.draw(menu[i]);
    }
}

void Menu::makingTextField(sf::RenderWindow &window)
{
    namePlayer[1].setString(namePlayerString);
    window.draw(nameRectangle);

    for (int i = 0; i < 2; i++)
    {
        window.draw(namePlayer[i]);
    }
}
void Menu::MoveUp()
{
    if (selectedIndex - 1 >= 0)
    {
        menu[selectedIndex].setFillColor(sf::Color::White);
        selectedIndex--;
        menu[selectedIndex].setFillColor(sf::Color::Yellow);
    }
}

void Menu::MoveDown()
{
    if (selectedIndex + 1 < MAX_OPTIONS_MENU)
    {
        menu[selectedIndex].setFillColor(sf::Color::White);
        selectedIndex++;
        menu[selectedIndex].setFillColor(sf::Color::Yellow);
    }
}
