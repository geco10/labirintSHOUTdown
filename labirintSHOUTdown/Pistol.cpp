#include "Pistol.h"

Pistol::Pistol(const sf::Vector2f* pos,const float *len,const float *dir) :Gun(pos,len,dir)
{
	
}

void Pistol::reload()
{
}

void Pistol::shoot()
{
}

void Pistol::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Vector2f center = sf::Vector2f(pos->x + 0.43, pos->y + 0.43);
	sf::RectangleShape gun(sf::Vector2f(3, -10));
	gun.setFillColor(sf::Color::Black);
	gun.setPosition(sf::Vector2f((*len)*center.x-4,( * len)*center.y-5));
	//gun.setOrigin(center * *len);
	gun.setRotation(*dir);
	target.draw(gun);
}
