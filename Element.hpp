#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Math.hpp"

class Element
{
public:
    Element(float x, float y, float rotation = 0, bool hasGravity = false, float velocityOnX = 0, float velocityOnY = 0, sf::Color color = sf::Color::White);
    virtual ~Element();

    void update_position(float timeElapsed);
    void move_in_a_direction(const Vector2D &direction, float distance);
    virtual void draw(sf::RenderWindow &window) = 0;

    // Used to calculate colision
    virtual Vector2D get_center() const = 0;
    virtual Vector2D get_futhest_point(const Vector2D &direction) const = 0;

    void set_x(float x);
    void set_y(float y);
    void set_has_gravity(bool hasGravity);
    void set_velocity_on_x(float velocityOnX);
    void set_velocity_on_y(float velocityOnY);
    void set_color(sf::Color color);

    float get_x() const;
    float get_y() const;
    bool get_has_gravity() const;
    float get_velocity_on_x() const;
    float get_velocity_on_y() const;
    sf::Color get_color() const;

protected:
    float m_x;
    float m_y;
    float m_rotation;
    bool m_hasGravity;
    float m_velocityOnX;
    float m_velocityOnY;
    sf::Color m_color;
};

