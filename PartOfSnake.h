#include "Point.h"
#ifndef PART_OF_SNAKE_H
#define PART_OF_SNAKE_H

class PartOfSnake
{
	Point position;
	PartOfSnake* nextPart;
public:
	PartOfSnake(const Point& position);
	PartOfSnake(const Point& position, PartOfSnake* nextPart);
	Point getPosition() const;
	void setPosition(const Point& postion);
	PartOfSnake* getNext();
};

#endif // PART_OF_SNAKE_H

