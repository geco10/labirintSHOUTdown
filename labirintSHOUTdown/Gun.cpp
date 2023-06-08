#include "Gun.h"

Gun::Gun(const sf::Vector2f* pos,const float *len, const float* dir)
{
	this->pos = pos;
	this->len = len;
	this->dir = dir;
}
void Gun::tick(float delta) {
	
}

