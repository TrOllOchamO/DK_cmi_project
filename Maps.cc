#include "Maps.hpp"

void Maps::set_map1(Game &game)
{
    // Size of the window : 960 (x), 540 (y)
    const int MARIO_WIDTH = 20;
    const int MARIO_HEIGHT = 45;
    const int PLATFORM_HEIGHT = 20;
    const int WINDOW_WIDTH = game.get_windowWidth();
    const int WINDOW_HEIGHT = game.get_windowHeight();

    Rectangle *mario = new Rectangle(3, WINDOW_HEIGHT - PLATFORM_HEIGHT - MARIO_HEIGHT, MARIO_WIDTH, MARIO_HEIGHT, 0, true, 4, 5);
    game.add_element_to_background(mario);

    Circle *circle = new Circle(10, 10, 5);
    game.add_element_to_background(circle);

    Rectangle *RDC = new Rectangle(0, WINDOW_HEIGHT - PLATFORM_HEIGHT, WINDOW_WIDTH, PLATFORM_HEIGHT, -0.5);
    game.add_element_to_background(RDC);
    //Circle(float x, float y, int radius, float rotation = 0, bool hasGravity = false, float velocityOnX = 0, float velocityOnY = 0, sf::Color color = sf::Color::White);
    // Rectangle(float x, float y, int width, int height, float rotation = 0, bool hasGravity = false, float velocityOnX = 0, float velocityOnY = 0, sf::Color color = sf::Color::White);

    for (int i = 0; i < 4; i++)
    {
        if (i % 2 == 0)
        {
            Rectangle *first_stage = new Rectangle(MARIO_WIDTH * 3, WINDOW_HEIGHT - PLATFORM_HEIGHT - MARIO_HEIGHT * (4 + i * 2), WINDOW_WIDTH, PLATFORM_HEIGHT, -1.5);
            game.add_element_to_background(first_stage);
        }
        else
        {
            Rectangle *stage = new Rectangle(0, WINDOW_HEIGHT - PLATFORM_HEIGHT - MARIO_HEIGHT * (1 + 2 * i), WINDOW_WIDTH - MARIO_WIDTH, PLATFORM_HEIGHT, 1.5);
            game.add_element_to_background(stage);
        }
    }
}
