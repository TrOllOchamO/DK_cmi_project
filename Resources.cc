#include "Resources.hpp"

void Resources::load_resources1(Resources *resources)
{
    // Fonts
    if (!resources->m_fonts[0].loadFromFile("resources/fonts/arial.ttf"))
    {
        std::cout << "Error, could not load arial.ttf" << std::endl;
    }

    // Murs
    if (!resources->m_walls[0].loadFromFile("resources/images/mur1.jpg"))
    {
        std::cout << "Error, could not load mur1.jpg" << std::endl;
    }

    // Mario
    if (!resources->m_players_life[0].loadFromFile("resources/images/marios_life.png"))
    {
        std::cout << "Error, could not load marios_life.png" << std::endl;
    }
    if (!resources->m_player_img[0].loadFromFile("resources/images/mario_stopped.png"))
    {
        std::cout << "Error, could not load mario_stopped.png" << std::endl;
    }
    if (!resources->m_player_img[1].loadFromFile("resources/images/mario_running1.png"))
    {
        std::cout << "Error, could not load mario_running1.png" << std::endl;
    }
    if (!resources->m_player_img[2].loadFromFile("resources/images/mario_running2.png"))
    {
        std::cout << "Error, could not load mario_running2.png" << std::endl;
    }
    if (!resources->m_player_img[3].loadFromFile("resources/images/mario_jumping.png"))
    {
        std::cout << "Error, could not load mario_jumping.png" << std::endl;
    }
    if (!resources->m_player_img[4].loadFromFile("resources/images/mario_climbing_ladders.png"))
    {
        std::cout << "Error, could not load mario_climbing_ladders.png" << std::endl;
    }

    // Ladders
    if (!resources->m_ladders[0].loadFromFile("resources/images/ladders.png"))
    {
        std::cout << "Error, could not load ladders.png" << std::endl;
    }

    // Barrels
    if (!resources->m_barrels[0].loadFromFile("resources/images/barrel.png"))
    {
        std::cout << "Error, could not load barrel.png" << std::endl;
    }
    if (!resources->m_barrels[1].loadFromFile("resources/images/barrel_vertical.png"))
    {
        std::cout << "Error, could not load barrel_vertical.png" << std::endl;
    }
    if (!resources->m_barrels[2].loadFromFile("resources/images/blue_barrel.png"))
    {
        std::cout << "Error, could not load blue_barrel.png" << std::endl;
    }

    // Donkey Kong
    if (!resources->m_dk_img[0].loadFromFile("resources/images/dk_pause_tense.png"))
    {
        std::cout << "Error, could not load dk_pause_tense.png" << std::endl;
    }
    if (!resources->m_dk_img[1].loadFromFile("resources/images/dk_pause_tense_smiling.png"))
    {
        std::cout << "Error, could not load dk_pause_tense_smiling.png" << std::endl;
    }
    if (!resources->m_dk_img[2].loadFromFile("resources/images/dk_excited.png"))
    {
        std::cout << "Error, could not load dk_excited.png" << std::endl;
    }
    if (!resources->m_dk_img[3].loadFromFile("resources/images/dk_prepare_to_throw.png"))
    {
        std::cout << "Error, could not load dk_prepare_to_throw.png" << std::endl;
    }
    if (!resources->m_dk_img[4].loadFromFile("resources/images/dk_throwing_barrel.png"))
    {
        std::cout << "Error, could not load dk_throwing_barrel.png" << std::endl;
    }

    // Flames
    if (!resources->m_flames_img[0].loadFromFile("resources/images/flame1.png"))
    {
        std::cout << "Error, could not load flame1.png" << std::endl;
    }
    if (!resources->m_flames_img[1].loadFromFile("resources/images/flame2.png"))
    {
        std::cout << "Error, could not load flame2.png" << std::endl;
    }

    // Peach
    if (!resources->m_peach_img[0].loadFromFile("resources/images/peach1.png"))
    {
        std::cout << "Error, could not load peach1.png" << std::endl;
    }
    if (!resources->m_peach_img[1].loadFromFile("resources/images/peach2.png"))
    {
        std::cout << "Error, could not load peach2.png" << std::endl;
    }

    if (!resources->m_music[0].openFromFile("resources/songs/main.ogg")) {
        std::cout << "Error, could not load main.ogg" << std::endl;
    }

    resources->m_walls[0].setRepeated(true);
    resources->m_ladders[0].setRepeated(true);
}
