#pragma once
#include<set>
class Tickable {
	static std::set<Tickable*> objects;
public:
	Tickable();
	virtual void tick(float delta)=0;
	static void super_tick(float delta);
	~Tickable();
};