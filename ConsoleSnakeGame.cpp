#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Snake.h"
#include "Map.h"

bool isUserChooseCorrectDirection(char chosenDirection, char actualDirection);
bool isEmptyLocationForFood(Map map, const Point & point);
bool isUserChoseCorectSign(char dir);
bool isNextPositionEmpty(Map map, const Point& point);
Point getNextPositionForFood(Map* map);

int main() {

	Snake snake;
	Map map;
	bool error = false;
	Point positionBeforeLoop(0, 0);
	Point prevPosition(0, 0);

	srand(time(NULL));

	Point foodPosition = getNextPositionForFood(&map);
	map.setSignInGameMap(foodPosition, 'x');

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
		Point nextPosition(nextYpos, nextXpos);
		positionBeforeLoop = nextPosition;

		if (isNextPositionEmpty(map, nextPosition)) {
			error = true;
			map.printMap();
			std::cout << "\n\n\n";
			std::cout << "--------GAME OVER--------";
			Sleep(4000);
			continue;
		}
		if (nextPosition == foodPosition) {
			snake.increase(nextPosition);
			foodPosition = getNextPositionForFood(&map);
			map.setSignInGameMap(foodPosition, 'x');
		}
		PartOfSnake* current = snake.getHead();

		while (current != nullptr) {
			prevPosition = current->getPosition();
			current->setPosition(nextPosition);
			Point position = current->getPosition();
			map.setSignInGameMap(position,'o');
			nextPosition = prevPosition;
			current = current->getNext();
		}

		map.setSignInGameMap(prevPosition,' ');

		delete current;
		nextPosition = positionBeforeLoop;

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
bool isEmptyLocationForFood(Map* map, Point& point) {
	if (map->getSignFromGameMap(point) == ' ') {
		return true;
	}
	return false;
}
bool isNextPositionEmpty(Map map, const Point& point) {
	if (map.getSignFromGameMap(point) == '|' || map.getSignFromGameMap(point) == '-' ||
		map.getSignFromGameMap(point) == 'o') {
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

Point getNextPositionForFood(Map* map) {
	while (true) {
		int randomRow = rand() % 29 + 1;
		int randomColumn = rand() % 119 + 1;
		Point foodPosition = Point(randomRow, randomColumn);
		if (isEmptyLocationForFood(map, foodPosition)) {
			return foodPosition;
		}
	}
}