//Solved using youtube tutorial on coin change problem and partitions
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int	n = 100;

	vector<vector<int>> soln;
	for (int i = 0; i <= n; ++i)
	{
		vector<int> row;
		for (int j = 0; j <= n; ++j)
			row.push_back(-1);
		soln.push_back(row);
	}
	for (int i = 0; i <= n; ++i)
	{
		soln[0][i] = 0;
		soln[1][i] = 1;
	}
	soln[0][0] = 1;
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			if (j < i)
			{
				soln[i][j] = soln[i - 1][j];
			}
			else
			{
				soln[i][j] = soln[i - 1][j] + soln[i][j - i];
			}
		}
	}
	cout << soln[100][100] - 1 << endl;
	return 0;
}