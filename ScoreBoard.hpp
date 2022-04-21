#pragma once

#include "Rectangle.hpp"
#include "Player.hpp"
#include "Text.hpp"

class ScoreBoard : public Rectangle 
{
public:
    ScoreBoard(float x, float y, int width, int height, const sf::Font *fonts, const Player *player, sf::Color color = sf::Color::White, sf::Texture texture = sf::Texture());
    ~ScoreBoard();

private:
    Text m_text_level;
    Text m_text_score;
    Text m_text_vie_mario;

    const Player *m_players;
};