#pragma once
class Random
{
private:
	int seed1;
	int seed2;

public:
	bool first;
	void initialize(void);

	void init(int s1, int s2);

	float randReal(void);
	unsigned nextIntBetween(int, int);

};

