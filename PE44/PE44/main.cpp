/*
	Author: Leul Shiferaw
	Project Euler Problem 44
*/
#include <iostream>
#include "../../helper.h"

using namespace std;

long long pent(long long n)
{
	return (n * (3ll * n - 1ll) / 2ll);
}

//Generate pentagonal numbers
vector<long long> generate_pent(long long n)
{
	vector<long long> res;
	for (int i = 1; i <= n; ++i)
		res.push_back(pent(i));
	return res;
}

bool is_pentagonal(long long pn)
{
	if (is_long((1.0 + sqrt(1.0 + 24.0 * pn)) / 6.0))
	{
		return true;
	}
	return false;
}

int main()
{
	long long p1 = 0, p2 = 0;
	long long smallest = LLONG_MAX;

	//Generate pentagonal numbers
	vector<long long> pents = generate_pent(10000);
	for (int i = 0; i < pents.size(); ++i)
	{
		for (int j = i+1; j < pents.size(); ++j)
		{
			//If the difference so far is greater than smallest
			//Stop because it is only going to get larger as pents[j] gets larger
			if(abs(pents[j]-pents[i])>smallest)
				break;

			//Sum and difference
			long long sum = pents[i] + pents[j];
			long long diff = pents[j] - pents[i];

			//Is their sum and difference pentagonal
			if (is_pentagonal(sum) && is_pentagonal(diff))
			{
				cout << "P1: " << pents[i] << endl;
				cout << "P2: " << pents[j] << endl << endl;
				if (abs(diff) < smallest)
				{
					smallest = abs(diff);
					p1 = pents[i];
					p2 = pents[j];
				}
			}
		}
	}
	
	//Final result
	cout << "p1: " << p1 << endl;
	cout << "p2: " << p2 << endl;
	cout << "Diff: " << p2 - p1 << endl;
	return 0;
}