#include "ScoreBoard.hpp"

ScoreBoard::ScoreBoard(float x, float y, int width, int height, const sf::Font *fonts, const Player *player, bool collide, sf::Color color, sf::Texture texture) :
Rectangle(x, y, width, height, 0, false, 0, 0, collide, color, texture),
m_text_level(x + 580, y + 8, "L=01", fonts[0], 20, 0, false, sf::Color::Blue),
m_text_score(x + 7, y + 7, "", fonts[0], 28),
m_text_player_life(x + 100, y + 100, "000000", fonts[0], 20),
m_players(player)
{

}

ScoreBoard::ScoreBoard(float x, float y, int width, int height, const sf::Font *fonts, const Player *player, bool collide, sf::Texture texture) :
Rectangle(x, y, width, height, 0, false, 0, 0, collide, texture),
m_text_level(x + 7, y + 7, "L=01", fonts[0], 20),
m_text_score(x + 512, y + 8, "000000", fonts[0], 20),
m_text_player_life(x + 100, y + 100, "000000", fonts[0], 20),
m_players(player)
{
    
}

ScoreBoard::~ScoreBoard() {}

void ScoreBoard::draw(sf::RenderWindow &window)
{
    m_text_score.set_text(std::to_string(m_players->get_player_score()));
    m_text_player_life.set_text(std::to_string(m_players->get_player_life()));
    m_text_level.draw(window);
    m_text_score.draw(window);
    m_text_player_life.draw(window);
}

Text ScoreBoard::getTextLevel() const { return m_text_level; }
Text ScoreBoard::getTextScore() const { return m_text_score; }
Text ScoreBoard::getTextVieMario() const { return m_text_player_life; }
