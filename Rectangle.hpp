#pragma once

#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "Element.hpp"

class Rectangle : public Element 
{
public:
    Rectangle(float x, float y, int width, int height, float rotation = 0, bool hasGravity = false, float velocityOnX = 0, float velocityOnY = 0, sf::Color color = sf::Color::White, sf::Texture texture = sf::Texture());
    Rectangle(float x, float y, int width, int height, float rotation = 0, bool hasGravity = false, float velocityOnX = 0, float velocityOnY = 0, sf::Texture texture = sf::Texture());
    ~Rectangle();
    
    virtual void draw(sf::RenderWindow &window);
    Vector2D get_center() const;
    Vector2D get_futhest_point(const Vector2D &direction) const;
    std::vector<Vector2D> get_vertices_coord() const;

    // Getters
    int get_height() const;
    int get_width() const;

private:
    int m_width;
    int m_height;
};
