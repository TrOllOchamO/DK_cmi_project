#include "Game.hpp"

Game::Game() : m_windowWidth(1000), m_windowHeight(800), m_mario(nullptr),
m_window(sf::VideoMode(m_windowWidth, m_windowHeight), L"Donkey Kong Arcade Incroyable")//, m_resources(new Resources())
{
    m_resources = new Resources();
    m_window.setFramerateLimit(60);
}

Game::~Game()
{
    // delete every elements
    for (Element* element : m_backGroundElements) { delete element; }
    for (Element* element : m_movingElements) { delete element; }
    delete m_mario;
    delete m_resources;

    // empty the list/vector of elements
    m_backGroundElements.clear();
    m_movingElements.clear();
}

void Game::update(float dt)
{
    Physics::apply_gravity(m_mario, dt, 700);
    m_userInputs.update(m_window);
    bool marioTryToMove(m_mario->update_player(m_userInputs, dt));
    m_mario->update_position(dt);
    
    Vector2D direction;
    for (int i = 0; i < m_backGroundElements.size(); ++i)
    {
        const float distance = Physics::EPA(m_mario, m_backGroundElements[i], direction);
        if (distance < 0) // if there is collision
        {
            m_backGroundElements[i]->set_color(sf::Color::Red);
            if (marioTryToMove) { m_mario->move_in_a_direction(direction, distance); }
            else { Physics::set_position_before_colision(m_mario, m_backGroundElements[i], dt); }
            // Physics::solve_velocity(m_mario, m_backGroundElements[i], direction, distance);
        }
        else
        {
            m_backGroundElements[i]->set_color(sf::Color::White);
        }
    }
}

void Game::render()
{
    m_window.clear(sf::Color::Black);
  
    // draw every elements of the game
    m_mario->draw(m_window);
    for (Element* element : m_backGroundElements) { element->draw(m_window); }
    for (Element* element : m_movingElements) { element->draw(m_window); }

  m_window.display();
}

void Game::add_element_to_background(Element *element)
{
    m_backGroundElements.push_back(element);
}

void Game::add_moving_element(Element *element) {
    m_movingElements.push_back(element);
}

void Game::set_elements_resources()
{
    m_mario->set_resources_pointer(m_resources);
    for (Element* element : m_backGroundElements) { element->set_resources_pointer(m_resources); }
    for (Element* element : m_movingElements) { element->set_resources_pointer(m_resources); }
}

// getters
int Game::get_windowWidth() const { return m_windowWidth; }
int Game::get_windowHeight() const { return m_windowHeight; }
bool Game::is_open() const { return m_window.isOpen(); }
Resources* Game::get_resources_pointer() const { return m_resources; }

// setters
void Game::set_mario(Player *mario) { m_mario = mario; }
