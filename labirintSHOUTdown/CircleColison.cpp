#define _USE_MATH_DEFINES
#include "CircleColison.h"
#include<cmath>
#include"VectorFunctions.h"
bool CircleColison::WallColison(sf::Vector2f step)
{ 
	sf::Vector2f new_pos = pos + step+sf::Vector2f(radius,radius);
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
	objects.insert(this);
}
CircleColison::~CircleColison() {
	objects.erase(this);
}
bool CircleColison::objectColison(sf::Vector2f step){
	sf::Vector2f new_pos = pos + step + sf::Vector2f(radius, radius);
	for  (CircleColison* x : objects){
		if (x == this) continue;
		if (x->radius + this->radius >= vec::xyToLenfi((x->pos+sf::Vector2f(radius,radius)) - new_pos).x)
			return true;//true colison
	}
	return false;
}
std::set<CircleColison*> CircleColison::objects = {};