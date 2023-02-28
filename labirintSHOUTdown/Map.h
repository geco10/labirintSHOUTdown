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
	float len;//mashtab
	char map[500][500];//karta
	std::vector<sf::Vector2f> spawns;//spavny
	size_t n=0, m=0; //razmernost karti
	void download(const char* path);//zagruzaet kartu
	void findSpawns();//naxodyt cpavni
public:
	const std::vector<sf::Vector2f>& getSpawns();//vozvrashaet spavni
	float getLen()const;//vozvroshaet mashtab
	const float* getLenPointer()const;
	sf::Vector2f getSize();// vozvroshaet razmer
	Map(const char* path,sf::Vector2f size);//konstruktor
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;//risuet kartu
};

