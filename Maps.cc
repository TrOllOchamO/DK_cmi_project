#include "Maps.h"

void Maps::set_map1 (Game &game)
{
    // Size of the window : 960 (x), 540 (y)
    const int MARIO_WIDTH = 20;
    const int MARIO_HEIGHT = 45;
    const int PLATFORM_HEIGHT = 20;
    const int WINDOW_WIDTH = game.get_windowHeight();
    const int WINDOW_HEIGHT = game.get_windowHeight();

    Rectangle mario(3, 960 - PLATFORM_HEIGHT - MARIO_HEIGHT, MARIO_WIDTH, MARIO_HEIGHT, 0, true, 4, 5);
    game.add_element_to_background(&mario);

    /* Circle circle(10, 10, 5);
    game.add_element_to_background(&circle); */

    Rectangle RDC(0, WINDOW_WIDTH - PLATFORM_HEIGHT, WINDOW_WIDTH, PLATFORM_HEIGHT, -0.5);
    game.add_element_to_background(&RDC);

    for (int i = 0; i < 4; i++)
    {
        if (i % 2 == 0)
        {
            Rectangle first_stage(MARIO_WIDTH * 3, WINDOW_WIDTH - PLATFORM_HEIGHT - MARIO_HEIGHT * (4 + i * 2), WINDOW_WIDTH, PLATFORM_HEIGHT, 1.5);
            game.add_element_to_background(&first_stage);
        }
        else
        {
            Rectangle stage(0, WINDOW_WIDTH - PLATFORM_HEIGHT - MARIO_HEIGHT * (1 + 2 * i), WINDOW_WIDTH - MARIO_WIDTH, PLATFORM_HEIGHT, 1.5);
            game.add_element_to_background(&stage);
        }
    }
}
