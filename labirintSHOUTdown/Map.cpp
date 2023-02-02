#pragma warning(disable:4996)
#include "Map.h"
#include<SFML/Graphics.hpp>
float Map::getLen()const
{
	return len;
}
sf::Vector2f Map::getSize()
{
	return sf::Vector2f(m,n);
}
Map::Map(const char* path, sf::Vector2f size){
	download(path);
	float ky = size.y / n;
	float kx = size.x / m;
	if (ky > kx)len = kx;
	else len = ky;
	findSpawns();
}
void Map::findSpawns() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
			if (map[i][j] == '@') {
				spawns.push_back(sf::Vector2f(j, i));
				map[i][j] = ' ';
			}
		}
	}
}
void Map:: draw(sf::RenderTarget& target, sf::RenderStates states)const {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (map[y][x] == '#') {
				sf::RectangleShape wall(sf::Vector2f(len, len));
				wall.setFillColor(sf::Color(255, 255, 240));
				wall.setPosition(sf::Vector2f(x * len, y * len));
				target.draw(wall);
			}
			if (map[y][x] == '@') {

			}
			if (map[y][x] == '|') {
				/*sf::RectangleShape door(sf::Vector2f(len,4/len));
				door.setPosition(sf::Vector2f(x * len,y * len));
				door.setPosition(map[]);
				if(map[y][x+1]=='#')*/
			}
		}
	}
}
const std::vector<sf::Vector2f>& Map::getSpawns() {
	return spawns;
}
void Map::download(const char* path)
{
	FILE* file;
	file = fopen(path, "r");
	if (file==NULL) {
		throw - 13;
	}
	while (fgets(map[n++], 500, file) != NULL)puts(map[n-1]);
	--n;
	m=strlen(map[0])-1;
	fclose(file);

}
