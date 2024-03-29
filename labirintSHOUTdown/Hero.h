#pragma once
#include"Gun.h"
#include"Pistol.h"
#include"CircleColison.h"
#include<vector>
#include "Map.h"
#include<SFML/Graphics.hpp>
#include"enumHero.h"
#include"EnumAction.h"

class Hero :public MyDrawable,public CircleColison,public Tickable{
	int live;//zizny
	float dir;//napravlenya
	int id;//porydkovi nomer
	ShapeType type; //type formi
	int kD;
	float speed=0.5;
	sf::Color color;
	Gun* gun;
	sf::Shape* shape;
	std::map<HeroAction,bool> keyPressed;
	void performMoveAction(float delta);
	void performDoAction(float delta);
	void download(const char* path);
	void initShape();
public:
	Hero(const char* path);//konstrucktor
	void shoot();//ctreliet
	void setColor(sf::Color c);//ustanavlyvaet chvet geroya
	void reload();//perezarezaut
	void kick();//biet
	virtual void tick(float delta)override;
	~Hero();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;//resuet geroya
	void addAction(HeroAction event, bool isPressed=true);//dvigaetcya
};

