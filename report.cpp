#include"report.h"

using namespace std;

void writeTXT(vector<vector<float>> A, string filename)
{
	ofstream output;
	output.open(filename);
	for(int i = 0; i < A.size(); i++)
	{
		for(int j = 0; j < A[i].size() - 1; j++) output << A[i][j] << ", ";
		if(A[i].size() >= 1) output << A[i][A[i].size() - 1] << "\n";
	}
}
