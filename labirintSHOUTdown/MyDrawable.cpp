#include"MyDrawable.h"

MyDrawable::MyDrawable() {
	objects.insert(this);
}
MyDrawable::~MyDrawable() {
	objects.erase(this);
}
void MyDrawable::super_draw(sf::RenderWindow& window) {
	for (MyDrawable* res : objects) {
		window.draw(*res);
	}
}
std::set<MyDrawable*> MyDrawable::objects={ };