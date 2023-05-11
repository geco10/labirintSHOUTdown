#include "Pistol.h"

Pistol::Pistol(const sf::Vector2f* pos,const float *len,const float *dir) :Gun(pos,len,dir)
{
	vis = false;
	this->len = len;
	mC = 10;
	speed = 5;
	bul_radius = 1/ *len;//bullet radius
	bc = mC;
	this->dir = dir;
	this->pos = pos;
	damage = 50;
	range = 15;
}

void Pistol::reload()
{
}

void Pistol::shoot()
{
	Bullet bullet(speed,*dir,damage,*pos,range,bul_radius,vis);
	--bc;
}

void Pistol::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Vector2f center = sf::Vector2f(pos->x + 0.43, pos->y + 0.43);
	sf::RectangleShape gun(sf::Vector2f(3, -10));
	gun.setFillColor(sf::Color::Black);
	gun.setPosition(center**len);
	gun.setOrigin(2, 5);
	gun.setRotation(*dir);
	target.draw(gun);
}
