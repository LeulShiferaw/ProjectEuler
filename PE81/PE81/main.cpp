//Project Euler 81
//Author: Leul Shiferaw
#include <fstream>
#include <iostream>

using namespace std;


int mat[80][80];
long long soln[80][80];

long long min_path_sum(int i, int j)
{
	if (soln[i][j] != -1)
		return soln[i][j];

	if (i == 79)
	{
		long long res = 0;
		for (int k = j; k < 80; ++k)
			res += mat[i][k];
		soln[i][j] = res;
		return res;
	}
	else if (j == 79)
	{
		long long res = 0;
		for (int k = i; k < 80; ++k)
			res += mat[k][j];
		soln[i][j] = res;
		return res;
	}

	soln[i][j] = min<long long>(mat[i][j] + min_path_sum(i + 1, j), mat[i][j] + min_path_sum(i, j + 1));
	return soln[i][j];
}

int main()
{
	ifstream file("file.txt");
	for(int i = 0; i<80; ++i)
		for (int j = 0; j < 80; ++j)
		{
			int temp;
			file >> temp;

			if (j != 79)
			{
				char c;
				file >> c;
			}

			soln[i][j] = -1;
			mat[i][j] = temp;
		}
	file.close();

	cout << min_path_sum(0, 0) << endl;
	return 0;
}