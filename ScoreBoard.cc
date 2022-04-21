#include "ScoreBoard.hpp"

ScoreBoard::ScoreBoard(float x, float y, int width, int height, const sf::Font *fonts, const Player *player, sf::Color color, sf::Texture texture) :
Rectangle(x, y, width, height, 0, false, 0, 0, color, texture),
m_text_level(m_x + 10, m_y + y, "L=01", fonts[0], 10),
m_text_score(m_x + 0, m_y + 0, "000000", fonts[0], 20),
m_text_vie_mario(m_x + 0, m_y + 0, "000000", fonts[0], 20),
m_players(player)
{
    
}

ScoreBoard::~ScoreBoard() {}