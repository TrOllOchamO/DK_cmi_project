#pragma once

#include "Rectangle.hpp"
#include "Resources.hpp"
#include "Inputs.hpp"

enum PlayerFacingDirection
{
    FACING_LEFT,
    FACING_RIGHT
};

class Player : public Rectangle
{
public:
    Player(float x, float y, int width, int height, float rotation = 0, bool hasGravity = false, float velocityOnX = 0, float velocityOnY = 0, sf::Color color = sf::Color::White, sf::Texture texture = sf::Texture());
    ~Player();

    void draw(sf::RenderWindow &window);
    void update_animation(float dt);

    // update the player animation accordingly with the inputs, also update the player velocity
    // in the direction he try to move, if the player try to move return true
    bool update_player(Inputs &inputs, float dt); 


    // Getters
    int get_player_life() const;
    int get_player_score() const;

    // Setters
    void set_player_life(int life); // Pour le moment inutile
    void set_player_score(int score); // Idem

    void add_player_life(int life);
    void add_player_score(int score);

private:
    int m_life = 3;
    int m_score = 0;
    int m_animation = 0;
    double m_clock = 0;
    PlayerFacingDirection m_facingDirection= FACING_LEFT;
};
