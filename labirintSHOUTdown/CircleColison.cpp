#include "CircleColison.h"
#include<cmath>
bool CircleColison::WallColison(sf::Vector2f step)
{ 
	sf::Vector2f new_pos = pos + step;
	float u = atan(step.y/step.x);
	float len = radius;
	sf::Vector2f a;
	sf::Vector2f b;
	sf::Vector2f c;
}