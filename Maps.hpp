#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Text.hpp"
#include "ScoreBoard.hpp"
#include "Resources.hpp"


struct Maps
{
    // take a game and initialise it with every elements of the first level and load the according textures
    static void set_map1(Game &game);
};