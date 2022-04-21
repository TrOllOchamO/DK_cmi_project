#pragma once

#include "Element.hpp"

class Text : public Element {
public:
    Text(std::string text, int size, sf::Font font, float x, float y, int width = 0, int height = 0, float rotation = 0, bool hasGravity = false, float velocityOnX = 0, float velocityOnY = 0, sf::Color color = sf::Color::White);
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
