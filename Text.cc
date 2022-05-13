#include "Text.hpp"

Text::Text(float x, float y, std::string text, sf::Font font, int size, float rotation, bool collide, sf::Color color)
    : Element(x, y, 0, false, 0, 0, collide, color), m_text(text), m_size(size), m_font(font)
{

}

Text::~Text() {}

// Draw text into the window
void Text::draw(sf::RenderWindow &window)
{
    sf::Text text;
    text.setString(m_text);
    text.setFont(m_font);
    text.setCharacterSize(m_size);
    text.setFillColor(m_color);
    text.setPosition(m_position.x, m_position.y);
    window.draw(text);
}

// Setters
void Text::set_text(std::string text) { m_text = text; }


// Getters
Vector2D Text::get_center() const {  }
Vector2D Text::get_futhest_point(const Vector2D &direction) const {  }
