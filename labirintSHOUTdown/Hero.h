#pragma once
#include"Gun.h"
#include<SFML/Graphics.hpp>
class Hero{
	int live = 100;
	float dir;
	sf::Vector2f pos;
	int type;
	sf::Shape *shape;
	int kD;
	Gun* gun;

	void shoot();
	void reload();
	void kick();
	void move();
};

