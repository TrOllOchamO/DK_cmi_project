#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

struct Resources
{
    // Elements textures
    sf::Texture m_walls[1];
    sf::Image m_mario_img[4];
    sf::Texture m_marios_life;

    // Fonts
    sf::Font m_fonts[1];
    sf::Text m_text_score;

    void load_resources1();
};