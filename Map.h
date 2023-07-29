#ifndef MAP_H
#define MAP_H
#include "MapPoint.h"

class Map {
	char gameMap[30][120];
public:
	Map();
	void printMap()const;
	void setSignInGameMap(const MapPoint & point, char sign);
	char getSignFromGameMap(const MapPoint & point) { return gameMap[point.getY()][point.getX()]; }
};

#endif //MAP_H