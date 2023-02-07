#include "Hero.h"
#pragma warning(disable:4996)
 static size_t last_id=0;
Hero::Hero(Map* map,const char* path) {
	download(path);
	dir = UP;
	id = last_id++;
	this->map = map;
	pos = map->getSpawns()[id];
	pos.x += (1 - radius * 2) / 2;
	pos.y += (1 - radius * 2) / 2;
}
void Hero::download(const char* path){
	FILE* file;
	file=fopen(path,"r");
	if (file == NULL) {
		throw - 13;
	}
	fscanf(file,"%i",&live);
	fscanf(file,"%i",&kD);
	fscanf(file,"%i",&type);
	fclose(file);
}
void Hero::setColor(sf::Color c)

{
	color = c;
}

void Hero::setMap(Map* map){
	this->map = map;
}

void Hero::draw(sf::RenderTarget& target, sf::RenderStates states) const{

	if (type == ShapeType::Circle) {
		sf::CircleShape circle(map->getLen() * radius);
		circle.setPosition(sf::Vector2f(pos.x * map->getLen(), pos.y * map->getLen()));
		circle.setFillColor(color);
		target.draw(circle);
	}
	if (type == ShapeType::Triangle) {
		sf::CircleShape triangle(map->getLen() * radius, 3);
		triangle.setPosition(sf::Vector2f(pos.x * map->getLen(), pos.y * map->getLen()));
		triangle.setFillColor(color);
		target.draw(triangle);
	}
	if (type == ShapeType::Square) {
		/*sf::RectangleShape square(sf::Vector2f(len,len));
		square.setPosition(sf::Vector2f(pos.x * map->getLen(), pos.y * map->getLen()));
		square.setFillColor(color);
		target.draw(square);*/
	}
}
