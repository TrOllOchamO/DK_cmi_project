#include "Maps.hpp"

void Maps::set_map1(Game &game)
{
    const int WINDOW_WIDTH = game.get_windowWidth();
    const int WINDOW_HEIGHT = game.get_windowHeight();
    const int PLATFORM_HEIGHT = WINDOW_HEIGHT / 30;
    const int MARIO_SIZE = WINDOW_HEIGHT / 14;
    sf::Font font = game.get_font();

    Player *mario = new Player(3, WINDOW_HEIGHT - PLATFORM_HEIGHT - MARIO_SIZE, MARIO_SIZE, MARIO_SIZE, 0, true);
    game.set_mario(mario);

    Circle *circle = new Circle(10, 10, 7);
    game.add_element_to_background(circle);

    Rectangle *RDC = new Rectangle(0, WINDOW_HEIGHT - PLATFORM_HEIGHT, WINDOW_WIDTH, PLATFORM_HEIGHT, 0, false, 0, 0, sf::Color::White, game.get_texture_mur());
    game.add_element_to_background(RDC);

    //  Text(std::string text, int size, sf::Font font, float x, float y, int width, int height, float rotation = 0, bool hasGravity = false, float velocityOnX = 0, float velocityOnY = 0, sf::Color color = sf::Color::White);
    //  Circle(float x, float y, int radius, float rotation = 0, bool hasGravity = false, float velocityOnX = 0, float velocityOnY = 0, sf::Color color = sf::Color::White);
    //  Rectangle(float x, float y, int width, int height, float rotation = 0, bool hasGravity = false, float velocityOnX = 0, float velocityOnY = 0, sf::Color color = sf::Color::White);

    for (int i = 0; i < 4; i++)
    {
        if (i % 2 == 0)
        {
            Rectangle *first_stage = new Rectangle(MARIO_SIZE * 3, WINDOW_HEIGHT - PLATFORM_HEIGHT - MARIO_SIZE * (3.5 + i * 2), WINDOW_WIDTH, PLATFORM_HEIGHT, -1.5, false, 0, 0, sf::Color::White, game.get_texture_mur());
            game.add_element_to_background(first_stage);
        }
        else
        {
            Rectangle *stage = new Rectangle(0, WINDOW_HEIGHT - PLATFORM_HEIGHT - MARIO_SIZE * (2 * i), WINDOW_WIDTH - MARIO_SIZE * 3, PLATFORM_HEIGHT, 1.5, false, 0, 0, sf::Color::White, game.get_texture_mur());
            game.add_element_to_background(stage);
        }
    }

    Rectangle *point_to_reach = new Rectangle(WINDOW_WIDTH / 2 - WINDOW_WIDTH / 16, WINDOW_HEIGHT - PLATFORM_HEIGHT - MARIO_SIZE * 10, WINDOW_WIDTH / 8, PLATFORM_HEIGHT, 0, false, 0, 0, sf::Color::White, game.get_texture_mur());
    game.add_element_to_background(point_to_reach);
}
