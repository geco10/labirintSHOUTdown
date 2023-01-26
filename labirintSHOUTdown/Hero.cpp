#include "Hero.h"

void Hero::setMap(Map* map){
	this->map = map;
}

void Hero::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	if (type == ShapeType::Circle) {
		sf::CircleShape circle(map->getLen());
		circle.setPosition(sf::Vector2f(pos.x * map->getLen(), pos.y * map->getLen()));
		circle.setFillColor(color);
		target.draw(circle);
	}
	if (type == ShapeType::Triangle) {
		sf::CircleShape triangle(map->getLen(),3);
		triangle.setPosition(sf::Vector2f(pos.x * map->getLen(), pos.y * map->getLen()));
		triangle.setFillColor(color);
		target.draw(triangle);
	}
	if (type == ShapeType::Square) {
		sf::RectangleShape square(sf::Vector2f(len));
		square.setPosition(sf::Vector2f(pos.x * map->getLen(), pos.y * map->getLen()));
		square.setFillColor(color);
		target.draw(square);
	}
}
