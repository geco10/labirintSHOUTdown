#pragma once
#include<SFML/Graphics.hpp>
class Bullet :public sf::Drawable{
    int dir;
	sf::Vector2f pos;
	bool vis;
	int damage;
	float speed;
	int range;
	float radius;
	Bullet(const int* dir, int damage,float speed,const sf::Vector2f* pos, int range, int bul_radius, bool vis);
	void move(float delta);
};

