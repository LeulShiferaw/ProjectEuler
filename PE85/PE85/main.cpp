#include <iostream>
#include <math.h>

using namespace std;

/*
	The number of rectangles starting at the top left corner of an n by m is n multiplied by m
	Then just do that for every corner and you will find the number of rectangles in the n by m grid
*/
long long num_rec(int n, int m)
{
	long long res = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			res += (i * j);
		}
	}
	return res;
}

int main()
{
	int smallest = INT_MAX;
	for (int i = 1; i <= 500; ++i)
	{
		for (int j = 1; j <= 500; ++j)
		{
			int temp = num_rec(i, j);
			if (abs(2000000 - temp) < smallest)
			{
				smallest = abs(2000000 - temp);
				cout << i << " " << j << " " << smallest << ", " << i*j << endl;
			}
		}
	}
	return 0;
}