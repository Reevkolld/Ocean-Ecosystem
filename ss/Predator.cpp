#include "Predator.h"
#include "Ocean.h"


void Predator::process(void)
{
	Coordinate toCoord;
	if (--timeToFeed <= 0)
	{
		assIgnCellAt(_offset, new Cell(_offset.getX(),_offset.getY(), _owner));
		_owner->setNumbPredators(_owner->getNumPredators() - 1);
		delete this;
	}
	else
	{
		toCoord = getPreyNeighborCoord();
		if (toCoord != _offset)
		{
			_owner->setNumbPrey(_owner->getNumPrey() - 1);
			timeToFeed = TimeToFeed;
			moveFrom(_offset, toCoord);
		}
		else
		{
			Prey::process();
		}
	}
}

Cell* Predator::reproduce(Coordinate anOffset)
{
	Predator* temp = new Predator(anOffset.getX(), anOffset.getY(), _owner);
	_owner->setNumbPredators(_owner->getNumPredators());
	return(Cell*)temp;
}


Predator::Predator(Coordinate aCoord) : Prey(aCoord)
{
	timeToFeed = TimeToFeed;
	image = DefaultPredImage;
}

Predator::Predator(unsigned x, unsigned y, Ocean* owner) : Prey(x, y, owner)
{
	timeToFeed = TimeToFeed;
	image = DefaultPredImage;
}
