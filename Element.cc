#include "Element.hpp"

Element::Element(float x, float y, float rotation, bool hasGravity, float velocityOnX, float velocityOnY, sf::Color color) : 
m_x(x), m_y(y), m_rotation(rotation), m_hasGravity(hasGravity), m_velocityOnX(velocityOnX), m_velocityOnY(velocityOnY), m_color(color)
{
    
}

Element::~Element()
{
    
}

void Element::update_position(float timeElapsed)
{
    m_x += m_velocityOnX * timeElapsed;
    m_y += m_velocityOnY * timeElapsed;
}

void Element::set_x(float x) { m_x = x; }
void Element::set_y(float y) { m_y = y; }
void Element::set_has_gravity(bool hasGravity) { m_hasGravity = hasGravity; }
void Element::set_velocity_on_x(float velocityOnX) { m_velocityOnX = velocityOnX; }
void Element::set_velocity_on_y(float velocityOnY) { m_velocityOnY = velocityOnY; }
void Element::set_color(sf::Color color) { m_color = color; }

float Element::get_x() const { return m_x; }
float Element::get_y() const { return m_y; }
bool Element::get_has_gravity() const { return m_hasGravity; }
float Element::get_velocity_on_x() const { return m_velocityOnX; }
float Element::get_velocity_on_y() const {return m_velocityOnY; }
sf::Color Element::get_color() const { return m_color; }