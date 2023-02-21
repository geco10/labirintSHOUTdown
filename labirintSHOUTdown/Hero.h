#pragma once
#include"Gun.h"
#include<vector>
#include "Map.h"
#include<SFML/Graphics.hpp>
#include"enumHero.h"
#include"EnumAction.h"

class Hero :public sf::Drawable{
	float radius = 0.43;//radius
	int live;//zizny
	float dir;//napravlenya
	int id;//porydkovi nomer
	sf::Vector2f pos;//positia
	ShapeType type; //type formi
	int kD;
	float speed=0.2;
	sf::Color color;
	Gun* gun;
	Map* map;
	sf::Shape* shape;
	std::map<HeroAction,bool> keyPressed;
	std::vector<HeroAction> doAction;
	void performMoveAction(float delta);
	void performDoAction(float delta);
	void download(const char* path);
	void initShape();
public:
	void setMap(Map* map);//ustanavlivaet ukazatel map
	Hero(Map* map,const char* path);//konstrucktor
	void shoot();//ctreliet
	void setColor(sf::Color c);//ustanavlyvaet chvet geroya
	void reload();//perezarezaut
	void kick();//biet
	void tick(float delta);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;//resuet geroya
	void addAction(HeroAction event, bool isPressed=true);//dvigaetcya
};

