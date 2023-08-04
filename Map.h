#ifndef MAP_H
#define MAP_H
#include "Point.h"

class Map {
	//char gameMap[30][120];
	char** gameMap;
	int width;
	int height;
	void fillMap();
public:
	Map(int height = 10, int width = 10);
	void printMap()const;
	void setSignInGameMap(const Point& point, char sign);
	char getSignFromGameMap(const Point& point) { return gameMap[point.getY()][point.getX()]; }
};

#endif //MAP_H