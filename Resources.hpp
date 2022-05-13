#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

struct Resources
{
    // Elements textures

    // Statiques texture
    sf::Texture m_walls[1];
    sf::Texture m_players_life[1];
    sf::Texture m_ladders[1];
    sf::Texture m_barrels[3];

    // Images for dynamic animation
    sf::Image m_player_img[5];
    sf::Image m_dk_img[5];
    sf::Image m_flames_img[2];
    sf::Image m_peach_img[2];

    // Fonts
    sf::Font m_fonts[1];
    sf::Text m_text_score[1];

    sf::Music m_music[1];

    static void load_resources1(Resources *resources);
};
