#include "Bullet.h"
#include"Vectorfunctions.h"
Bullet::Bullet(float len,float speed, float dir, int damage, sf::Vector2f pos, int range, float bul_radius, bool vis) {
	this->dir = (dir-90) / 57.2957795;
	this->damage = damage;
	this->pos=pos;
	this->len = len;
	this->range = range;
	radius = 5;
	this->speed = speed;
	this->vis = vis;
}
void Bullet::move(float delta) {
	float step = speed * delta;
	sf::Vector2f a = vec::lenfiToXy(sf::Vector2f(step, dir));
	if(WallColison(a) == true)
	  pos =pos+ a;
}
Bullet* Bullet::create_bullet(float len, float speed, float dir, int damage, sf::Vector2f pos, int range, float bul_radius, bool vis) {
	return new Bullet(len,speed,dir,damage, pos, range, bul_radius, vis);
}
Bullet::~Bullet() {
	delete this;
}
void Bullet::tick(float delta) {
	move(delta);
}
void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	if (vis) {
		sf::RectangleShape bullet(sf::Vector2f(radius, radius));
		bullet.setFillColor(sf::Color::Black);
		bullet.setRotation(dir);
		bullet.setPosition(pos * len);
		target.draw(bullet);
	}
}