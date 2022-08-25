#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class TextNode
{
public:
    sf::Text textValue;
    TextNode *next_node = nullptr;
};