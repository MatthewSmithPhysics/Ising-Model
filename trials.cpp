#include"trials.h"

using namespace std;

float mean(vector<float> v, int cutoff)
{
	int N = v.size() - cutoff;
	float sum = 0.0;
	for(int i = 0; i < N; i++) sum = sum + v[i];
	float avg = sum / N;
	return avg;
}

float uncert(vector<float> v, int cutoff)
{
	int N = v.size() - cutoff;
	float avg = mean(v, cutoff);
	float sum = 0.0;
	for(int i = 0; i < N; i++) sum = sum + pow(v[i] - avg, 2.0);
	float err = sqrt(sum / (N - 1))/sqrt(N);
	return err;
}

vector<float> extract(vector<vector<float>> A, int k)
{
	vector<float> v = {};
	for(int i = 0; i < A.size(); i++) v.push_back(A[i][k]);
	return v;
}

vector<vector<float>> H_vs_T(State X0, float B, int steps, int inc)
{
	vector<vector<float>> T_H = {{0.0, H(X0)}};
	State X = X0.copy();
	for(int i = 0; i < steps; i += inc)
	{
		X = evolve(X, B, inc);
		vector<float> row = {(float)(i + inc), H(X)};
		T_H.push_back(row);
		//cout << H(X) << endl;
	}
	return T_H;
}

vector<vector<float>> H_vs_B(State X0, float Bmin, float Bmax, float Binc, int steps, int inc, int cutoff)
{
	vector<vector<float>> B_H = {};
	for(float B = Bmin; B <= Bmax; B += Binc)
	{
		vector<vector<float>> T_H = H_vs_T(X0, B, steps, inc);
		vector<float> Hvals = extract(T_H, 1);
		vector<float> row = {B, mean(Hvals, cutoff), uncert(Hvals, cutoff)};
		B_H.push_back(row);
	}
	return B_H;
}
