#include "Player.hpp"

Player::Player(float x, float y, int width, int height, float rotation, bool hasGravity, float velocityOnX, float velocityOnY, sf::Color color, int life, int score) : 
Rectangle(x, y, width, height, rotation, hasGravity, velocityOnX, velocityOnY, color), m_life(life), m_score(score)
{

}

Player::~Player()
{

}

// Getters
int Player::get_players_life() const { return m_life; }
int Player::get_players_score() const { return m_score; }

// Setters
void Player::set_players_life(int life) { m_life = life; }
void Player::set_players_score(int score) { m_score = score; }

void Player::add_players_life(int life) { m_life += life; }
void Player::add_players_score(int score) { m_score += score; }