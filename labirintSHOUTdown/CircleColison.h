#pragma once
#include<SFML/Graphics.hpp>
class CircleColison
{
protected:
	sf::Vector2f pos;
	float radius;
public:
	CircleColison()=default;
	bool WallColison(sf::Vector2f step);
};

