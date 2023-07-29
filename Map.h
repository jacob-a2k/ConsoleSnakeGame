#ifndef MAP_H
#define MAP_H
#include "Point.h"

class Map {
	char gameMap[30][120];
public:
	Map();
	void printMap()const;
	void setSignInGameMap(const Point & point, char sign);
	char getSignFromGameMap(const Point & point) { return gameMap[point.getY()][point.getX()]; }
};

#endif //MAP_H