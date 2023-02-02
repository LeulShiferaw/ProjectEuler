#include <fstream>
#include <limits.h>
#include <iostream>

using namespace std;

constexpr int N = 80;
int soln[N][N][3];
int mat[N][N];
bool checked[N][N];

int min_path_sum(int, int);
int min_path_sum_up(int, int);
int min_path_sum_down(int, int);

int min_path_sum(int i, int j)
{
	if(soln[i][j][0] != -1)
		return soln[i][j][0];

	if (j == N-1)
	{
		soln[i][j][0] = mat[i][j];
		return mat[i][j];
	}

	checked[i][j] = true;
	int up = INT_MAX, down = INT_MAX, right = INT_MAX;
	if(i-1 >= 0)
	{
		if(!checked[i-1][j])
			up = min_path_sum_up(i-1, j);	
	}

	if(i+1 < N)
	{
		if(!checked[i+1][j])
			down = min_path_sum_down(i+1, j);
	}

	if(!checked[i][j+1])
		right = min_path_sum(i, j+1);
	checked[i][j] = false;

	soln[i][j][0] = mat[i][j] + min(up, min(right, down));
	return soln[i][j][0];
}

int min_path_sum_down(int i, int j)
{
	if(soln[i][j][1] != -1)
		return soln[i][j][1];

	if (j == N-1)
		return mat[i][j];

	checked[i][j] = true;
	int down = INT_MAX, right = INT_MAX;

	if(i+1 < N)
	{
		if(!checked[i+1][j])
			down = min_path_sum_down(i+1, j);
	}

	if(!checked[i][j+1])
		right = min_path_sum(i, j+1);

	checked[i][j] = false;

	soln[i][j][1] = mat[i][j] + min(right, down);
	return soln[i][j][1];
}

int min_path_sum_up(int i, int j)
{
	if(soln[i][j][2] != -1)
		return soln[i][j][2];

	if (j == N-1)
		return mat[i][j];

	checked[i][j] = true;
	int up = INT_MAX, right = INT_MAX;
	if(i-1 >= 0)
	{
		if(!checked[i-1][j])
			up = min_path_sum_up(i-1, j);	
	}

	if(!checked[i][j+1])
		right = min_path_sum(i, j+1);
	checked[i][j] = false;

	soln[i][j][2] = mat[i][j] + min(up, right);
	return soln[i][j][2];
}

int main()
{
	ifstream file("file.txt");
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int temp;
			file >> temp;

			if (j != 79)
			{
				char c;
				file >> c;
			}

			for(int k = 0; k<3; ++k)
				soln[i][j][k] = -1;
			mat[i][j] = temp;
			checked[i][j] = false;
		}
	}
	file.close();

/*
	for(int i = 0; i<5; ++i)
	{
		for(int j = 0; j<5; ++j)
		{
			for(int k = 0; k<3; ++k)
				soln[i][j][k] = -1;
		}
	}
	*/

	int res = INT_MAX;
	for(int i = 0; i<N; ++i)
	{
		res = min(res, min_path_sum(i, 0));
	}

	cout << res << endl;
}