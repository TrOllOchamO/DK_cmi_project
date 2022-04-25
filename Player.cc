#include "Player.hpp"

#define WALKING_SPEED 250

Player::Player(float x, float y, int width, int height, float rotation, bool hasGravity, float velocityOnX, float velocityOnY, sf::Color color,sf::Texture texture) : 
Rectangle(x, y, width, height, rotation, hasGravity, velocityOnX, velocityOnY, color, texture)
{

}

Player::~Player()
{

}

void Player::draw(sf::RenderWindow &window)
{
    auto size = m_texture.getSize(); // Get the size of the texture

    sf::RectangleShape rectangle(sf::Vector2f(get_width(), get_height()));
    rectangle.setPosition(m_x, m_y);
    rectangle.setTexture(&m_texture);
    if (m_facingDirection == FACING_RIGHT) {
        rectangle.setTextureRect(sf::IntRect(size.x, 0, -size.x, size.y));
    }
    rectangle.setFillColor(m_color);
    rectangle.rotate(m_rotation);
    window.draw(rectangle);
}

void Player::update_animation(float dt)
{
    m_clock += dt;
    if (m_clock >= 0.1)
    {
        m_clock = 0;
        switch (m_animation)
        {
        case 0:
            m_texture.loadFromImage(m_resourcesPointer->m_player_img[0]);
            m_animation += 1;
            break;
        case 1:
            m_texture.loadFromImage(m_resourcesPointer->m_player_img[1]);
            m_animation += 1;
            break;
        case 2:
            m_texture.loadFromImage(m_resourcesPointer->m_player_img[2]);
            m_animation = 0;
            break;
        default:
            std::cout << "Error: Unknown animation" << std::endl;
        }
    }
}

void Player::update_player(Inputs &inputs, float dt)
{
    // Effectue ces évènements lors qu'une touche est appuyé
    const bool BOTH_RIGHT_AND_LEFT_PRESSED = (inputs.leftKeyPressed && inputs.rightKeyPressed);
    const bool NO_RIGHT_NO_LEFT_PRESSED = !(inputs.leftKeyPressed || inputs.rightKeyPressed);
    const bool MARIO_ISNT_MOVING = (BOTH_RIGHT_AND_LEFT_PRESSED || NO_RIGHT_NO_LEFT_PRESSED);

    if (MARIO_ISNT_MOVING) // mario stand still
    {
        m_velocityOnX = 0;
        m_texture.loadFromImage(m_resourcesPointer->m_player_img[0]); // Texture of mario when he's not moving
    }
    else if (inputs.leftKeyPressed) // mario is walking on the left
    {
        m_velocityOnX = -WALKING_SPEED;
        m_facingDirection = FACING_LEFT;
        this->update_animation(dt);
    }
    else // mario is walking to the right
    {
        m_velocityOnX = WALKING_SPEED;
        m_facingDirection = FACING_RIGHT;
        this->update_animation(dt);
    }

    // case mario jump
    if (inputs.upKeyPressed)
    {
        m_velocityOnY = -250;
        m_texture.loadFromImage(m_resourcesPointer->m_player_img[3]); // Texture of mario when he's jumping
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
