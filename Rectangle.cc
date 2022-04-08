#include "Rectangle.h"

Rectangle::Rectangle(float x, float y, int width, int height, int rotation, bool hasGravity, float velocityOnX, float velocityOnY, sf::Color color) : 
Element(x, y, rotation, hasGravity, velocityOnX, velocityOnY, color), m_width(width), m_height(height)
{

}

Rectangle::~Rectangle()
{
    
}

void Rectangle::draw(sf::RenderWindow &window)
{
    sf::RectangleShape rectangle(sf::Vector2f(m_width, m_height));
    rectangle.setFillColor(m_color);
    rectangle.setPosition(m_x, m_y);
    rectangle.rotate(m_rotation);
    window.draw(rectangle);
}

Vector2D Rectangle::get_center() const
{
    Vector2D center = { m_x + m_width/2, m_y + m_height/2 };
    return center;
}

Vector2D Rectangle::get_futhest_point(const Vector2D &direction) const
{
    Vector2D futhest = {m_x, m_y}; // initialize the futhest point with the coordinates of a random corner
    float bestScore = Math::dot(direction, futhest); // calculate the score of this point

    // create an array for every point we still need compare
    const float right = m_x + m_width;
    const float bottom = m_y + m_height;
    Vector2D corners[3] = {{right, m_y}, {m_x, bottom}, {right, bottom}};

    // search for a point with a superior score
    for (int i = 0; i < 3; ++i)
    {
        const float newScore = Math::dot(direction, corners[i]);
        if (newScore > bestScore)
        {
            bestScore = newScore;
            futhest = corners[i];
        }
    }

    return futhest;
}