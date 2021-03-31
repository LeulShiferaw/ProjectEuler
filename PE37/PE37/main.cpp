#include <iostream>
#include "../../helper.h"
#include <cmath>

using namespace std;

bool is_trunc_lef_righ(int n)
{
	int start_pow = pow(10, num_digs(n) - 1);
	while (n > 0)
	{
		if (!isPrime(n))
			return false;

		n %= start_pow;
		start_pow /= 10;
	}
	return true;
}

bool is_trunc_righ_lef(int n)
{
	do
	{
		if (!isPrime(n))
			return false;
		n /= 10;
	} while (n > 0);
	return true;
}

int main()
{
	int res = 0;
	int x = 10;
	while (true)
	{
		if (is_trunc_lef_righ(x) && is_trunc_righ_lef(x))
		{
			res += x;
			cout << "X:" << x << endl;
			cout << "Sum: " << res << endl << endl;
		}
		++x;
	}
	return 0;
}