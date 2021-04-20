/*
	Author: Leul Shiferaw
	Project Euler Problem 50
*/

#include <iostream>
#include "../../helper.h"

using namespace std;

void display(const vector<int>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
		cout << vec[i] << " ";
	cout << endl;
}
int main()
{
	seive();
	long long sum = 0;
	long long longest = 0;
	for (int i = 0; i < primes.size(); ++i)
	{
		sum = 0;
		vector<int> vec;
		for (int j = i; j < primes.size(); ++j)
		{
			sum += primes[j];
			vec.push_back(primes[j]);
			if (sum < 1000000)
			{
				if ((j - i + 1) > longest && isPrime(sum))
				{
					longest = j - i + 1;
					cout << sum << endl;
					display(vec);
				}
			}
			else
				break;
		}
	}
	return 0;
}