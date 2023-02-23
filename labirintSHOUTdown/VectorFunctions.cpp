#include "VectorFunctions.h"

float vec::len(sf::Vector2f a)
{
    return sqrt(a.x*a.x+a.y*a.y);
}

sf::Vector2f vec::normalize(sf::Vector2f a)
{
    if (a.x == 0 && a.y == 0) return a;
    return a/len(a);
}
