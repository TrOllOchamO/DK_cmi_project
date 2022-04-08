#pragma once

#include <list>
#include <vector>

#include "Element.h"
#include "Circle.h"


class Game
{
public:
    Game();
    ~Game();

    bool is_open();
    bool poll_event(sf::Event &event);
    void update(float dt);
    void render();
    void treat_event(sf::Event &event);

    void add_element_to_background(Element *element);

    bool is_open();
    int get_windowWidth() const;
    int get_windowHeight() const;

private:
    void load_resources();

    int m_windowWidth;
    int m_windowHeight;
    UserInputs inputs;

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

struct UserInputs
{
    bool hasPressedLeft = false;
};