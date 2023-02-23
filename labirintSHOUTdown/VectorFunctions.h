#pragma once
#include<SFML/Graphics.hpp>
#include<cmath>
namespace vec {
	float len(sf::Vector2f a);
	sf::Vector2f normalize(sf::Vector2f a);
}