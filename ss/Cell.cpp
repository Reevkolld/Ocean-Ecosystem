#include "Cell.h"
#include <iostream>
#include "Ocean.h"

Cell* Cell::getCellAt(Coordinate aCoord)
{
	return _owner->getCells(aCoord.getX(), aCoord.getY());
}

void Cell::assIgnCellAt(Coordinate aCoord, Cell*aCell)
{
	_owner->cells[aCoord.getX()][aCoord.getY()] = aCell;
}

Cell* Cell::getNeighborWithImage(char anImage)
{
	Cell* neighbors[4];
	
	unsigned count = 0;

	if (north()->getImage() == anImage)
	{
		neighbors[count++] = north();
	}
	if (south()->getImage() == anImage)
	{
		neighbors[count++] = south();
	}
	if (east()->getImage() == anImage)
	{
		neighbors[count++] = east();
	}
	if (west()->getImage() == anImage)
	{
		neighbors[count++] = west();
	}
	if (count == 0)
	{
		return this;
	}
	else
	{
		return neighbors[_owner->random.nextIntBetween(0, count - 1)];

	}


}

Coordinate Cell::getEmptyNeighborCoord()
{
	return getNeighborWithImage(DefaultImage)->getOffset();
}

Coordinate Cell::getPreyNeighborCoord(void)
{
	return getNeighborWithImage(DefaultPreyImage)->getOffset();
}

Cell* Cell::north()
{
	unsigned yvalue;
	yvalue = (_offset.getY() > 0) ? (_offset.getY() - 1) : (_owner->numRows - 1); //
	return _owner->getCells(_offset.getX(),yvalue);
}

Cell* Cell::south()
{
	unsigned yvalue;
	/*yvalue = (_offset.getY() + 1) %  _owner->numRows;
	return _owner->cells[_offset.getX()][yvalue];*/


	//yvalue = (_offset.getY() < 24) ? ((_offset.getY() + 1) : 0); //

	if (_offset.getY() < 24)
	{
		yvalue = _offset.getY() + 1;
	}
	else
	{
		yvalue = 0;
	}

	return _owner->getCells(_offset.getX(), yvalue);
}

Cell* Cell::east()
{
	unsigned xvalue;
	/*xvalue = (_offset.getX() + 1) % _owner->numCols;*/
	 
	if (_offset.getX() < 69)
	{
		xvalue = _offset.getX() + 1;
	}
	else
	{
		xvalue = 0;
	}

	return _owner->cells[xvalue][_offset.getY()];
}

Cell* Cell::west()
{
	unsigned xvalue;
	/*xvalue = (_offset.getX() > 0) ? (_offset.getX() - 1) : (_owner->numCols - 1);
	return _owner->cells[xvalue][_offset.getY()];*/

	if (_offset.getX() ==  0)
	{
		xvalue = _owner->numCols - 1;
	}
	else
	{
		xvalue = _offset.getX() - 1;
		

	}
	return _owner->cells[xvalue][_offset.getY()];
}

Cell* Cell::reproduce(Coordinate anOffset)
{
	Cell* temp = new Cell(anOffset.getX(),anOffset.getY(),_owner);
	return temp;
}

void Cell::display()
{
	std::cout << ("%c", image);
}

Cell::Cell(Coordinate& aCoord)  
{ 
	_offset = aCoord;
	image = DefaultImage; 
}

Cell::Cell(unsigned x, unsigned y, Ocean* owner) : _offset(x, y), _owner(owner)
{
	image = DefaultImage; 
}

Coordinate&  Cell:: getOffset() 
{
	return _offset; 
}

void Cell::setOffset(Coordinate& anOffset) 
{
	_offset = anOffset; 
}


char Cell::getImage() 
{ 
	return image; 
}