#include "Maps.hpp"

void Maps::set_map1(Game &game)
{
    const int WINDOW_WIDTH = game.get_windowWidth();
    const int WINDOW_HEIGHT = game.get_windowHeight();
    const int PLATFORM_HEIGHT = WINDOW_HEIGHT/30;
    const int MARIO_SIZE = WINDOW_HEIGHT/14;

    // Start by loading the textures into the game
    Resources *gameResources = game.get_resources_pointer();
    Resources::load_resources1(gameResources);

    // Creating mario
    const float MARIO_OFFSET = -300; // preventing mario to spawn inside the floor
    const float MARIO_Y = WINDOW_HEIGHT - PLATFORM_HEIGHT - MARIO_SIZE + MARIO_OFFSET;
    Player *mario = new Player(3, MARIO_Y, MARIO_SIZE, MARIO_SIZE, 0, true);
    game.set_mario(mario);

    // Creating the platform where mario stand at the beginning

    const float ADJUSTMENT = WINDOW_HEIGHT - PLATFORM_HEIGHT; // Adjust the map with the height of the platform,
    // The window height is used here because we create the maps from the bottom

    Rectangle *firstFloor = new Rectangle(0, ADJUSTMENT, WINDOW_WIDTH, PLATFORM_HEIGHT, 0, false, 0, 0, true, gameResources->m_walls[0]);
    game.add_element_to_background(firstFloor);

    // Create the top flat platform
    Rectangle *point_to_reach = new Rectangle(WINDOW_WIDTH/2 - WINDOW_WIDTH/16, ADJUSTMENT - MARIO_SIZE*10, WINDOW_WIDTH/8, PLATFORM_HEIGHT, 0, false, 0, 0, true, gameResources->m_walls[0]);
    game.add_element_to_background(point_to_reach);

    // Create every inclined platforms
    for (int i = 0; i < 4; i++)
    {
        if (i % 2 == 0)
        {
            Rectangle *first_stage = new Rectangle(MARIO_SIZE*3, ADJUSTMENT - MARIO_SIZE*(3.5 + i*2), WINDOW_WIDTH, PLATFORM_HEIGHT, -1.5, false, 0, 0, true, gameResources->m_walls[0]);
            game.add_element_to_background(first_stage);
        }
        else
        {
            Rectangle *stage = new Rectangle(0, ADJUSTMENT - MARIO_SIZE*(2*i), WINDOW_WIDTH - MARIO_SIZE*3, PLATFORM_HEIGHT, 1.5, false, 0, 0, true, gameResources->m_walls[0]);
            game.add_element_to_background(stage);
        }
    }

    // Create stairs
    Rectangle *point_to_reac = new Rectangle(WINDOW_WIDTH / 2 - WINDOW_WIDTH / 16, ADJUSTMENT - MARIO_SIZE * 10, WINDOW_WIDTH / 8, PLATFORM_HEIGHT, 0, false, 0, 0, true, gameResources->m_ladders[0]);
    game.add_element_to_background(point_to_reac);
    for (int i = 0; i < 8; i++) {
        Circle *circle = new Circle(10, 10, 10, 0, true, 250, 0, true, sf::Color::White);
    }
    ScoreBoard *score = new ScoreBoard(0, 0, WINDOW_WIDTH, 200, gameResources->m_fonts, mario);
    game.add_element_to_background(score);

    // Set the new resources for every elements in the game
    game.set_elements_resources();
}

void Maps::set_map2(Game &game)
{
    const int WINDOW_WIDTH = game.get_windowWidth();
    const int WINDOW_HEIGHT = game.get_windowHeight();
    const int PLATFORM_HEIGHT = 20;
    const int LADDER_WIDTH = 21;
    sf::Texture texture = sf::Texture(); // Create this texture for dynamic images (it converts images into textures.)

    // Start by loading the textures into the game
    Resources *gameResources = game.get_resources_pointer();
    Resources::load_resources1(gameResources);

    // Creating mario
    Player *mario = new Player(76, 737, 29, 41, 0, true);
    game.set_mario(mario);

    // Creating walls
    Rectangle *firstFloor = new Rectangle(0, WINDOW_HEIGHT - PLATFORM_HEIGHT, WINDOW_WIDTH, PLATFORM_HEIGHT, 0, false, 0, 0, true, gameResources->m_walls[0], HORIZONTALY);
    game.add_element_to_background(firstFloor);

    Rectangle *plat_1 = new Rectangle(0, 658, 560, PLATFORM_HEIGHT, 4.29, false, 0, 0, true, gameResources->m_walls[0], HORIZONTALY);
    game.add_element_to_background(plat_1);

    Rectangle *plat_2 = new Rectangle(71, 544.8 + 65.7 - PLATFORM_HEIGHT, 569, PLATFORM_HEIGHT, -3.95, false, 0, 0, true, gameResources->m_walls[0], HORIZONTALY);
    game.add_element_to_background(plat_2);

    Rectangle *plat_3 = new Rectangle(0, 428.8, 573, PLATFORM_HEIGHT, 4.17, false, 0, 0, true, gameResources->m_walls[0], HORIZONTALY);
    game.add_element_to_background(plat_3);

    Rectangle *plat_4 = new Rectangle(64.8, 328.8 + 64.8 - PLATFORM_HEIGHT, 575, PLATFORM_HEIGHT, -4.47, false, 0, 0, true, gameResources->m_walls[0], HORIZONTALY);
    game.add_element_to_background(plat_4);

    Rectangle *plat_5 = new Rectangle(0, 223, 317, PLATFORM_HEIGHT, 0, false, 0, 0, true, gameResources->m_walls[0], HORIZONTALY);
    game.add_element_to_background(plat_5);

    Rectangle *plat_6 = new Rectangle(316, 223, 243, PLATFORM_HEIGHT, 10.18, false, 0, 0, true, gameResources->m_walls[0], HORIZONTALY);
    game.add_element_to_background(plat_6);

    Rectangle *final = new Rectangle(168, 126.4, 134, PLATFORM_HEIGHT, 0, false, 0, 0, true, gameResources->m_walls[0], HORIZONTALY);
    game.add_element_to_background(final);

    // Creating barrels
    Rectangle *blue_barrel = new Rectangle(12, 739.2, 40, 40, 0, false, 0, 0, true, gameResources->m_barrels[2]);
    game.add_element_to_background(blue_barrel);

    Rectangle *vertical_barrel1 = new Rectangle(0, 175.2, 19, 19, 0, false, 0, 0, true, gameResources->m_barrels[1]);
    game.add_element_to_background(vertical_barrel1);

    Rectangle *vertical_barrel2 = new Rectangle(0, 125.6, 19, 19, 0, false, 0, 0, true, gameResources->m_barrels[1]);
    game.add_element_to_background(vertical_barrel2);

    Rectangle *vertical_barrel3 = new Rectangle(21.6, 175.2, 19, 19, 0, false, 0, 0, true, gameResources->m_barrels[1]);
    game.add_element_to_background(vertical_barrel3);

    Rectangle *vertical_barrel4 = new Rectangle(21.6, 125.6, 19, 19, 0, false, 0, 0, true, gameResources->m_barrels[1]);
    game.add_element_to_background(vertical_barrel4);

    // Creating ladders
    Rectangle *ladders1 = new Rectangle(501, 697.6, LADDER_WIDTH, 82, 0, false, 0, 0, false, gameResources->m_ladders[0], VERTICALY);
    game.add_element_to_background(ladders1);

    Rectangle *ladders2 = new Rectangle(152.8, 670.4, LADDER_WIDTH, 31, 0, false, 0, 0, false, gameResources->m_ladders[0], VERTICALY);
    game.add_element_to_background(ladders2);

    Rectangle *ladders3 = new Rectangle(120, 584, LADDER_WIDTH, 85, 0, false, 0, 0, false, gameResources->m_ladders[0], VERTICALY);
    game.add_element_to_background(ladders3);

    Rectangle *ladders4 = new Rectangle(484.8, 465.6, LADDER_WIDTH, 91, 0, false, 0, 0, false, gameResources->m_ladders[0], VERTICALY);
    game.add_element_to_background(ladders4);

    Rectangle *ladders5 = new Rectangle(352.8, 348.8, LADDER_WIDTH, 109, 0, false, 0, 0, false, gameResources->m_ladders[0], VERTICALY);
    game.add_element_to_background(ladders5);

    Rectangle *ladders6 = new Rectangle(113.6, 367.2, LADDER_WIDTH, 72, 0, false, 0, 0, false, gameResources->m_ladders[0], VERTICALY);
    game.add_element_to_background(ladders6);

    Rectangle *ladders7 = new Rectangle(321.6, 226.4, LADDER_WIDTH, 126, 0, false, 0, 0, false, gameResources->m_ladders[0], VERTICALY);
    game.add_element_to_background(ladders7);

    Rectangle *ladders8 = new Rectangle(460, 252.8, LADDER_WIDTH, 91, 0, false, 0, 0, false, gameResources->m_ladders[0], VERTICALY);
    game.add_element_to_background(ladders8);

    Rectangle *ladders9 = new Rectangle(281.6, 126.4, LADDER_WIDTH, 100, 0, false, 0, 0, false, gameResources->m_ladders[0], VERTICALY);
    game.add_element_to_background(ladders9);

    Rectangle *ladders10 = new Rectangle(168, 126.4, LADDER_WIDTH, 100, 0, false, 0, 0, false, gameResources->m_ladders[0], VERTICALY);
    game.add_element_to_background(ladders10);


    // Creating DK
    texture.loadFromImage(gameResources->m_dk_img[0]);
    Rectangle *DK = new Rectangle(50.4, 162.4, 82, 61, 0, false, 0, 0, true, texture);
    game.add_moving_element(DK);

    // Creating peach
    texture.loadFromImage(gameResources->m_peach_img[0]);
    Rectangle *peach = new Rectangle(216, 86.4, 29, 40, 0, false, 0, 0, true, texture);
    game.add_moving_element(peach);

    // Creating flames
    texture.loadFromImage(gameResources->m_flames_img[0]);
    Rectangle *flame = new Rectangle(12, 700.8, 40, 38, 0, false, 0, 0, true, texture); // Texture à changer
    game.add_moving_element(flame);

    // Creating the ScoreBoard
    ScoreBoard *score = new ScoreBoard(0, 0, WINDOW_WIDTH, 200, gameResources->m_fonts, mario);
    game.add_element_to_background(score);

    gameResources->m_music[0].play();
    gameResources->m_music[0].setLoop(true);

    // Set the new resources for every elements in the game
    game.set_elements_resources();
}
