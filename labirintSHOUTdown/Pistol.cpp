#include "Pistol.h"

Pistol::Pistol(const sf::Vector2f* pos,const float *len,const float *dir) :Gun(pos,len,dir)
{
	vis = true;
	this->len = len;
	mC = 10;
	shootMon.setTime(0.5);
	reloadMon.setTime(1.5);
	speed = 5;
	bul_radius = 1/ *len;//bullet radius
	bc = mC;
	this->dir = dir;
	this->pos = pos;//ukazatel na top left conner of hero;
	damage = 50;
	range = 15;
}
void Pistol::reload()
{
	bc = mC;
	reloadMon.restart();
}

void Pistol::shoot()
{
	if (shootMon.isTime() && reloadMon.isTime()&& bc>0) {
		Bullet::create_bullet(*len, speed, *dir, damage, *pos + sf::Vector2f(0.43, 0.43), range, bul_radius, vis);
		--bc;
		shootMon.restart();
    }
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
