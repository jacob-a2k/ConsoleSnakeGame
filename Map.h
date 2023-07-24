#ifndef MAP_H
#define MAP_H
#include "Point.h"

class Map {
	char gameMap[30][120];
public:
	Map();
	void printMap()const;
	void setSignInGameMap(Point* food);
	char getSignFromGameMap(int posY, int posX) { return gameMap[posY][posX]; }
	void clearTail(int y, int x,char sign);
};

#endif //MAP_H