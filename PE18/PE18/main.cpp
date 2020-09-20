#include <string>
#include <fstream>
#include <iostream>

using namespace std;

const int n = 100;

int numbers[n][n];
long long sum[n][n];

long long max_path_sum(int x, int y)
{
	//Base case
	if (x == n-1)
	{
		sum[x][y] = numbers[x][y];
		return sum[x][y];
	}

	if (sum[x + 1][y] == -1)
	{
		sum[x + 1][y] = max_path_sum(x + 1, y);
	}

	if (sum[x + 1][y + 1] == -1)
	{
		sum[x + 1][y + 1] = max_path_sum(x + 1, y + 1);
	}

	if (sum[x + 1][y] > sum[x + 1][y + 1])
		return sum[x + 1][y] + numbers[x][y];
	else
		return sum[x + 1][y + 1] + numbers[x][y];
}

int main()
{
	int num;
	ifstream file("numbers.txt");
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			file >> num;
			sum[i][j] = -1;
			numbers[i][j] = num;
			cout << numbers[i][j] << " ";
		}
		cout << endl;

	}

	cout << max_path_sum(0, 0) << endl;

	return 0;
}