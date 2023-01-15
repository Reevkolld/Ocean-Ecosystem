#pragma once
#include "Coordinate.h"
#include "Random.h"
#include "Constants.h"
#include "Cell.h"

class Ocean
{
	friend class Cell;
private:
	unsigned numRows;
	unsigned numCols;
	unsigned size;
	unsigned numPrey;
	unsigned numPredators;
	unsigned numObstracles;
	Random random;
	Cell* cells[MaxRows][MaxCols];



	void initCells(void);
	void addEmptyCells(void);
	void addObstracles(void);
	void addPredators(void);
	void addPrey(void);
	Coordinate getEmptyCellCoord(void);

	void displayBorder(void);
	void displayCells(void);
	void displayStats(int interation);

public:
	unsigned getNumPrey(void);
	unsigned getNumPredators(void);
	void setNumbPrey(unsigned aNumber);
	void setNumbPredators(unsigned aNumber);
	void initialize(void);
	void run(void);
	Cell* getCells(unsigned x, unsigned y);

};

