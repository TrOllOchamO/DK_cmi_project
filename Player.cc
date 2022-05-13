#include "Player.hpp"

#define WALKING_SPEED 250

Player::Player(float x, float y, int width, int height, float rotation, bool hasGravity, float velocityOnX, float velocityOnY, bool collide, sf::Color color,sf::Texture texture) : 
Rectangle(x, y, width, height, rotation, hasGravity, velocityOnX, velocityOnY, collide, color, texture)
{

}

Player::~Player()
{

}

void Player::draw(sf::RenderWindow &window)
{
    auto size = m_texture.getSize(); // Get the size of the texture

    sf::RectangleShape rectangle(sf::Vector2f(get_width(), get_height()));
    rectangle.setPosition(m_position.x, m_position.y);
    rectangle.setTexture(&m_texture);
    if (m_facingDirection == FACING_RIGHT) {
        rectangle.setTextureRect(sf::IntRect(size.x, 0, -size.x, size.y));
    }
    rectangle.setFillColor(m_color);
    rectangle.rotate(m_rotation);
    window.draw(rectangle);
}

void Player::update_animation(float dt, const sf::Image img[])
{
    m_clock += dt;
    if (m_clock >= 0.1)
    {
        m_clock = 0;
        switch (m_animation)
        {
        case 0:
            m_texture.loadFromImage(img[0]);
            m_animation += 1;
            break;
        case 1:
            m_texture.loadFromImage(img[1]);
            m_animation += 1;
            break;
        case 2:
            m_texture.loadFromImage(img[2]);
            m_animation += 1;
            break;
        case 3:
            m_texture.loadFromImage(img[1]);
            m_animation = 0;
            break;
        default:
            std::cout << "Error: Unknown animation" << std::endl;
        }
    }
}

bool Player::update_player(Inputs &inputs, float dt, const sf::Image img[])
{
    // Effectue ces évènements lors qu'une touche est appuyé
    const bool BOTH_RIGHT_AND_LEFT_PRESSED = (inputs.leftKeyPressed && inputs.rightKeyPressed);
    const bool NO_RIGHT_NO_LEFT_PRESSED = !(inputs.leftKeyPressed || inputs.rightKeyPressed);
    const bool MARIO_ISNT_MOVING = (BOTH_RIGHT_AND_LEFT_PRESSED || NO_RIGHT_NO_LEFT_PRESSED);

    bool playerTryToMove(false);

    if (MARIO_ISNT_MOVING) // mario stand still
    {
        m_velocity.x = 0;
        m_texture.loadFromImage(img[0]); // Texture of mario when he's not moving
    }
    else if (inputs.leftKeyPressed) // mario is walking on the left
    {
        m_score += 1;
        m_velocity.x = -WALKING_SPEED;
        m_facingDirection = FACING_LEFT;
        playerTryToMove = true;
        this->update_animation(dt, img);
    }
    else // mario is walking to the right
    {
        m_velocity.x = WALKING_SPEED;
        m_facingDirection = FACING_RIGHT;
        playerTryToMove = true;
        this->update_animation(dt, img);
    }

    // case mario jump
    if (inputs.upKeyPressed)
    {
        m_velocity.y = -250;
        playerTryToMove = true;
        m_texture.loadFromImage(img[3]); // Texture of mario when he's jumping
    }

    return playerTryToMove;
}

// Getters
int Player::get_player_life() const { return m_life; }
int Player::get_player_score() const { return m_score; }

// Setters
void Player::set_player_life(int life) { m_life = life; }
void Player::set_player_score(int score) { m_score = score; }

void Player::add_player_life(int life) { m_life += life; }
void Player::add_player_score(int score) { m_score += score; }
