#include "Obstacle.h"
#include "Coordinate.h"
#include "Ocean.h"

Obstacle::Obstacle(Coordinate& aCoord) :Cell(aCoord)
{
    image = ObstacleImage;
}

Obstacle::Obstacle(unsigned x, unsigned y, Ocean* owner) : Cell(x, y, owner)
{
    image = ObstacleImage;
}