#include "Resources.hpp"

void Resources::load_resources1(Resources *resources)
{
    if (!resources->m_fonts[0].loadFromFile("resources/fonts/arial.ttf"))
    {
        std::cout << "Error, could not load arial.ttf" << std::endl;
    }
    if (!resources->m_walls[0].loadFromFile("resources/images/mur1.jpg"))
    {
        std::cout << "Error, could not load mur1.jpg" << std::endl;
    }
    if (!resources->m_players_life.loadFromFile("resources/images/marios_life.png"))
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
   resources->m_walls[0].setRepeated(true);
}
