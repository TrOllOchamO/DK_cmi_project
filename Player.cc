#include "Player.hpp"

Player::Player(float x, float y, int width, int height, float rotation, bool hasGravity, float velocityOnX, float velocityOnY, sf::Color color,sf::Texture texture) : 
Rectangle(x, y, width, height, rotation, hasGravity, velocityOnX, velocityOnY, color, texture)
{
    sprites.restart().asSeconds();
}

Player::~Player()
{

}

void Player::animation()
{
    if (sprites.getElapsedTime().asSeconds() >= 0.1)
    {
        sprites.restart().asSeconds();
        switch (m_animation)
        {
        case 0:
            m_mario->set_texture(m_mario_img[0]);
            m_animation += 1;
            break;
        case 1:
            m_mario->set_texture(m_mario_img[1]);
            m_animation += 1;
            break;
        case 2:
            m_mario->set_texture(m_mario_img[2]);
            m_animation = 0;
            break;
        default:
            std::cout << "Error: Unknown animation" << std::endl;
        }
    }
}

// Getters
int Player::get_players_life() const { return m_life; }
int Player::get_players_score() const { return m_score; }

// Setters
void Player::set_players_life(int life) { m_life = life; }
void Player::set_players_score(int score) { m_score = score; }

void Player::add_players_life(int life) { m_life += life; }
void Player::add_players_score(int score) { m_score += score; }