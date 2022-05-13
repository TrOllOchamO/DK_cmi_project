#include "Rectangle.hpp"

#define PI 3.14159265

Rectangle::Rectangle(float x, float y, int width, int height, float rotation, bool hasGravity, float velocityOnX, float velocityOnY, bool collide, sf::Color color, sf::Texture texture, Repeated repeat) :
Element(x, y, rotation, hasGravity, velocityOnX, velocityOnY, collide, color, texture), m_width(width), m_height(height), m_repeat(repeat)
{
}

Rectangle::Rectangle(float x, float y, int width, int height, float rotation, bool hasGravity, float velocityOnX, float velocityOnY, bool collide, sf::Texture texture, Repeated repeat) :
Element(x, y, rotation, hasGravity, velocityOnX, velocityOnY, collide, texture), m_width(width), m_height(height), m_repeat(repeat)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::draw(sf::RenderWindow &window)
{
    auto size = m_texture.getSize(); // Get the size of the texture

    sf::RectangleShape rectangle(sf::Vector2f(m_width, m_height));
    rectangle.setFillColor(m_color);
    rectangle.setPosition(m_position.x, m_position.y);
    rectangle.rotate(m_rotation);
    rectangle.setTexture(&m_texture);

    // Here we suppose that an object can't be repeated and facing to a direction
    if (m_facingDirection == FACING_RIGHT)
    {
        rectangle.setTextureRect(sf::IntRect(size.x, 0, -size.x, size.y));
    }
    if (m_repeat == VERTICALY) {
        rectangle.setTextureRect(sf::IntRect(0, 0, size.x, size.y * m_height / m_width)); // Set the position of the texture to be displayed in the rect
    }
    else if (m_repeat == HORIZONTALY) {
        rectangle.setTextureRect(sf::IntRect(0, 0, size.x * m_width / m_height, size.y)); // Set the position of the texture to be displayed in the rect
    }
    else if (m_repeat == BOTH) {
        rectangle.setTextureRect(sf::IntRect(0, 0, size.x * m_width / m_height, size.y * m_height / m_width)); // Set the position of the texture to be displayed in the rect
    }
    window.draw(rectangle);
}

Vector2D Rectangle::get_center() const
{
    const float angleInRadiant = (m_rotation*PI)/180;
    const float cosAngle = cos(angleInRadiant);
    const float sinAngle = sin(angleInRadiant);
    const float halfWidth = m_width/2;
    const float halfHeight = m_height/2;

    const Vector2D center = {m_position.x + halfWidth*cosAngle - halfHeight*sinAngle, m_position.y + halfWidth*sinAngle + halfHeight*cosAngle};
    return center;
}

std::vector<Vector2D> Rectangle::get_vertices_coord() const
{
    const float angleInRadiant = (m_rotation*PI)/180;
    const float cosAngle = cos(angleInRadiant);
    const float sinAngle = sin(angleInRadiant);

    // calculate the coordinates of the 4 vertices by taking in account the rotation of the rectangle
    // using this formula : https://stackoverflow.com/questions/1469149/calculating-vertices-of-a-rotated-rectangle#answer-1469166
    std::vector<Vector2D> vertices;
    vertices.push_back(Vector2D(m_position.x, m_position.y)); // top left corner
    vertices.push_back(Vector2D(m_position.x + m_width*cosAngle, m_position.y + sinAngle*m_width)); // top right corner
    vertices.push_back(Vector2D(m_position.x + m_width*cosAngle - m_height*sinAngle, m_position.y + m_width*sinAngle + m_height*cosAngle)); // bottom right corner
    vertices.push_back(Vector2D(m_position.x - m_height*sinAngle, m_position.y + m_height*cosAngle)); // bottom left corner

    return vertices;
}

Vector2D Rectangle::get_futhest_point(const Vector2D &direction) const
{
    std::vector<Vector2D> vertices = Rectangle::get_vertices_coord();
    
    Vector2D futhest = vertices[0]; // initialize the futhest point with the coordinates of a random corner
    float bestScore = Math::dot(direction, futhest); // calculate the score of this point

    // search for a point with a superior score
    for (int i = 1; i < 4; ++i)
    {
        const float newScore = Math::dot(direction, vertices[i]);
        if (newScore > bestScore)
        {
            bestScore = newScore;
            futhest = vertices[i];
        }
    }

    return futhest;
}

void Rectangle::update_animation(float dt, const sf::Image img[])
{
    m_clock += dt;
    if (m_clock >= 0.3)
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
            m_texture.loadFromImage(img[2]);
            m_animation += 1;
            m_facingDirection = FACING_RIGHT;
            break;
        case 4:
            m_texture.loadFromImage(img[1]);
            m_animation = 0;
            m_facingDirection = FACING_LEFT;
            break;
        default:
            std::cout << "Error: Unknown animation" << std::endl;
        }
    }
}

void Rectangle::update_animation2(float dt, const sf::Image img[])
{
    m_clock += dt;
    if (m_clock >= 0.3)
    {
        m_clock = 0;
        switch (m_animation)
        {
        case 0:
            m_texture.loadFromImage(img[0]);
            m_animation += 1;
            m_facingDirection = FACING_LEFT;
            break;
        case 1:
            m_texture.loadFromImage(img[1]);
            m_animation += 1;
            break;
        case 2:
            m_texture.loadFromImage(img[1]);
            m_animation += 1;
            m_facingDirection = FACING_RIGHT;
            break;
        case 3:
            m_texture.loadFromImage(img[0]);
            m_animation = 0;
            break;
        default:
            std::cout << "Error: Unknown animation" << std::endl;
        }
    }
}

// Getters
int Rectangle::get_height() const { return m_height; }
int Rectangle::get_width() const { return m_width; }

void Rectangle::set_repeated(Repeated repeat) { m_repeat = repeat; };
