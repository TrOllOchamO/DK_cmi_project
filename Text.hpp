#pragma once

#include "Element.hpp"

class Text : public Element {
public:
    Text(float x, float y, std::string text, sf::Font font, int size = 5, float rotation = 0, bool collide = false, sf::Color color = sf::Color::White);
    Text();
    ~Text();

    void draw(sf::RenderWindow & window);

    // Setters
    void set_text(std::string text); // Allow to modify the text during the game

    // Getters
    Vector2D get_center() const;
    Vector2D get_futhest_point(const Vector2D &direction) const;

private:
    std::string m_text; 
    int m_size; // Size of the text
    sf::Font m_font;
};
