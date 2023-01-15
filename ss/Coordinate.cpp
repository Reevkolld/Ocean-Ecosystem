#include "Coordinate.h"

unsigned Coordinate::getX() 
{ 
	return x; 
}
unsigned Coordinate::getY() 
{ 
	return y; 
}

void Coordinate::setX(unsigned aX) 
{ 
	x = aX;
}
void Coordinate::setY(unsigned aY) 
{ 
	y = aY;
}

Coordinate::Coordinate(const Coordinate& aCoord)
{
	x = aCoord.x;
	y = aCoord.y;
}

Coordinate::Coordinate(void) 
{
	x = 0; y = 0; 
}

