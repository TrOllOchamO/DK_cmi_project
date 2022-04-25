#include "Maps.hpp"

void Maps::set_map1(Game &game)
{
    const int WINDOW_WIDTH = game.get_windowWidth();
    const int WINDOW_HEIGHT = game.get_windowHeight();
    const int PLATFORM_HEIGHT = WINDOW_HEIGHT/30;
    const int MARIO_SIZE = WINDOW_HEIGHT/14;

    // start by loading the textures into the game
    Resources *gameResources = game.get_resources_pointer();
    Resources::load_resources1(gameResources);

    // creating mario
    const float MARIO_Y = WINDOW_HEIGHT - PLATFORM_HEIGHT - MARIO_SIZE;
    Player *mario = new Player(3, MARIO_Y, MARIO_SIZE, MARIO_SIZE, 0, true);
    game.set_mario(mario);

    // creating the platform where mario stand at the begining
    Rectangle *firstFloor = new Rectangle(0, WINDOW_HEIGHT - PLATFORM_HEIGHT, WINDOW_WIDTH, PLATFORM_HEIGHT, 0, false, 0, 0, sf::Color::White, gameResources->m_walls[0]);
    game.add_element_to_background(firstFloor);

    // create the top flat platform
    Rectangle *point_to_reach = new Rectangle(WINDOW_WIDTH/2 - WINDOW_WIDTH/16, WINDOW_HEIGHT - PLATFORM_HEIGHT - MARIO_SIZE*10, WINDOW_WIDTH/8, PLATFORM_HEIGHT, 0, false, 0, 0, sf::Color::White, gameResources->m_walls[0]);
    game.add_element_to_background(point_to_reach);

    // create every inclined platforms
    for (int i = 0; i < 4; i++)
    {
        if (i % 2 == 0)
        {
            Rectangle *first_stage = new Rectangle(MARIO_SIZE*3, WINDOW_HEIGHT - PLATFORM_HEIGHT - MARIO_SIZE*(3.5 + i*2), WINDOW_WIDTH, PLATFORM_HEIGHT, -1.5, false, 0, 0, sf::Color::White, gameResources->m_walls[0]);
            game.add_element_to_background(first_stage);
        }
        else
        {
            Rectangle *stage = new Rectangle(0, WINDOW_HEIGHT - PLATFORM_HEIGHT - MARIO_SIZE*(2*i), WINDOW_WIDTH - MARIO_SIZE*3, PLATFORM_HEIGHT, 1.5, false, 0, 0, sf::Color::White, gameResources->m_walls[0]);
            game.add_element_to_background(stage);
        }
    }
    // set the new resources for every elements in the game
    game.set_elements_resources();
}