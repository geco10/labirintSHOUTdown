#include "Pistol.h"

Pistol::Pistol(sf::Vector2f* pos,const float *len) :Gun(pos,len)
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
	sf::RectangleShape gun(sf::Vector2f(3, 10));
	gun.setFillColor(sf::Color::Black);
	gun.setPosition(sf::Vector2f(pos->x**len,pos->y**len));
	gun.setRotation(0);
	target.draw(gun);
}
