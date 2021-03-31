#include <iostream>
#include <set>

using namespace std;

//Is it a curious fraction
//Given that n and d are two digit fractions
bool is_cur_frac(int n, int d)
{
	int tempn = n, tempd = d;
	int nx2 = tempn % 10;//Second digit of numertator
	tempn /= 10;
	int nx1 = tempn % 10;//First digit of numerator
	tempn /= 10;

	int dx2 = tempd % 10;
	tempd /= 10;
	int dx1 = tempd % 10;
	tempd /= 10;

	if (nx1 == dx1)
	{
		if ((double)n / (double)d == (double)nx2 / (double)dx2)
			return true;
	}

	if (nx1 == dx2)
	{
		if ((double)n / (double)d == (double)nx2 / (double)dx1)
			return true;
	}

	if (nx2 == dx1)
	{
		if ((double)n / (double)d == (double)nx1 / (double)dx2)
			return true;
	}

	if (nx2 == dx2 && nx2 != 0)
	{
		if ((double)n / (double)d == (double)nx1 / (double)dx1)
			return true;
	}

	return false;
}

int main()
{
	for (int i = 10; i <= 99; ++i)
	{
		for (int j = i + 1; j <= 99; ++j)
		{
			if (is_cur_frac(i, j))
			{
				cout << "Num: " << i << endl;
				cout << "Den: " << j << endl << endl;
			}
		}
	}

	return 0;
}