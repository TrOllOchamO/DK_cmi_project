#pragma once

#include <list>
#include <vector>

#include "Element.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Physics.hpp"
#include "Player.hpp"
#include "Text.hpp"
#include "Resources.hpp"

enum GameState
{
    GAME_PAUSED,
    GAME_MENU,
    GAME_START
};

struct UserInputs
{
    bool leftKeyPressed = false;
    bool rightKeyPressed = false;
    bool upKeyPressed = false;
};

class Game
{
public:
    Game();
    ~Game();

    void handle_events();
    void update(float dt);
    void render();
    void animation(bool facing);

    void add_element_to_background(Element *element);

    bool is_open() const;

    // Getters
    int get_windowWidth() const;
    int get_windowHeight() const;
    sf::Font get_fonts() const;
    UserInputs get_user_inputs() const;
    Resources* get_resources() const;

    // Setter
    void set_mario(Player *mario);

private:
    GameState game_state;
    int m_windowWidth;
    int m_windowHeight;
    int m_animation = 0;
    UserInputs m_inputs;

    std::vector<Element*> m_backGroundElements;
    std::list<Element*> m_movingElements;
    Player *m_mario;

    sf::RenderWindow m_window;

    sf::Clock sprites;

    Resources *m_resources;
};