#include <iostream>

#include "Math.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Game.hpp"
#include "Maps.hpp"

int main()
{
  sf::Clock clock;
  Game game;
  Maps::set_map2(game);

  /*
   * GAME LOOP
   */
  while (game.is_open()) {

    /*
     * update state
     */
    float dt = clock.restart().asSeconds();

    game.update(dt);

    /*
     * render states
     */

    game.render(); 
  }

  return 0;
}
