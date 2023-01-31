#pragma once
/* #-wall stena
* @-hero geroy
* |-movable wall is bullet proof
* t-tnt vzrivchatcka
* b-bots
* +-armed veichl
*/
#include<string>
#include<SFML/Graphics.hpp>
class Map :public sf::Drawable
{
	float len;
	char map[500][500];
	std::vector<sf::Vector2f> spawns;
	size_t n=0, m=0;
	void download(const char* path);
	void findSpawns();
public:
	std::vector<sf::Vector2f> getSpawns();
	float getLen()const;
	sf::Vector2f getSize();
	Map(const char* path,sf::Vector2f size);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

