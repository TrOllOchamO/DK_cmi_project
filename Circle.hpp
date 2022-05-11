#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Element.hpp"

class Circle : public Element
{
public:
    Circle(float x, float y, int radius, float rotation = 0, bool hasGravity = false, float velocityOnX = 0, float velocityOnY = 0, sf::Color color = sf::Color::White, sf::Texture texture = sf::Texture());
    Circle(float x, float y, int radius, float rotation = 0, bool hasGravity = false, float velocityOnX = 0, float velocityOnY = 0, sf::Texture texture = sf::Texture());
    ~Circle();

    void draw(sf::RenderWindow &window);
    Vector2D get_center() const;
    Vector2D get_futhest_point(const Vector2D &direction) const;

private:
    int m_radius;
};