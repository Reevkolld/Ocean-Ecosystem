#pragma once
#ifndef PredatorDefiend
#define PredatorDefined
#include "Prey.h"
class Predator :
    public Prey
{
private:
    virtual Cell* reproduce(Coordinate anOffset);

protected: 
    unsigned timeToFeed;

public:
    Predator(Coordinate aCoord);
    Predator(unsigned x, unsigned y, Ocean* owner);
    virtual ~Predator(void){}
    virtual void process(void);

};


#endif // !1