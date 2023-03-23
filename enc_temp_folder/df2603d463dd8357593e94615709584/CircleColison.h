#pragma once
#include<set>
#include<SFML/Graphics.hpp>
#include"Map.h"
class CircleColison
{
public:
	static std::set<CircleColison*> objects;
protected:
	sf::Vector2f pos;
	float radius;
	Map *map;
public:
	CircleColison();
	bool WallColison(sf::Vector2f step);
	~CircleColison();
};

