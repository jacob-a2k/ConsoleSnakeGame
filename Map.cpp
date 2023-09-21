#include <iostream>
#include "Map.h"

Map::Map(int height, int width) : height(height), width(width) {
	gameMap = new char* [height];
	for (int i = 0; i < height; i++) {
		gameMap[i] = new char[width];
	}
	fillMap();
}
void Map::printMap() const {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			std::cout << gameMap[i][j];
		}
		std::cout << '\n';
	}
}
void Map::setSignInGameMap(const Point& point, char sign) {
	gameMap[point.getY()][point.getX()] = sign;
}
void Map::fillMap() {
	gameMap[0][0] = '+';
	for (int i = 1; i < width -1; ++i) {
		gameMap[0][i] = '-';
	}
	gameMap[0][width -1] = '+';
	for (int j = 1; j < height -1; ++j) {
		gameMap[j][0] = '|';
		for (int i = 1; i < width -1; ++i) {
			gameMap[j][i] = ' ';
		}
		gameMap[j][width-1] = '|';
	}
	gameMap[height - 1][0] = '+';
	for (int i = 1; i < width-1; ++i) {
		gameMap[height - 1][i] = '-';
	}
	gameMap[height - 1][width-1] = '+';
}