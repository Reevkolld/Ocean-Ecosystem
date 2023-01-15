#pragma once
#ifndef ObstacleDefined
#define ObstacleDefined


#include "Cell.h"
class Obstacle :
    public Cell
{
public:
    Obstacle(Coordinate& aCoord);
    Obstacle(unsigned x, unsigned y, Ocean* owner);
    virtual ~Obstacle(void){}
};

#endif 
