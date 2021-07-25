#include <iostream>
#include "../../helper.h"

using namespace std;

int main()
{
	long long res = 0;
	for (int d = 2; d <= 12000; ++d)
	{
		int start = (double)d / 2.0;
		for (int n = start; n >= 1; --n)
		{
			double temp = (double)n / d;
			if (temp <= (1.0 / 3))
				break;
			if (temp < (1.0 / 2))
			{
				if (gcd(n, d) == 1)
					++res;
			}
		}
	}
	printf("%d\n", res);
	return 0;
}