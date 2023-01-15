#include "Prey.h"
#include "Ocean.h"
#include "Cell.h"

void Prey::moveFrom(Coordinate from, Coordinate to)
{
	Cell* toCell;
	timeToReproduce--;
	if (to != from)
	{
		toCell = getCellAt(to);
		delete toCell;
		setOffset(to);
		assIgnCellAt(to, this);
		if (timeToReproduce <= 0)
		{
			timeToReproduce = TimeToReproduce;
			assIgnCellAt(from, reproduce(from));
		}
		else
		{
			assIgnCellAt(from, new Cell(from.getX(), from.getY(), _owner));
		}
	}
}

Cell* Prey::reproduce(Coordinate anOffset)
{
	Prey* temp = new Prey(anOffset.getX(), anOffset.getY(), _owner);
	_owner->setNumbPrey(_owner->getNumPrey() + 1);
	return (Cell*)temp;
}

Prey :: Prey(Coordinate& aCoord) : Cell(aCoord)
{
	timeToReproduce = TimeToReproduce;
	image = DefaultPreyImage;
}

Prey::Prey(unsigned x, unsigned y, Ocean* owner) : Cell(x, y, owner)
{
	timeToReproduce = TimeToReproduce;
	image = DefaultPreyImage;
}