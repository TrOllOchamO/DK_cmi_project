#include "Barrel.hpp"

Barrel::Barrel(float x, float y, float velocityOnX, float velocityOnY, float frequency, sf::Color color) :
Element(x, y, 0, false, velocityOnX, velocityOnY, false, sf::Texture()) 
{

}
Barrel::~Barrel() {

}

void Barrel::draw(sf::RenderWindow &window)
{
    auto size = m_texture.getSize(); // Get the size of the texture

    sf::RectangleShape rectangle(sf::Vector2f(m_width, m_height));
    rectangle.setFillColor(m_color);
    rectangle.setPosition(m_position.x, m_position.y);
    rectangle.rotate(m_rotation);
    rectangle.setTexture(&m_texture);

    if (m_facingDirection == FACING_RIGHT)
    {
        rectangle.setTextureRect(sf::IntRect(size.x, 0, -size.x, size.y));
    }
    window.draw(rectangle);
}