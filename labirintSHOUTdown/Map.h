#pragma once
/* #-wall stena
* @-hero geroy
* |-movable wall is bullet proof
* t-tnt vzrivchatcka
* b-bots
* +-armed veichl
*/
#include<string>
#include<SFML/Graphics/Drawable.hpp>
class Map :public sf::Drawable
{
	int len;
	char map[500][500];
	size_t n, m;
public:
	Map(const char* path,sf::Vector2f size);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	void download(const char* path);
};

