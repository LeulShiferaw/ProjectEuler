//Algorithm:
//Find x in x/d = 3/7 that is the value of x that is closest to 3/7
//Start from x and go down till you find one that has gcd(x, d) == 1 & it can't be less than the current value that is closest to 3/7
#include <iostream>
#include "../../helper.h"

using namespace std;


int main()
{

	double curr = -1;
	pair<int, int> curr_frac = make_pair(-1, -1);
	for (int d = 2; d <= 1000000; ++d)
	{
		if (d == 3 || d==7)
			continue;
		//printf("%d\n", d);
		int start = (double)d * 3.0 / 7.0;
		
		for (int n = start; n >= 1; --n)
		{
			double temp = (double)n / d;
			if (temp <= curr)
				break;
			else if (gcd(n, d) == 1)
			{
				if (temp > curr)
				{
					curr = temp;
					curr_frac.first = n;
					curr_frac.second = d;
				}
				break;
			}
		}
	}

	cout << curr_frac.first << ", " << curr_frac.second << endl;
	return 0;
}