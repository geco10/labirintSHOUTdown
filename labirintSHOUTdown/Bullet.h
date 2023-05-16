#pragma once
#include<SFML/Graphics.hpp>
#include"Tickable.h"
class Bullet :public sf::Drawable,public Tickable{
    int dir;
	sf::Vector2f pos;
	bool vis;
	int damage;
	float speed;
	int range;
	float radius;
	virtual void tick(float delta)override;
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	void move(float delta);
public:
	Bullet(float speed, int dir, int damage, sf::Vector2f pos, int range, float bul_radius, bool vis);
};

