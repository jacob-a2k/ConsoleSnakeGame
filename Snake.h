#ifndef SNAKE_H
#define SNAKE_H
#include "PartOfSnake.h"

class Snake {
	int snakeSize;
	int snakeSpeed;
	PartOfSnake* head;

public:
	Snake(int size = 1, int speed = 100) : snakeSize(size), snakeSpeed(speed) { 
		MapPoint headPosition(10, 10);
		head = new PartOfSnake(headPosition);
	}
	PartOfSnake* getHead() const { return head; }
	void setHead(PartOfSnake* newHead) { head = newHead; }
	void increaseSnakeSize() { snakeSize++; }
	int getSnakeSize() const { return snakeSize; }
	void increaseSnakeSpeed() { snakeSpeed = snakeSpeed / 2; }
	int getSnakeSpeed() const { return snakeSpeed; }
};

#endif //SNAKE-h
