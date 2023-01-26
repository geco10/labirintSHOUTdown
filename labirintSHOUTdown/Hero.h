#pragma once
#include"Gun.h"
#include "Map.h"
#include<SFML/Graphics.hpp>
#include"enumHero.h"
class Hero :public sf::Drawable{
	int live = 100;
	float dir;
	sf::Vector2f pos;
	ShapeType type;
	int kD;
	sf::Color color;
	Gun* gun;
	Map* map;
public:
	Hero();
	void shoot();
	void setColor(sf::Color c);
	void reload();
	void kick();
	void setMap(Map* map);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	void move();
};

