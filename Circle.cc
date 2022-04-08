#include "Circle.hpp"

Circle::Circle(float x, float y, int radius, float rotation, bool hasGravity, float velocityOnX, float velocityOnY, sf::Color color) : 
Element(x, y, rotation, hasGravity, velocityOnX, velocityOnY, color), m_radius(radius)
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
    window.draw(circle);
}

Vector2D Circle::get_center() const
{
    const float halfRadius = m_radius/2;
    Vector2D center = {m_x + halfRadius, m_y + halfRadius};
    return center;
}

Vector2D Circle::get_futhest_point(const Vector2D &direction) const
{
    const Vector2D center = get_center();
    const Vector2D futhest = center + direction*m_radius; // the distance vector MUST be normalised
    return futhest;
}