#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

struct Inputs
{
    bool leftKeyPressed = false;
    bool rightKeyPressed = false;
    bool upKeyPressed = false;

    // pull every event from the parameter sf::RenderWindow and update the struct atributes accordingly
    void update(sf::RenderWindow &m_window);
};
