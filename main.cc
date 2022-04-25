#include <iostream>

#include "Math.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Game.hpp"
#include "Maps.hpp"

#define NB_FPS 60
#define FRAME_DURATION 1.0/NB_FPS

int main()
{
  sf::Clock clock;
  Game game;
  Maps::set_map1(game);

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

    // wait before rendering the frame in order to not compute more than the wanted maximum frames
    const float sleepDuration(FRAME_DURATION - dt);
    if (sleepDuration > 0) { sf::sleep(sf::microseconds(sleepDuration)); }

    game.render();

  }

  return 0;
}
