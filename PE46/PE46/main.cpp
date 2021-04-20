/*
	Author: Leul Shiferaw
	Project Euler problem 46
*/

#include <iostream>
#include "../../helper.h"

using namespace std;

//Does this correspond with the conjecture
bool is_conj(long long n)
{
	int ind = 0;
	while (primes[ind] < n)
	{
		if (is_long(sqrt((n - primes[ind]) / 2.0)))
			return true;
		++ind;
	}
	return false;
}

int main()
{
	//Brute force
	for (int i = 3; i < 100000; i += 2)
	{
		if (!isPrime(i) && !is_conj(i))
			cout << i << endl;
	}
	return 0;
}