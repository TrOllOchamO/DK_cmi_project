#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Math.hpp"

class Element
{
public:
    Element(float x, float y, float rotation = 0, bool hasGravity = false, float velocityOnX = 0, float velocityOnY = 0, sf::Color color = sf::Color::White, sf::Texture texture = sf::Texture());
    virtual ~Element();

    // Used when the Element has to move
    void update_position(float timeElapsed);
    void move_in_a_direction(const Vector2D &direction, float distance);

    // Used to render the Element
    virtual void draw(sf::RenderWindow &window) = 0;
    virtual void update_animation(float dt); // take in parameter the time since the last call

    // Used to calculate colision between Elements
    virtual Vector2D get_center() const = 0;
    virtual Vector2D get_futhest_point(const Vector2D &direction) const = 0;

    void set_x(float x);
    void set_y(float y);
    void set_has_gravity(bool hasGravity);
    void set_velocity_on_x(float velocityOnX);
    void set_velocity_on_y(float velocityOnY);
    void set_color(sf::Color color);
    void set_texture(sf::Image image);
    void set_texture_reversed(sf::Texture texture);

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
    sf::Texture m_texture;
    int m_animation = 0; // store the index of the current element texture
    float m_animation_time = 0; // store the time since the last animation occured
};