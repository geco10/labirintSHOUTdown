#pragma once
#include<SFML/Graphics.hpp>
#include"Tickable.h"
#include"CircleColison.h"
#include"MyDrawable.h"
class Bullet :public MyDrawable ,public Tickable,public CircleColison{
    float dir;
	bool vis;
	int damage;
	float speed;
	float len;
	int range;
public:
	~Bullet();
	static Bullet* create_bullet(float len, float speed, float dir, int damage, sf::Vector2f pos, int range, float bul_radius, bool vis);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
private:
	virtual void tick(float delta)override;	
	void move(float delta);
	Bullet(float len,float speed, float dir, int damage, sf::Vector2f pos, int range, float bul_radius, bool vis);
};

