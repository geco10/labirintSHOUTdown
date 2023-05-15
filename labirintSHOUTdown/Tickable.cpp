#include"Tickable.h"

Tickable::Tickable() {
	objects.insert(this);
}
Tickable::~Tickable() {
	objects.erase(this);
}
void Tickable::super_tick(float delta) {
	for (Tickable* cur:objects)
	{
		cur->tick(delta);
	}
}