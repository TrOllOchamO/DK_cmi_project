#pragma once

#include<SFML/Graphics.hpp>

#include "Element.h"

class Rectangle : public Element 
{
public:
    Rectangle(float x, float y, int width, int height, int rotation = 0, bool hasGravity = false, float velocityOnX = 0, float velocityOnY = 0, sf::Color color = sf::Color::Black);
    ~Rectangle();
    
    void draw(sf::RenderWindow &window);
    Vector2D get_center() const;
    Vector2D get_futhest_point(const Vector2D &direction) const;

private:
    int m_width;
    int m_height;
    int m_rotation;
    sf::Color m_color;
};