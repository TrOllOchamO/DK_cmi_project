#pragma once

#include "Rectangle.hpp"

class Player : public Rectangle
{
public:
    Player(float x, float y, int width, int height, float rotation = 0, bool hasGravity = false, float velocityOnX = 0, float velocityOnY = 0, sf::Color color = sf::Color::White, sf::Texture texture = sf::Texture(), int life = 3, int score = 0);
    ~Player();


    // Getters functions
    int get_players_life() const;
    int get_players_score() const;


    // Setters functions
    void set_players_life(int life); // Pour le moment inutile
    void set_players_score(int score); // Idem

    void add_players_life(int life);
    void add_players_score(int score);

private:
    int m_life;
    int m_score;
};
