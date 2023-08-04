#include "Point.h"

Point::Point() : y(0), x(0) {}

Point::Point(int y, int x) {
	this->y = y;
	this->x = x;
}

bool Point::operator==(const Point& other) {
	return x == other.x && y == other.y;
}
/*
MapPoint& MapPoint::operator=(const MapPoint& other) {
	return *this;
}

MapPoint::MapPoint(const MapPoint& other) : MapPoint(other.y, other.x)
{
}
*/