#include "Bullet.h"
#include"CircleColison.h"
#include"Vectorfunctions.h"
Bullet::Bullet(float speed, int dir, int damage, sf::Vector2f pos, int range, float bul_radius, bool vis) {
	this->dir = dir;
	this->damage = damage;
	this->pos=pos;
	this->range = range;
	radius = 5;
	this->speed = speed;
	this->vis = vis;
}
void Bullet::move(float delta) {
	float step = speed * delta;
	pos =pos+ vec::lenfiToXy(sf::Vector2f(step,dir));
}
void Bullet::tick(float delta) {
	move(delta);
}
void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	if (vis) {
		sf::RectangleShape bullet(sf::Vector2f(radius, radius));
		bullet.setFillColor(sf::Color::Black);
		bullet.setRotation(dir);
		bullet.setPosition(pos);
		target.draw(bullet);
	}
}