#pragma once
#include<SFML/Graphics.hpp>
#include"Tickable.h"
#include"MyDrawable.h"
class Bullet :public MyDrawable ,public Tickable{
    float dir;
	sf::Vector2f pos;
	bool vis;
	int damage;
	float speed;
	float len;
	int range;
	float radius;
public:
	~Bullet();
	static Bullet* create_bullet(float len, float speed, float dir, int damage, sf::Vector2f pos, int range, float bul_radius, bool vis);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
private:
	virtual void tick(float delta)override;	
	void move(float delta);
	Bullet(float len,float speed, float dir, int damage, sf::Vector2f pos, int range, float bul_radius, bool vis);
};

