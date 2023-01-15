#include "Random.h"
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // для функции time()
#define MAX 32767

//float Random::randReal()
//{
//	int c;
//	//static bool first = 1;//it`s corected by myself (bool) in book is empty
//	//v = rand() % 100 + 1;
//	if (first)
//	{
//		seed1 *= 2;
//		seed2 *= 2;
//		if (seed1 > MAX) seed1 = MAX;
//		if (seed2 > MAX)seed2 = MAX;
//		first = 0;
//
//		for (int index = 1; index <= 30; index++) randReal();
//	}
//	c = seed1 + seed2;
//	if (c > MAX)c = MAX;
//	c *= 2;
//	if (c > MAX)c = MAX;
//	seed1 = seed2;
//	seed2 = c;
//	return(float)c / 32767.0;
//
//}

//unsigned Random::nextIntBetween(int low, int high)
//{
//	float r, t;
//	int c;
//
//	r =(float)high - (float)low;//it`s corected by myself deleted + 1.0 y = 70
//	float v = rand() % low + high;
//	t = r * v ;
//	c = (int)t;
//	return (low + c);
//}


unsigned Random::nextIntBetween(int low, int high)
{
	int randNumber;
	randNumber = rand() % high + low;
	return randNumber;
}

void Random::initialize(void)
{
	seed1 = 3797;
	seed2 = 2117;
}

void Random::init(int s1, int s2)
{
	seed1 = s1;
	seed2 = s2;
}
