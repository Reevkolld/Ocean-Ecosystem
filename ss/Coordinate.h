#pragma once
class Coordinate
{
private:
	unsigned x;
	unsigned y;

public:
	Coordinate(unsigned aX, unsigned aY) :x(aX), y(aY) {}
	Coordinate(void);
	Coordinate(const Coordinate& aCoord);
	~Coordinate(void) {}

	unsigned getX(void);
	unsigned getY(void);

	void setX(unsigned aX);
	void setY(unsigned aY);

	int operator == (Coordinate& c)
	{
		return (x == c.x && y == c.y);
	}

	int operator != (Coordinate& c)
	{
		return(x != c.x || y != c.y);
	}



};

