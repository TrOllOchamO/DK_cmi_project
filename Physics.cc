#include "Physics.hpp"

void Physics::apply_gravity(Element *element, float timeElapsed, float gravityAcceleration)
{
    if (element->get_has_gravity()) // apply gravity only if the element shoud be affected by the gravity
    {
        const float oldVelocityOnY = element->get_velocity_on_y();
        const float newVelocityOnY = oldVelocityOnY + timeElapsed*gravityAcceleration;
        element->set_velocity_on_y(newVelocityOnY);
    }
}

bool Physics::GJK(Element *e1, Element *e2)
{
    // get the first direction vector
    const Vector2D e1Center = e1->get_center();
    const Vector2D e2Center = e2->get_center();
    Vector2D direction(Math::normalize_vector(e2Center - e1Center));

    // create a simplex and add the first point to it
    std::vector<Vector2D> simplex; 
    simplex[0] = Physics::support(e1, e2, direction);

    // setting the new direction toward the origin
    direction = -simplex[0]; // == ORIGIN - A == (0, 0) - A

    while (true)
    {
        // get the second point of the vertex
        Vector2D A = Physics::support(e1, e2, direction);

        // if the new point didn't pass the origin then the origin can't be inside the Minkowski difference
        // and by extention the 2 shapes aren't colliding, so return false
        if (Math::dot(A, direction) < 0) { return false; }
        
        // append the new point to the simplex
        simplex.push_back(A);

        // return true if the origin is inside the simplex
        // else modify the direction vector and the simplex in order to reiterate the steps
        if (handle_simplex(simplex, direction))
        {
            return true;
        }
    }
}

Vector2D Physics::support(Element *e1, Element *e2, Vector2D &direction)
{
    return e1->get_futhest_point(direction) - e2->get_futhest_point(-direction);
}

bool Physics::handle_simplex(std::vector<Vector2D> &simplex, Vector2D &direction)
{
    if (simplex.size() == 2) { return handle_line_simplex(simplex, direction); }
    return handle_triangle_simplex(simplex, direction);
}

bool Physics::handle_line_simplex(std::vector<Vector2D> &simplex, Vector2D &direction)
{
    Vector2D B = simplex[0];
    Vector2D A = simplex[1];

    Vector2D AB = B - A;
    Vector2D OA = -A; // == (0, 0) - A

    // get the vector perpendicular to AB and pointing toward the origin
    Vector2D ABPerp = Math::triple_cross_product(AB, OA, AB);

    direction = ABPerp; // redifine the direction toward the origin

    // since the simplex is a line the odd of it to containing the origin in a 2D space
    // is almost null, so return null without bothering to check is more efficient
    // if the simplex was indeed containing the origin the next step of the gjk will tell it
    return false;
}



bool Physics::handle_triangle_simplex(std::vector<Vector2D> &simplex, Vector2D &direction)
{
    int simplexSize = simplex.size();

    Vector2D A = simplex[simplexSize - 1];
    Vector2D B = simplex[simplexSize - 2];
    Vector2D C = simplex[simplexSize - 3];

    Vector2D AB = B - A;
    Vector2D AC = C - A;
    Vector2D AO = -A; // == (0, 0) - A

    Vector2D ABPerp = Math::triple_cross_product(AC, AB, AB);
    if (Math::dot(ABPerp, AO) > 0) // if the origin is in the region AB
    {
        simplex.erase(simplex.begin()); // remove the point C of the simplex
        direction = ABPerp; // setting the new direction toward the region AB
        return false; // since the point is contain in the region AB then it's not contain in the simplex
    }

    Vector2D ACPerp = Math::triple_cross_product(AB, AC, AC);
    if (Math::dot(ACPerp, AO) > 0) // if the origin is in the region AC
    {
        simplex.erase(std::next(simplex.begin())); // remove the point B of the simplex
        direction = ABPerp; // setting the new direction toward the region AC
        return false; // since the point is contain in the region AC then it's not contain in the simplex
    }

    // if the origin isn't in both of the 2 area then it belong in the simplex due to the way
    // we first obtained this simplex, so we return true
    return true;
}