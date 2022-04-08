#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Element.h"

class Circle : public Element
{
public:
    Circle(float x, float y, int radius, int rotation = 0, bool hasGravity = false, float velocityOnX = 0, float velocityOnY = 0, sf::Color color = sf::Color::Black);
    ~Circle();

    void draw(sf::RenderWindow &window);
    Vector2D get_center() const;
    Vector2D get_futhest_point(const Vector2D &direction) const;

private:
    int m_radius;
};