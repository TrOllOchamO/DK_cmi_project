#include "Game.hpp"

Game::Game() : m_windowWidth(960), m_windowHeight(540), m_mario(nullptr),
m_window(sf::VideoMode(m_windowWidth, m_windowHeight), L"Donkey Kong Arcade Incroyable")
{
  load_resources();
}

Game::~Game()
{
  for (int i = 0; i < m_backGroundElements.size(); ++i)
  {
    delete m_backGroundElements[i];
  }

  delete m_mario;
}

void Game::load_resources()
{
    m_font.loadFromFile("resources/fonts/arial.ttf");
    if (!m_murs[0].loadFromFile("resources/images/mur1.jpg"))
    {
      std::cout << "Error, could not load mur1.jpg" << std::endl;
    }
    if (!m_murs[1].loadFromFile("resources/images/mur2.jpg"))
    {
      std::cout << "Error, could not load mur2.jpg" << std::endl;
    }
}

void Game::handle_events() 
{
  sf::Event event;
  while (m_window.pollEvent(event)) 
  {
    // close the window if the cross is clicked
    if (event.type == sf::Event::Closed) { m_window.close(); }

    switch(event.type) 
    {
      // appuis touche
      case sf::Event::KeyPressed:
        switch(event.key.code) 
        {
          case sf::Keyboard::Left:
            m_inputs.leftKeyPressed = true;
            break;
          case sf::Keyboard::Right:
            m_inputs.rightKeyPressed = true;
            break;
          case sf::Keyboard::Up:
            m_inputs.upKeyPressed = true;
          default:
            break;
        }
        break;
      
      // relachement touche
      case sf::Event::KeyReleased:
        switch(event.key.code) 
        {
          case sf::Keyboard::Left:
            m_inputs.leftKeyPressed = false;
            break;
          case sf::Keyboard::Right:
            m_inputs.rightKeyPressed = false;
          case sf::Keyboard::Up:
            m_inputs.upKeyPressed = false;
          default:
            break;
        }
        break;

      default:
        break;
    }
  }
}

void Game::update(float dt)
{
  // Effectue ces évènements lors qu'une touche est appuyé
  if (m_inputs.leftKeyPressed) {  m_mario->set_velocity_on_x(-100); }
  else if (m_inputs.rightKeyPressed) {  m_mario->set_velocity_on_x(100); }
  else {  m_mario->set_velocity_on_x(0); }

  if (m_inputs.upKeyPressed) { m_mario->set_velocity_on_y(-100);  }
  // else { m_mario->set_velocity_on_y(0); }

  Physics::apply_gravity(m_mario, dt, 100);
  m_mario->update_position(dt);

  Vector2D direction;
  for (int i = 0; i < m_backGroundElements.size(); ++i)
  {
    const float distance = Physics::EPA(m_mario, m_backGroundElements[i], direction);
    if (distance > 0) // if there is collision
    {
      m_backGroundElements[i]->set_color(sf::Color::Red);
      m_mario->move_in_a_direction(direction, -distance);
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
  
  for (int i = 0; i < m_backGroundElements.size(); ++i)
  {
    m_backGroundElements[i]->draw(m_window);
  }

  m_mario->draw(m_window);

  m_window.display();
}

void Game::add_element_to_background(Element *element)
{
  m_backGroundElements.push_back(element);
}

// getters
int Game::get_windowWidth() const { return m_windowWidth; }
int Game::get_windowHeight() const { return m_windowHeight; }
bool Game::is_open() const { return m_window.isOpen(); }
sf::Font Game::get_font() const { return m_font; }
UserInputs Game::get_user_inputs() const { return m_inputs; }

// setters
void Game::set_mario(Player *mario) { m_mario = mario;}
void Game::set_text_score(const sf::Text &text) { m_text_score = text; }
