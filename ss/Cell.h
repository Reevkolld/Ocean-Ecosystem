#pragma once
//#include "Ocean.h"
#include "Coordinate.h"
#ifndef CellDefined
#define CellDefined
#include "Constants.h"
class Ocean;
class Cell
{
friend class Ocean;
protected:
	Ocean* _owner;
	Coordinate _offset;
	char image;

	Cell* getCellAt(Coordinate aCoord);
	void assIgnCellAt(Coordinate aCoord, Cell* aCell);
	Cell* getNeighborWithImage(char anImage);
	Coordinate getEmptyNeighborCoord(void);
	Coordinate getPreyNeighborCoord(void);
	Cell* north(void);
	Cell* south(void);
	Cell* east(void);
	Cell* west(void);

	virtual Cell* reproduce(Coordinate anOffset);

public:
	
	Cell(Coordinate& aCoord);// : _offset(aCoord) { image = DefaultImage; }
	
	Cell(unsigned x, unsigned y, Ocean* owner);
	Cell(void) { }
	virtual ~Cell(void){}

	Coordinate& getOffset(void);
	void setOffset(Coordinate& anOffset);
	char getImage(void);
	void display(void);
	virtual void process(void){}

};

#endif
