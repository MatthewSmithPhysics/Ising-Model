#include"main.h"

using namespace std;

int main()
{
	State X0 = State(20, 20, 1.0);
	vector<vector<float>> B_H = H_vs_B(X0, 0.1, 10.0, 0.1, 10000, 10, 900);
	writeTXT(B_H, "output.txt");
	return 0;
}
