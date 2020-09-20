#include <iostream>

using namespace std;


long long num_path(long long grid[][21], int x, int y)
{
	if (grid[x][y] != -1)
		return grid[x][y];

	if (x == 0 || y == 0)
		return 1;

	if (grid[x - 1][y] == -1)
	{
		grid[x - 1][y] = num_path(grid, x - 1, y);
		grid[y][x - 1] = grid[x - 1][y];
	}
	if (grid[x][y - 1] == -1)
	{
		grid[x][y - 1] = num_path(grid, x, y - 1);
		grid[y - 1][x] = grid[x][y - 1];
	}

	grid[x][y] = grid[x][y - 1] + grid[x - 1][y];
	grid[y][x] = grid[x][y];
	return grid[x][y];
}

int main()
{
	const int n = 20 + 1, m = 20 + 1;
	long long grid[n][m];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			grid[i][j] = -1;
		}
	}

	cout << num_path(grid, 20, 20) << endl;
	return 0;
}