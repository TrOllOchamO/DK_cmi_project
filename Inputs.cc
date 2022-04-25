#include "Inputs.hpp"

void Inputs::update(sf::RenderWindow &m_window)
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        // close the window if the cross is clicked
        if (event.type == sf::Event::Closed)
        {
            m_window.close();
        }

        switch (event.type)
        {
        // appuis touche
        case sf::Event::KeyPressed:
            switch (event.key.code)
            {
            case sf::Keyboard::Left:
                leftKeyPressed = true;
                break;
            case sf::Keyboard::Right:
                rightKeyPressed = true;
                break;
            case sf::Keyboard::Up:
                upKeyPressed = true;
            default:
                break;
            }
            break;

        // relachement touche
        case sf::Event::KeyReleased:
            switch (event.key.code)
            {
            case sf::Keyboard::Left:
                leftKeyPressed = false;
                break;
            case sf::Keyboard::Right:
                rightKeyPressed = false;
                break;
            case sf::Keyboard::Up:
                upKeyPressed = false;
            default:
                break;
            }
            break;

        default:
            break;
        }
    }
}