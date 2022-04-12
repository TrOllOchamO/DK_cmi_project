#pragma once

#include <list>
#include <vector>

#include "Element.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Physics.hpp"
#include "Player.hpp"

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

    void add_element_to_background(Element *element);

    bool is_open() const;

    // Getters
    int get_windowWidth() const;
    int get_windowHeight() const;
    sf::Font get_font() const;
    UserInputs get_user_inputs() const;

    // Setter
    void set_mario(const Player *mario);
    void set_text_score(const sf::Text &text);

private:
    void load_resources();

    GameState game_state;
    int m_windowWidth;
    int m_windowHeight;
    Player m_mario;
    UserInputs m_inputs;

    std::vector<Element*> m_backGroundElements;
    std::list<Element*> m_movingElements;

    // the window and resources
    sf::RenderWindow m_window;

    //Murs
    sf::Image m_murs[2];

    //Fonts
    sf::Font m_font;
    sf::Text m_text_score;
};