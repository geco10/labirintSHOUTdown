#include "VectorFunctions.h"

float vec::len(sf::Vector2f a)
{
    return sqrt(a.x*a.x+a.y*a.y);
}
sf::Vector2f vec::xyToLenfi(sf::Vector2f v)
{
    sf::Vector2f res;
    res.x = sqrt(v.x * v.x + v.y * v.y);
    if (res.x == 0) return res;
    if (v.x == 0)
        res.y = v.y > 0 ? M_PI_2 : -M_PI_2;
    else {
        float t = atan(v.y / v.x);
        res.y = v.x > 0 ? t : M_PI + t;
    }
    return res;
}
sf::Vector2f vec::pointFrame(sf::Vector2f pos)
{
    sf::Vector2f res;
    res.x = trunc(pos.x);
    res.y = trunc(pos.y);

    return res;
}
sf::Vector2f vec::lenfiToXy(sf::Vector2f lenfi_v)
{
    sf::Vector2f res;
    res.x = lenfi_v.x * cos(lenfi_v.y);
    res.y = lenfi_v.x * sin(lenfi_v.y);

    return res;
}
sf::Vector2f vec::normalize(sf::Vector2f a)
{
    if (a.x == 0 && a.y == 0) return a;
    return a/len(a);
}
