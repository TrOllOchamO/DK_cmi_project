#include "Physics.hpp"

bool Physics::GJK(Element *e1, Element *e2)
{
    // get the direction vector
    const Vector2D e1Center = e1->get_center();
    const Vector2D e2Center = e2->get_center();
    const Vector2D centerVect = e2Center - e1Center;
    Vector2D direction(Math::normalize_vector(centerVect));



    return true;
}

Vector2D Physics::support(Element *e1, Element *e2, Vector2D &direction)
{
    return e1->get_futhest_point(direction) - e2->get_futhest_point(-direction);
}

void Physics::apply_gravity(Element *element, float timeElapsed, float gravityAcceleration)
{
    if (element->get_has_gravity()) // apply gravity only if the element shoud be affected by the gravity
    {
        const float oldVelocityOnY = element->get_velocity_on_y();
        const float newVelocityOnY = oldVelocityOnY + timeElapsed*gravityAcceleration;
        element->set_velocity_on_y(newVelocityOnY);
    }
}