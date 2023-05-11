#include "Bullet.h"
#include"CircleColison.h"
#include"Vectorfunctions.h"
Bullet::Bullet(const int* dir, int damage, float speed, const sf::Vector2f* pos, int range, int bul_radius, bool vis) {
	this->dir = *dir;
	this->damage = damage;
	this->pos=*pos;
	this->range = range;
	radius = bul_radius;
	this->vis = vis;
}
void Bullet::move(float delta) {
	float step = speed * delta;
	pos =pos+ vec::lenfiToXy(sf::Vector2f(step,dir));
}