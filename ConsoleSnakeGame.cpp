#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Point.h"
#include "Snake.h"
#include "Map.h"

bool isUserChooseCorrectDirection(char chosenDirection, char actualDirection);
bool isEmptyLocationForFood(Map map, int y, int x);
bool isUserChoseCorectSign(char dir);
bool isNextPositionEmpty(Map map, int y, int x);
void setFoodInNewLocation(Map* map,Point* food);

int main() {

	Snake snake;
	Map map;

	bool error = false;
	int XposBeforeLoop;
	int YposBeforeLoop;
	int prevPosX;
	int prevPosY;

	srand(time(NULL));
	Point* food = new Point;
	setFoodInNewLocation(&map,food);

	char actualDirection = 'd';
	char chosenDirection = actualDirection;
	int nextXpos = 10;
	int nextYpos = 10;
	while (!error) {
		if (_kbhit()) {
			chosenDirection = _getch();
		}
		if (isUserChooseCorrectDirection(chosenDirection, actualDirection)) {
			switch (chosenDirection) {
			case 'd':
				nextXpos++;
				break;
			case 's':
				nextYpos++;
				break;
			case 'w':
				nextYpos--;
				break;
			case 'a':
				nextXpos--;
				break;
			default:
				std::cout << "Something goes wrong!!!" << std::endl;
				Sleep(1000);
				error = true;
			}
			actualDirection = chosenDirection;
		}
		else {
			chosenDirection = actualDirection;
			continue;
		}
		XposBeforeLoop = nextXpos;
		YposBeforeLoop = nextYpos;

		if (isNextPositionEmpty(map, nextYpos, nextXpos)) {
			error = true;
			map.printMap();
			std::cout << "\n\n\n";
			std::cout << "--------GAME OVER--------";
			Sleep(4000);
			continue;
		}
		if (map.getSignFromGameMap(nextYpos, nextXpos) == food->getSign()) {
			snake.increaseSnakeSize();
			if (snake.getSnakeSize() % 5 == 0) {
				snake.increaseSnakeSpeed();
			}
			Point* newPartOfSnake = new Point(snake.getHead(), nextYpos, nextXpos);
			snake.setHead(newPartOfSnake);

			setFoodInNewLocation(&map,food);
		}
		Point* current = snake.getHead();

		while (current != nullptr) {
			prevPosX = current->getX();
			prevPosY = current->getY();
			current->setX(nextXpos);
			current->setY(nextYpos);
			map.setSignInGameMap(current);
			nextXpos = prevPosX;
			nextYpos = prevPosY;
			current = current->getNext();
		}
		map.clearTail(prevPosY, prevPosX, ' ');
		delete current;
		nextXpos = XposBeforeLoop;
		nextYpos = YposBeforeLoop;

		map.printMap();
		Sleep(snake.getSnakeSpeed());
		system("cls");
	}
}
bool isUserChooseCorrectDirection(char chosenDirection, char actualDirection) {
	if (isUserChoseCorectSign(chosenDirection)) {
		if (actualDirection == 'd' && chosenDirection == 'a' ||
			actualDirection == 'a' && chosenDirection == 'd' ||
			actualDirection == 's' && chosenDirection == 'w' ||
			actualDirection == 'w' && chosenDirection == 's') {
			return false;
		}
		return true;
	}
	return false;
}
bool isEmptyLocationForFood(Map* map, int y, int x) {
	if (map->getSignFromGameMap(y, x) == ' ') {
		return true;
	}
	return false;
}
bool isNextPositionEmpty(Map map, int y, int x) {
	if (map.getSignFromGameMap(y, x) == '|' || map.getSignFromGameMap(y, x) == '-' ||
		map.getSignFromGameMap(y, x) == 'o') {
		return true;
	}
	return false;
}
bool isUserChoseCorectSign(char dir) {
	if (dir == 'a' || dir == 's' || dir == 'd' || dir == 'w') {
		return true;
	}
	return false;
}
void setFoodInNewLocation(Map* map,Point* food) {
	int randomRow = rand() % 29 + 1;
	int randomColumn = rand() % 119 + 1;
	while (!isEmptyLocationForFood(map, randomRow, randomColumn)) {
		randomRow = rand() % 29 + 1;
		randomColumn = rand() % 119 + 1;
	}
	food->setY(randomRow);
	food->setX(randomColumn);
	food->setSign('x');
	map->setSignInGameMap(food);
}