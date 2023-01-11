#pragma once
#include"Gun.h"
#include<SFML/Graphics.hpp>
class Hero{
	int live = 100;
	float dir;
	sf::Shape *shape;
	Gun* gun;
	void shoot();
};

