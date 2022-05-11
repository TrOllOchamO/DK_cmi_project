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
#include "Inputs.hpp"

enum GameState
{
    GAME_PAUSED,
    GAME_MENU,
    GAME_START
};

class Game
{
public:
    Game();
    ~Game();

    void update(float dt); // update every elements of the game by aplying physics on them
    void render(); // render a frame of the game

    void add_element_to_background(Element *element);
    void add_moving_element(Element *element);
    void set_elements_resources(); // set the resources pointer to every elements of the game

    // Getters
    bool is_open() const;
    int get_windowWidth() const;
    int get_windowHeight() const;
    Resources* get_resources_pointer() const;

    // Setter
    void set_mario(Player *mario);

private:
    GameState game_state;
    int m_windowWidth;
    int m_windowHeight;
    Inputs m_userInputs;

    std::vector<Element*> m_backGroundElements;
    std::list<Element*> m_movingElements;
    Player *m_mario;

    sf::RenderWindow m_window;

    sf::Clock sprites;

    Resources *m_resources;
};
