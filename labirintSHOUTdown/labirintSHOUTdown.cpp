#include <SFML/Graphics.hpp>
#include"Map.h"
#include"Hero.h"
int main()
{
	sf::Vector2f size(900, 900);
	Map map("./Maps/Test_Map.txt", size);
	Hero hero;
	hero.setColor(sf::Color::Blue);
	hero.setMap(&map);
	sf::RenderWindow window(sf::VideoMode(size.x,size.y), "Lesson 2. kychka-pc.ru");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Red);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(map);
		window.draw(hero);
		window.display();
	}

	return 0;
}