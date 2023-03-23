#define _USE_MATH_DEFINES
#include "CircleColison.h"
#include<cmath>
#include"VectorFunctions.h"
bool CircleColison::WallColison(sf::Vector2f step)
{ 
	sf::Vector2f new_pos = pos + step;
	float fi = vec::xyToLenfi(step).y;
	float len = radius;
	sf::Vector2f a= new_pos + vec::lenfiToXy(sf::Vector2f(len, fi-M_PI_4));
	sf::Vector2f b=new_pos+vec::lenfiToXy(sf::Vector2f(len,fi));
	sf::Vector2f c= new_pos + vec::lenfiToXy(sf::Vector2f(len, fi + M_PI_4));
	if (map->getFrame(vec::pointFrame(a)) == '#')return false;
	if (map->getFrame(vec::pointFrame(b)) == '#')return false;
	if (map->getFrame(vec::pointFrame(c)) == '#')return false;
	return true;
}
CircleColison::CircleColison() {
	objects.push_back(this);
}
CircleColison::~CircleColison() {
	int i = 0;
	for (; objects[i] != this; i++);
	objects.erase(objects.begin()+i);
}