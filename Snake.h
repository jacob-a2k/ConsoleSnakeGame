#ifndef SNAKE_H
#define SNAKE_H
#include "PartOfSnake.h"

class Snake {
	int size;
	int speed;
	PartOfSnake* head;
	void increaseSnakeSpeed() { speed = speed / 2; }

public:
	Snake(int size = 1, int speed = 100) : size(size), speed(speed) { 
		Point headPosition(10, 10);
		head = new PartOfSnake(headPosition);
	}
	PartOfSnake* getHead() const { return head; }
	void setHead(PartOfSnake* newHead) { head = newHead; }
	void increase(const Point& position) {
		PartOfSnake* tmp = head;
		PartOfSnake* newPartOfSnake = new PartOfSnake(position, head);
		head = newPartOfSnake;
		if (size % 5 == 0) {
			increaseSnakeSpeed();
		}
	}
	int getSnakeSize() const { return size; }
	int getSnakeSpeed() const { return speed; }
};

#endif //SNAKE-h
