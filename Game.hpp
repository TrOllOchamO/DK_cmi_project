#pragma once

#include <list>
#include <vector>

#include "Element.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"

enum GameState
{
    GAME_PAUSED,
    GAME_MENU,
    GAME_START
};

struct UserInputs
{
    bool hasPressedLeft = false;
};

class Game
{
public:
    Game();
    ~Game();

    void handle_events();
    void update(float dt);
    void render();

    void add_element_to_background(Element *element);

    bool is_open() const;
    int get_windowWidth() const;
    int get_windowHeight() const;

private:
    void load_resources();

    GameState game_state;
    int m_windowWidth;
    int m_windowHeight;
    UserInputs m_inputs;

    std::vector<Element*> m_backGroundElements;
    std::list<Element*> m_movingElements;

    // the window and resouces
    sf::RenderWindow m_window;

    //Murs
    sf::Image m_murs[2];

    //Fonts
    sf::Font m_font;
    // sf::Text text;
};