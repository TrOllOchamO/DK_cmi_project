#include <iostream>

#include "Math.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Game.h"
#include "Maps.h"

#define NB_FPS 60.0
#define FRAME_DURATION 1/NB_FPS

int main()
{
  sf::Clock clock;
  Game game;

  /*
   * GAME LOOP
   */
  while (game.is_open()) {

    /*
     * event loop
     */
    sf::Event event;
    while (game.poll_event(event)) 
    {
      game.treat_event(event);
    }

    /*
     * update state
     */
    float dt = clock.restart().asSeconds();

    // update every elements
    game.update(dt);

    /*
     * render states
     */

    //wait before rendering the frame in order to not compute more than the wanted maximum frames
    const float sleepDuration(FRAME_DURATION - dt);
    if (sleepDuration > 0) { sf::sleep(sf::microseconds(sleepDuration)); }

    game.render();

  }

  return 0;
}
