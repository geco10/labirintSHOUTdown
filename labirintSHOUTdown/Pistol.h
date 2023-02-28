#pragma once
#include"Gun.h"
class Pistol :public Gun{
public:
	Pistol(const sf::Vector2f *pos,const float *lenws);
	virtual void reload();
	virtual void shoot();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
};

