#ifndef POINT_H
#define POINT_H
class Point
{
	int x;
	int y;
public:
	Point(int y, int x);
	Point();
	int getX() const { return x; }
	int getY() const { return y; }
	bool operator==(const Point& other);
};
#endif //MAP_POINT_H