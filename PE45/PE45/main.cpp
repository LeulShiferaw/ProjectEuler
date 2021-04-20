/*
	Author: Leul Shiferaw
	Project Euler Problem 45
*/
#include <iostream>
#include "../../helper.h"

using namespace std;

long long triangle_num(long long n)
{
	return (n * (n + 1)) / 2;
}

bool is_pentagonal(long long pn)
{
	return is_long((1.0 + sqrt(1 + 24.0 * pn)) / 6.0);
}

bool is_hexa(long long hn)
{
	return is_long((1.0 + sqrt(1.0 + 8.0 * hn)) / 4.0);
}

int main()
{
	long long n = 1;
	while (true)
	{
		long long tri_num = triangle_num(n);
		if (is_hexa(tri_num) && is_pentagonal(tri_num))
		{
			cout << tri_num << endl;
		}
		++n;
	}
	return 0;
}