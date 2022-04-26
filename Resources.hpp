#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

struct Resources
{
    // Elements textures
    sf::Texture m_walls[1];
    sf::Image m_player_img[5];
    sf::Texture m_players_life[1];
    sf::Texture m_ladders[1];

    // Fonts
    sf::Font m_fonts[1];
    sf::Text m_text_score[1];

    static void load_resources1(Resources *resources);
};
