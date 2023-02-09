#pragma once
#include"Gun.h"
#include "Map.h"
#include<SFML/Graphics.hpp>
#include"enumHero.h"
enum {
   UP,
   LEFT,
   DOWN,
   RIGHT
};
class Hero :public sf::Drawable{
	float radius = 0.43;//radius
	int live;//zizny
	float dir;//napravlenya
	int id;//porydkovi nomer
	sf::Vector2f pos;//positia
	ShapeType type; //type formi
	int kD;
	sf::Color color;
	Gun* gun;
	Map* map;
	sf::Shape* shape;
	void download(const char* path);
	void initShape();
public:
	void setMap(Map* map);//ustanavlivaet ukazatel map
	Hero(Map* map,const char* path);//konstrucktor
	void shoot();//ctreliet
	void setColor(sf::Color c);//ustanavlyvaet chvet geroya
	void reload();//perezarezaut
	void kick();//biet
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;//resuet geroya
	void move();//dvigaetcya
};

