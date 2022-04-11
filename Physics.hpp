#pragma once

#include "Math.hpp"
#include "Element.hpp"

class Physics
{
public:
    // change the Y velocity of the element accordingly to the gravityAcceleration ant the time elapsed 
    static void apply_gravity(Element *element, float timeElapsed, float gravityAcceleration);


    /* 
     * Below functions are used to calculate colision and penetration depth vector
     * reffer to this great video https://www.youtube.com/watch?v=ajv46BSqcK4&t
     * and this website https://dyn4j.org/2010/04/gjk-gilbert-johnson-keerthi
     */

    // return true if 2 Element overlap
    static bool GJK(Element *e1, Element *e2);

private:
    // return the point the point on the edge of the Minkowski difference in the given direction
    static Vector2D support(Element *e1, Element *e2, Vector2D &direction);

    // return true if the origin is inside the simplex 
    // else modify the simplex by adding/modifying points and redifine the direction vector
    // to prepare to the next step of the gjk algorithm 
    static bool handle_simplex(std::vector<Vector2D> &simplex, Vector2D &direction);

    // take a 2 points simplex, update the direction toward the origin, return false
    static bool handle_line_simplex(std::vector<Vector2D> &simplex, Vector2D &direction);

    // 
    static bool handle_triangle_simplex(std::vector<Vector2D> &simplex, Vector2D &direction);

};