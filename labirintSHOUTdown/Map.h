#pragma once
/* #-wall stena
* @-hero geroy
* |-movable wall is bullet proof
* t-tnt vzrivchatcka
* b-bots
* +-armed veichl
*/
#include<string>
#include"MyDrawable.h"
#include<SFML/Graphics.hpp>
class Map :public MyDrawable
{
	static float len;//mashtab
	static char map[500][500];//karta
	static std::vector<sf::Vector2f> spawns;//spavny
	static size_t n=0, m=0; //razmernost karti
	static void download(const char* path);//zagruzaet kartu
	static void findSpawns();//naxodyt cpavni
public:
	static char getFrame(sf::Vector2f fpos);
	static const std::vector<sf::Vector2f>& getSpawns();//vozvrashaet spavni
	static float getLen();//vozvroshaet mashtab
	static const float* getLenPointer();
	static sf::Vector2f getSize();// vozvroshaet razmer
	Map(const char* path,sf::Vector2f size);//konstruktor
	static virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;//risuet kartu
};

