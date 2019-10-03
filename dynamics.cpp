#include"dynamics.h"

using namespace std;

float H(State X)
{
	float E = 0.0;
	for(int k = 0; k < X.d; k++)
	{
		int inc = (int)pow(X.n, k);
		int des = (int)pow(X.n, k + 1);
		for(int i = 0; i < pow(X.n, X.d); i++)
		{
			int j = i + inc;
			if(div(i, des).quot == div(j, des).quot) E = E + X.S[i]*X.S[j];
		}
	}
	E = -X.J*E;
	return E;
}

float acc(State X, State Y, float B)
{
	double A = exp(-B*(H(Y) - H(X)));
	//cout << A << endl;
	if(A < 1.0) return A;
	else return 1.0;
}

State evolve(State X0, float B, int steps)
{
	State X = X0.copy();
	for(int i = 0; i < steps; i++)
	{
		int k = rand() % (int)pow(X.n, X.d);
		State Y = X.copy();
		Y.S[k] = -Y.S[k];
		float r = (float)rand() / RAND_MAX;
		//cout << r << endl;
		//cout << r << ", " << acc(X, Y, B) << endl;
		if(r < acc(X, Y, B))
		{
			X = Y.copy();
		}
	}
	return X;
}