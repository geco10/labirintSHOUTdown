#include "Hero.h"
#include"VectorFunctions.h"
#pragma warning(disable:4996)
 static size_t last_id=0;
 extern Map* map;
Hero::Hero(const char* path) {
	radius = 0.43;
	download(path);
	dir = 0;
	id = last_id++;
	pos = map->getSpawns()[id];
	pos.x += (1 - radius * 2) / 2;
	pos.y += (1 - radius * 2) / 2;
	initShape();
}
void Hero::shoot()
{
	gun->shoot();
}
void Hero::reload()
{
	gun->reload();
}
void Hero::performMoveAction(float delta)
{
	float dis = delta*speed;
	sf::Vector2f step = { 0,0 };
	step.x += keyPressed[HeroAction::MOVE_RIGHT];
	step.x -= keyPressed[HeroAction::MOVE_LEFT];

	step.y -= keyPressed[HeroAction::MOVE_UP];
	step.y += keyPressed[HeroAction::MOVE_DOWN];
	dir += keyPressed[HeroAction::TURN_LEFT]*0.2;
	dir -= keyPressed[HeroAction::TURN_RIGHT] * 0.2;
	step=vec::normalize(step);
	step.x *= dis;
	step.y *= dis;
	if((step.x!=0||step.y!=0)&&WallColison(step)==true&&!objectColison(step))
	  pos += step;
}
void Hero::performDoAction(float delta)
{
	if (keyPressed[HeroAction::SHOOT])
		shoot();
	if (keyPressed[HeroAction::RELOAD])
		reload();
}
void Hero::download(const char* path){
	gun = new Pistol(&pos,map->getLenPointer(),&dir);
	FILE* file;
	file=fopen(path,"r");
	if (file == NULL) {
		throw - 13;
	}
	fscanf(file,"%i",&live);
	fscanf(file,"%i",&kD);
	fscanf(file,"%i",&type);
	fscanf(file, "%f", &speed);

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



void Hero::tick(float delta)
{
	performMoveAction(delta);
	performDoAction(delta);
}

void Hero::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	shape->setPosition(sf::Vector2f(pos.x * map->getLen(), pos.y * map->getLen()));
	shape->setFillColor(color);
	target.draw(*shape);
    target.draw(*gun);

}

Hero::~Hero() {
	delete gun;
}

void Hero::addAction(HeroAction event, bool isPressed){
	keyPressed[event]=isPressed;
}
