#include "PartOfSnake.h"

PartOfSnake::PartOfSnake(const Point& position)
{
    this->position = position;
    this->nextPart = nullptr;
}

PartOfSnake::PartOfSnake(const Point& position, PartOfSnake * nextPart)
{
    this->position = position;
    this->nextPart = nextPart;
}

Point PartOfSnake::getPosition() const
{
    return this->position;
}

void PartOfSnake::setPosition(const Point& position)
{
    this->position = position;
}

PartOfSnake* PartOfSnake::getNext()
{
    return this->nextPart;
}


