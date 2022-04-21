#include "Circle.hpp"

Circle::Circle(float x, float y, int radius, float rotation, bool hasGravity, float velocityOnX, float velocityOnY, sf::Color color, sf::Texture texture) : 
Element(x, y, rotation, hasGravity, velocityOnX, velocityOnY, color, texture), m_radius(radius)
{
}

Circle::~Circle()
{
}

void Circle::draw(sf::RenderWindow &window)
{
    sf::CircleShape circle(m_radius);
    circle.setFillColor(m_color);
    circle.setPosition(m_x, m_y);
    circle.rotate(m_rotation);
    circle.setTexture(&m_texture);
    window.draw(circle);
}

Vector2D Circle::get_center() const
{
    const Vector2D center = {m_x + m_radius, m_y + m_radius};
    return center;
}

Vector2D Circle::get_futhest_point(const Vector2D &direction) const
{
    const Vector2D center = get_center();
    const Vector2D futhest = center + direction*m_radius; // the distance vector MUST be normalised
    return futhest;
}