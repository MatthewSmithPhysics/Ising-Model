#include"state.h"

using namespace std;

State::State()
{
	this->scramble();
}

State::State(int d, int n)
{
	this->d = d;
	this->n = n;
	this->scramble();
}

State::State(int d, int n, double J)
{
	this->d = d;
	this->n = n;
	this->J = J;
	this->scramble();
}

State State::copy()
{
	State Y = State(this->d, this->n, this->J);
	for(int i = 0; i < pow(this->n, this->d); i++) Y.S[i] = this->S[i];
	return Y;
}

void State::scramble()
{
	this->S = {};
	for(int i = 0; i < pow(this->n, this->d); i++)
	{
		int s = rand() % 2;
		if(s == 0) s = -1;
		this->S.push_back(s);
	}
}

