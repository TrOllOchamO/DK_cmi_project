#include "Resources.hpp"

void Resources::load_resources1()
{
    if (!m_fonts[0].loadFromFile("resources/fonts/arial.ttf"))
    {
        std::cout << "Error, could not load arial.ttf" << std::endl;
    }
    if (!m_walls[0].loadFromFile("resources/images/mur1.jpg"))
    {
        std::cout << "Error, could not load mur1.jpg" << std::endl;
    }
    if (!m_marios_life.loadFromFile("resources/images/mur1.jpg"))
    {
        std::cout << "Error, could not load mur1.jpg" << std::endl;
    }
    if (!m_mario_img[0].loadFromFile("resources/images/mario_stopped.png"))
    {
        std::cout << "Error, could not load mario_stopped.png" << std::endl;
    }
    if (!m_mario_img[1].loadFromFile("resources/images/mario_running1.png"))
    {
        std::cout << "Error, could not load mario_running1.png" << std::endl;
    }
    if (!m_mario_img[2].loadFromFile("resources/images/mario_running2.png"))
    {
        std::cout << "Error, could not load mario_running2.png" << std::endl;
    }
    if (!m_mario_img[3].loadFromFile("resources/images/mario_jumping.png"))
    {
        std::cout << "Error, could not load mario_jumping.png" << std::endl;
    }

    m_walls[0].setRepeated(true);
}