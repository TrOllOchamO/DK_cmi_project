#include "Element.hpp"

Element::Element(float x, float y, float rotation, bool hasGravity, float velocityOnX, float velocityOnY, bool collide, sf::Color color, sf::Texture texture): 
m_position(x, y), m_previousPosition(x, y), m_rotation(rotation), m_hasGravity(hasGravity), m_velocity(velocityOnX, velocityOnY), m_collide(collide), m_color(color), 
m_texture(texture), m_resourcesPointer(nullptr)
{

}

Element::Element(float x, float y, float rotation, bool hasGravity, float velocityOnX, float velocityOnY, bool collide, sf::Texture texture) :
m_position(x, y), m_previousPosition(x, y), m_rotation(rotation), m_hasGravity(hasGravity), m_velocity(velocityOnX, velocityOnY), m_collide(collide), m_color(sf::Color::White),
m_texture(texture), m_resourcesPointer(nullptr)
{
    
}

Element::~Element()
{
    
}

void Element::update_position(float timeElapsed)
{
    m_previousPosition = m_position;
    m_position.x += m_velocity.x * timeElapsed;
    m_position.y += m_velocity.y * timeElapsed;
}

void Element::move_in_a_direction(const Vector2D &direction, float distance)
{
    m_previousPosition = m_position;
    m_position.x += direction.x*distance;
    m_position.y += direction.y*distance;
}

void Element::update_animation(float dt, const sf::Image img[])
{
    
}

void Element::update_animation2(float dt, const sf::Image img[])
{
    
}

// Setters
void Element::set_x(float x) { m_position.x = x; }
void Element::set_y(float y) { m_position.y = y; }
void Element::set_position(const Vector2D &position) 
{
    m_previousPosition = m_position;
    this->set_x(position.x);
    this->set_y(position.y);
}
void Element::set_previous_position(const Vector2D &previousPosition) { m_previousPosition = previousPosition; }
void Element::set_has_gravity(bool hasGravity) { m_hasGravity = hasGravity; }
void Element::set_velocity_on_x(float velocityOnX) { m_velocity.x = velocityOnX; }
void Element::set_velocity_on_y(float velocityOnY) { m_velocity.y = velocityOnY; }
void Element::set_velocity(const Vector2D &velocity) { m_velocity = velocity; }
void Element::set_bounciness(float bounciness) { m_bounciness = bounciness; }
void Element::set_color(sf::Color color) { m_color = color; }
void Element::set_texture(sf::Image image) { m_texture.loadFromImage(image); }
void Element::set_resources_pointer(Resources *resources) { m_resourcesPointer = resources; }

// Getters
float Element::get_x() const { return m_position.x; }
float Element::get_y() const { return m_position.y; }
Vector2D Element::get_position() const { return m_position; }
bool Element::get_has_gravity() const { return m_hasGravity; }
float Element::get_velocity_on_x() const { return m_velocity.x; }
float Element::get_velocity_on_y() const {return m_velocity.y; }
Vector2D Element::get_velocity() const {return m_velocity; }
float Element::get_bounciness() const { return m_bounciness; }
sf::Color Element::get_color() const { return m_color; }
Vector2D Element::get_previous_position() const { return m_previousPosition; }
bool Element::get_collide() const { return m_collide; };
