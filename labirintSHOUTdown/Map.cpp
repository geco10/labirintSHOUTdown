#include "Map.h"

Map::Map(const char* path, sf::Vector2f size){
	download(path);
	len = size.x/n;
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '#') {
				
			}
		}
	}
}
//void Map:: draw(sf::RenderTarget& target, sf::RenderStates states) {
	
//}
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
