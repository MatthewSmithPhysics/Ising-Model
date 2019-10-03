#pragma once
#include"includes.h"

class State
{
	public:
	int d = 1;
	int n = 1;
	float J = 1.0;
	std::vector<int> S;
	State();
	State(int, int);
	State(int, int, double);
	State copy();
	void scramble();
};
