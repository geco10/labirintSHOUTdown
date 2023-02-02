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
	int live = 100;//zizny
	float dir;//napravlenya
	int id;//porydkovi nomer
	sf::Vector2f pos;//positia
	ShapeType type; //type formi
	int kD;
	sf::Color color;
	Gun* gun;
	Map* map;
	void download(const char* path);
public:
	void setMap(Map* map);//ustanavlivaet ukazatel map
	Hero(int d,Map* map,const char* path);//konstrucktor
	void shoot();//ctreliet
	void setColor(sf::Color c);//ustanavlyvaet chvet geroya
	void reload();//perezarezaut
	void kick();//biet
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;//resuet geroya
	void move();//dvigaetcya
};

