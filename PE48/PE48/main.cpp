/*
	Author: Leul Shiferaw
	Project Euler Problem 58
*/
#include <iostream>

using namespace std;

long long ten_ten = 10000000000;

//Return  a^b  mod 10
long long pow_mod_to10(int a, int b)
{
	long long res = 1;
	for (int i = 0; i < b; ++i)
	{
		res *= a;
		res %= ten_ten;
	}

	return res;
}

int main()
{
	try
	{
		long long res = 0;
		for (int i = 1; i <= 1000; ++i)
		{
			res += pow_mod_to10(i, i);
			res %= ten_ten;
		}
		cout << res << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
		return 1;
	}
	catch (...)
	{
		cout << "Unknown Error!" << endl;
		return 2;
	}
	return 0;
}