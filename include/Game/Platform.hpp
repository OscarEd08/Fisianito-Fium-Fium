#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Platform : public Entity
{
private:
    void initVariables();

public:
    // Variables
    sf::Texture texture;
    // Constructor-Destructor
    Platform();
    virtual ~Platform();

    // Functions
    void movePlatform();
    void update();

};