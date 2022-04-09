#pragma once

#include "Math.hpp"
#include "Element.hpp"

class Physics
{
public:
    // Used to calculate colision and penetration depth vector reffer to this video https://www.youtube.com/watch?v=ajv46BSqcK4&t
    // and this website 
    static bool GJK(Element *e1, Element *e2);
    static Vector2D support(Element *e1, Element *e2, Vector2D &direction);

    static void apply_gravity(Element *element, float timeElapsed, float gravityAcceleration);
};