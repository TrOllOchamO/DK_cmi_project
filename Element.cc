#include "Element.h"

Element::Element(float x, float y, int rotation, bool hasGravity, float velocityOnX, float velocityOnY, sf::Color color) : 
m_x(x), m_y(y), m_rotation(rotation), m_hasGravity(hasGravity), m_velocityOnX(velocityOnX), m_velocityOnY(velocityOnY), m_color(color)
{
    
}

Element::~Element()
{
    
}

void Element::apply_gravity(float timeElapsed, float gravityAcceleration)
{
    if (m_hasGravity)
    {
        m_velocityOnY += timeElapsed*gravityAcceleration;
    }
}

void Element::update_position(float timeElapsed)
{
    m_x += m_velocityOnX*timeElapsed;
    m_y += m_velocityOnY*timeElapsed;
}

bool Element::GJK(Element *e1, Element *e2) const
{
    // get the direction vector
    const Vector2D e1Center = e1->get_center();
    const Vector2D e2Center = e2->get_center();
    const Vector2D centerVect = e2Center - e1Center;
    Vector2D direction(Math::normalize_vector(centerVect));



    return true;
}

Vector2D Element::support(Element *e1, Element *e2, Vector2D &direction) const
{
    return e1->get_futhest_point(direction) - e2->get_futhest_point(-direction);
}

void Element::set_x(float x) { m_x = x; }
void Element::set_y(float y) { m_y = y; }
void Element::set_velocity_on_x(float velocityOnX) { m_velocityOnX = velocityOnX; }
void Element::set_velocity_on_y(float velocityOnY) { m_velocityOnY = velocityOnY; }
void Element::set_color(sf::Color color) { m_color = color; }

float Element::get_x() const{ return m_x; }
float Element::get_y() const { return m_y; }
float Element::get_velocity_on_x() const { return m_velocityOnX; }
float Element::get_velocity_on_y() const {return m_velocityOnY; }
sf::Color Element::get_color() const { return m_color; }