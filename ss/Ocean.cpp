#include <iostream>
#include "Ocean.h"
#include "Cell.h"
#include "Constants.h"
#include "Obstacle.h"
#include "Predator.h"
#include "Prey.h"
#include "Random.h"

void Ocean::initialize()
{
	random.initialize();
	numRows = MaxRows;
	numCols = MaxCols; 
	size = numRows * numCols;

	numObstracles = DefaultNumObstracles;
	numPredators = DefaultNumPredators;
	numPrey = DefaultNumPrey;

	initCells();

}

void Ocean::initCells()
{
	addEmptyCells();


	std::cout << "\n\nEnter number of obstacles (default = 75): ";
	std::cout.flush();
	std::cin >> numObstracles;
	if (numObstracles == size)
	{
		numObstracles = size;
	}
	std::cout << "\nNumber obstacles accepted = " << numObstracles;
	std::cout.flush();

	std::cout << "\n\nEnter number of predators (default = 20): ";
	std::cout.flush();
	std::cin >> numPredators;
	if (numPredators == (size - numObstracles))
	{
		numPredators = size - numObstracles;
	}
	std::cout << "\nNumber predators accepted = " << numPredators;
	std::cout.flush();

	std::cout << "\n\nEnter number of prey (default = 150): ";
	std::cout.flush();
	std::cin >> numPrey;
	if (numPrey == (size - numObstracles - numPredators))
	{
		numPrey = size - numObstracles - numPredators;
	}
	std::cout << "\nNumber prey accepted = " << numPrey<<std::endl<<std::endl;


	addObstracles();
	addPredators();
	addPrey();
	displayStats(-1);
	displayCells();
	displayBorder();
	//Cell:: Ocean1 = this;

}

void Ocean::addEmptyCells()
{
	for (unsigned row = 0; row < numRows; row++)
	{
		for (unsigned col = 0; col < numCols; col++)
		{
			cells[row][col] = new Cell(col, row, this);
		}
	}
}

void Ocean::addObstracles()
{
	Coordinate empty;
	for (unsigned count = 0; count < numObstracles; count++)
	{
		empty = getEmptyCellCoord();
		cells[empty.getY()][empty.getX()] = new Obstacle(empty.getX(),empty.getY(), this);
	}
}

void Ocean::addPredators(void)
{
	Coordinate empty;
	for (unsigned count = 0; count < numPredators; count++)
	{
		empty = getEmptyCellCoord();
		cells[empty.getY()][empty.getX()] = new Predator(empty.getX(), empty.getY(), this);
	}
}

void Ocean::addPrey()
{
	Coordinate empty;
	for (unsigned count = 0; count < numPrey; count++)
	{
		empty = getEmptyCellCoord();
		cells[empty.getY()][empty.getX()] = new Prey(empty.getX(), empty.getY(), this);
	}
}

Coordinate Ocean::getEmptyCellCoord()
{
	unsigned x, y;
	Coordinate empty;
	//random.initialize();//corected by myself
	random.first = true;
	do
	{
		x = random.nextIntBetween(0, numCols - 1);
		y = random.nextIntBetween(0, numRows - 1);

	} while (cells[y][x]->getImage() != DefaultImage);

	empty = cells[y][x]->getOffset();
	delete cells[y][x];
	return empty;

}


void Ocean::displayBorder()
{
	for (unsigned col = 0; col < numCols; col++)
	{
		std::cout << "*";
		
	}
	std::cout << "\n";
}

void Ocean::displayCells()
{
	for (unsigned row = 0; row < numRows; row++)
	{
		for (unsigned col = 0; col < numCols; col++)
		{
			cells[row][col]->display();
			
		}
		std::cout << "\n";
	}

}

void Ocean::displayStats(int iteration)
{
	std::cout << "\n\n";
	std::cout << " Iteration number: " << ++iteration;
	std::cout << " Obstacles: " << numObstracles;
	std::cout << " Predators: " << numPredators;
	std::cout << " Prey: " << numPrey << "\n";
	std::cout.flush();
	displayBorder();
}

void Ocean::run()
{
	unsigned numIterations = DefaultNumIterations;

	std::cout << "\n\nEnter number of iterations (default max = 1000): ";
	std::cout.flush();
	std::cin >> numIterations;
	if (numIterations > 1000) numIterations = 1000;
	std::cout << "\nNumber iterations = " << numIterations << "\nbegin run...";
	std::cout.flush();
	for (unsigned iteration = 0; iteration < numIterations; iteration++)
	{
		if (numPredators > 0 && numPrey > 0)
		{
			for (unsigned row = 0; row < numRows; row++)
			{
				for (unsigned col = 0; col < numCols; col++)
				{

					cells[row][col]->process();

				}
				/*displayCells();
				displayBorder();*/
			} 

			displayStats(iteration);
			displayCells();
			displayBorder();
			std::cout.flush();
		}
	}
}

unsigned Ocean::getNumPrey(void)
{ 
	return numPrey; 
}
unsigned Ocean::getNumPredators(void) { 
	return numPredators; 
}
void Ocean::setNumbPrey(unsigned aNumber) 
{ 
	numPrey = aNumber; 
}
void Ocean::setNumbPredators(unsigned aNumber) 
{ 
	numPredators = aNumber;
}

Cell* Ocean::getCells(unsigned x, unsigned y)
{
	return cells[y][x];
}