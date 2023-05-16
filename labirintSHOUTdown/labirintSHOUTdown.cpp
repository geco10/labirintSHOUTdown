#include <SFML/Graphics.hpp>
#include"Map.h"
#include"Tickable.h"
#include"Hero.h"
#include"ControlHero.h"
#include<Windows.h>
size_t toMilliseconds(SYSTEMTIME time) {
	return time.wHour * 3600000 + time.wMinute * 60000 + time.wSecond * 1000 + time.wMilliseconds;
}
int main()
{
	SYSTEMTIME time;
	GetLocalTime(&time);
	sf::Vector2f size(900, 900);
	Map map("./Maps/Test_Map.txt", size);
	ControlHero heros(&map);
	heros.createHero("./Hero/triangle.txt");
	heros.createHero("./Hero/circle.txt");
	sf::RenderWindow window(sf::VideoMode(size.x,size.y), "Lesson 2. kychka-pc.ru");
	window.setKeyRepeatEnabled(false);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				heros.keyPressed(event.key.code);
			}else
			if (event.type == sf::Event::KeyReleased)
			{
				heros.keyPressed(event.key.code,false);
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}
		SYSTEMTIME time1;
		GetLocalTime(&time1);
		int delta = toMilliseconds(time1) - toMilliseconds(time);
		time = time1;
		Tickable::super_tick(delta / 1000.f);
		heros.tick(delta/1000.f);
		window.clear();
		window.draw(map);
		window.draw(heros);
		window.display();
	}

	return 0;
}