#pragma once

#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "Element.hpp"

class Rectangle : public Element 
{
public:
    Rectangle(float x, float y, int width, int height, float rotation = 0, bool hasGravity = false, float velocityOnX = 0, float velocityOnY = 0, bool collide = true, sf::Color color = sf::Color::White, sf::Texture texture = sf::Texture(), Repeated repeat = NO);
    Rectangle(float x, float y, int width, int height, float rotation = 0, bool hasGravity = false, float velocityOnX = 0, float velocityOnY = 0, bool collide = true, sf::Texture texture = sf::Texture(), Repeated repeat = NO);
    ~Rectangle();
    
    virtual void draw(sf::RenderWindow &window);
    Vector2D get_center() const;
    Vector2D get_futhest_point(const Vector2D &direction) const;
    std::vector<Vector2D> get_vertices_coord() const;
    virtual void update_animation(float dt, const sf::Image img[]);
    virtual void update_animation2(float dt, const sf::Image img[]);

    // Getters
    int get_height() const;
    int get_width() const;

    // Setters
    void set_repeated(Repeated repeat);

private:
    int m_width;
    int m_height;
    Repeated m_repeat;
    double m_clock = 0;
    FacingDirection m_facingDirection = FACING_LEFT;
};
