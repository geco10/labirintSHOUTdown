#include <SFML/Graphics.hpp>
#include"Map.h"
#include"Hero.h"
#include"ControlHero.h"
int main()
{
	sf::Vector2f size(900, 900);
	Map map("./Maps/Test_Map.txt", size);
	/*Hero hero(&map,"./Hero/triangle.txt");
	hero.setColor(sf::Color::Blue);
	Hero hero2(&map,"./Hero/circle.txt");
	hero2.setColor(sf::Color::Green);*/
	ControlHero heros(&map);
	heros.createHero("./Hero/triangle.txt");
	heros.createHero("./Hero/circle.txt");
	sf::RenderWindow window(sf::VideoMode(size.x,size.y), "Lesson 2. kychka-pc.ru");
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				heros.keyPressed(event.key.code);
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		heros.tick(1);
		window.clear();
		window.draw(map);
		window.draw(heros);
		window.display();
	}

	return 0;
}