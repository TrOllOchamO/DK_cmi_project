#pragma once

#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "Element.hpp"

class Barrel : public Element
{
public:
    Barrel(float x, float y, float velocityOnX = 250, float velocityOnY = 0, float frequency = 20, sf::Color color = sf::Color::Transparent);
    ~Barrel();

    void draw(sf::RenderWindow &window);
    
    Vector2D get_center() const;
    Vector2D get_futhest_point(const Vector2D &direction) const;
    std::vector<Vector2D> get_vertices_coord() const;

    void update_animation(float dt, const sf::Image img[]);

private:
    int m_width;
    int m_height;
    double m_clock = 0;
    FacingDirection m_facingDirection = FACING_LEFT;
};
