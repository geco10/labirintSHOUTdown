#include "CircleColison.h"
#include<cmath>
bool CircleColison::WallColison(sf::Vector2f step)
{ 
	sf::Vector2f new_pos = pos + step;
	float x = radius;
	float y = new_pos.y - pos.y;
	float u = atan(y/x);
	float l = sqrt(x*x+y*y);
	sf::Vector2f a;
	sf::Vector2f b;
	sf::Vector2f c;
}