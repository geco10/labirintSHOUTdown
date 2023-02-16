#pragma once
#include<SFML/Graphics.hpp>
#include"Hero.h"
#include"Map.h"

class ControlHero :public sf::Drawable {
	Map* map;//karta
	sf::Color color[4];//masiv chevtov
	std::vector<Hero*> heros;//masiv ukasateley
	void initColor();
public:
	ControlHero(Map* map);//konstruktor
	void tick(float delta);
	void keyPressed(sf::Keyboard::Key key);
	Hero* createHero(const char*path);//sozdaet geroev
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;//rysuet
	~ControlHero();
};

