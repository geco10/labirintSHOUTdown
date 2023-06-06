#pragma once
#include<set>
#include<SFML/Graphics.hpp>
class MyDrawable :public sf::Drawable{
	static std::set<MyDrawable*> objects;
public:
	MyDrawable();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	static void super_draw(sf::RenderWindow& window);
	~MyDrawable();
};