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
	float len;
	char map[500][500];
	size_t n=0, m=0;
public:
	int getLen()const;
	Map(const char* path,sf::Vector2f size);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void download(const char* path);
};

