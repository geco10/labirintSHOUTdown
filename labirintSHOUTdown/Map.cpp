#include "Map.h"

Map::Map(const char* path, sf::Vector2f size){
	download(path);
}

void Map::download(const char* path)
{
	FILE* file;
	file = fopen(path, "r");
	if (file==NULL) {
		throw - 13;
	}
	while (fgets(map[n++], 500, file) != NULL);
	strlen(map[0]);
	fclose(file);
}
