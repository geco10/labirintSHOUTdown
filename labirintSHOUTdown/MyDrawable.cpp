#include"MyDrawable.h"

MyDrawable::MyDrawable() {
	objects.push_back(this);
}
MyDrawable::~MyDrawable() {
	int i = 0;
	for (; objects[i] != this; i++);
	objects.erase(objects.begin() + i);
}
void MyDrawable::super_draw(sf::RenderWindow& window) {
	for (MyDrawable* res : objects) {
		window.draw(*res);
	}
}
std::vector<MyDrawable*> MyDrawable::objects={ };