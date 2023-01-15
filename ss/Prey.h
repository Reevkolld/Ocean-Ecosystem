#pragma once

#ifndef PreyDefined
#define PreyDefined
#include "Cell.h"




class Prey : public Cell
{
protected:
	int timeToReproduce;

	void moveFrom(Coordinate from, Coordinate to);
	virtual Cell* reproduce(Coordinate anOffset);

public:
	Prey(Coordinate& aCoord) ;
	Prey(unsigned x, unsigned y, Ocean* owner);

	virtual void process(void)
	{
		Coordinate toCoord;
		toCoord = getEmptyNeighborCoord();
		moveFrom(_offset, toCoord);
	}

	virtual ~Prey(void) {}

};

#endif




