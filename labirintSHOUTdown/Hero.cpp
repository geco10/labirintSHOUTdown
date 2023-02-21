#include "Hero.h"
#pragma warning(disable:4996)
 static size_t last_id=0;
Hero::Hero(Map* map,const char* path) {
	download(path);
	dir = 0;
	float speed;
	id = last_id++;
	this->map = map;
	pos = map->getSpawns()[id];
	pos.x += (1 - radius * 2) / 2;
	pos.y += (1 - radius * 2) / 2;
	initShape();
}
void Hero::performMoveAction(float delta)
{
	sf::Vector2f step = {0,0};
	step.x += keyPressed[HeroAction::MOVE_RIGHT];
	step.x -= keyPressed[HeroAction::MOVE_LEFT];

	step.y -= keyPressed[HeroAction::MOVE_UP];
	step.y +h= keyPressed[HeroAction::MOVE_DOWN];
	pos.x += step.x/50.0;
	pos.y += step.y / 50.0;
}
void Hero::performDoAction(float delta)
{
	printf("%i do", id);
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
void Hero::initShape()
{
	if (type == ShapeType::Circle) {
		shape=new sf::CircleShape(map->getLen() * radius);
	}
	if (type == ShapeType::Triangle) {
		shape=new sf::CircleShape(map->getLen() * radius, 3);
	}
	if (type == ShapeType::Square) {
		//shape=new sf::RectangleShape(sf::Vector2f(len,len));
	}
}
void Hero::setColor(sf::Color c)

{
	color = c;
}

void Hero::setMap(Map* map){
	this->map = map;
}

void Hero::tick(float delta)
{
	performMoveAction(delta);
	performDoAction(delta);
	doAction.clear();
}

void Hero::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	shape->setPosition(sf::Vector2f(pos.x * map->getLen(), pos.y * map->getLen()));
	shape->setFillColor(color);
	target.draw(*shape);
}

void Hero::addAction(HeroAction event, bool isPressed){
	if (event >= HeroAction::MOVE_UP && event <= HeroAction::MOVE_RIGHT) {
		keyPressed[event]=isPressed;
	}
	else
		doAction.push_back(event);
}
