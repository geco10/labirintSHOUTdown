#pragma once
#include<SFML/Graphics.hpp>
#include"Map.h"
class CircleColison
{
protected:
	sf::Vector2f pos;
	float radius;
	Map *map;
public:
	CircleColison()=default;
	bool WallColison(sf::Vector2f step);
};

