#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream file("numbers.txt");
	if (!file.is_open())
	{
		cerr << "File error!" << endl;
		return 0;
	}

	int grid[20][20];
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			file >> grid[i][j];
		}
	}

	file.close();

	long long greatest = 1;
	for (int i = 0; i < 20 - 4; ++i)
	{
		long long temp = 1;
		for (int j = 0; j < 4; ++j)
		{
			temp *= grid[i][j];
		}
		if (temp > greatest)
			greatest = temp;
	}
	cout << greatest << endl;

	for (int i = 0; i < 20 - 4; ++i)
	{
		long long temp = 1;
		for (int j = 0; j < 4; ++j)
		{
			temp *= grid[j][i];
		}
		if (temp > greatest)
			greatest = temp;
	}
	cout << greatest << endl;

	for (int i = 0; i < 20 - 4; ++i)
	{
		for (int j = 0; j < 20 - 4; ++j)
		{
			long long temp = 1;
			for (int k = 0; k < 4; ++k)
			{
				temp *= grid[i + k][j + k];
			}
			if (temp > greatest)
				greatest = temp;
		}
	}

	cout << greatest << endl;
	for (int i = 0; i < 20-4; ++i)
	{
		for (int j = 19; j >= 3; --j)
		{
			long long temp = 1;
			for (int k = 0; k < 4; ++k)
			{
				temp *= grid[i + k][j - k];
			}
			if (temp > greatest)
				greatest = temp;
		}
	}

	cout << greatest << endl;

	return 0;
}