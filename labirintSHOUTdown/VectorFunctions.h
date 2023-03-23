#pragma once
#define _USE_MATH_DEFINES
#include<SFML/Graphics.hpp>
#include"Map.h"
#include<cmath>
namespace vec {
	float len(sf::Vector2f a);
	sf::Vector2f normalize(sf::Vector2f a);
	sf::Vector2f xyToLenfi(sf::Vector2f xy_v);
	sf::Vector2f lenfiToXy(sf::Vector2f lenfi_v);
	sf::Vector2f pointFrame(sf::Vector2f pos);
}