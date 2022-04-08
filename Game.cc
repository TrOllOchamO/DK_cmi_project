#include "Game.hpp"

Game::Game() : m_windowWidth(960), m_windowHeight(540), 
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

    // switch(event.type) 
    //   {
    //     // appuis touche
    //     case Event::KeyPressed:
    //       switch(event.key.code) 
    //       {
    //         case Keyboard::Left:
    //           userInput.leftKeyPressed = true;
    //           break;
    //         default:
    //           break;
    //       }
    //       break;
        
    //     // relachement touche
    //     case Event::KeyReleased:
    //       switch(event.key.code) 
    //       {
    //         case Keyboard::Left:
    //           userInput.leftKeyPressed = false;
    //           break;
    //         default:
    //           break;
    //       }
    //       break;

    //     // appuis bouton souris
    //     case Event::MouseButtonPressed:
    //       switch(event.mouseButton.button) 
    //       {
    //         case Mouse::Button::Left: {
    //           if (is_point_in_rectangle(redRec, event.mouseButton.x, event.mouseButton.y)) {update_rect_color(redRec);}
    //           break;
    //         }
    //         default:
    //           break;
    //       }
    //       break;

    //     default:
    //       break;
    //   }
    // }
  }
}

void Game::update(float dt)
{
  /* switch (game_state) {
    case GAME_PAUSED,
    GAME_MENU,
    GAME_START
  } */
}

void Game::render()
{
    m_window.clear(sf::Color::Black);
    
    for (int i = 0; i < m_backGroundElements.size(); ++i)
    {
      m_backGroundElements[i]->draw(m_window);
    }

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

// setters
