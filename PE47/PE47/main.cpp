/*
	Author: Leul Shiferaw
	Project Euler problem 47
*/

#include <algorithm>
#include <vector>
#include <iostream>
#include "../../helper.h"

using namespace std;

vector<int> prime_factorise(int n)
{
	vector<int> prim_facts;
	int temp = ceil(sqrt(n));

	for (int i = 2; i <= temp; ++i)
	{
		if (n % i == 0)
		{
			prim_facts.push_back(i);
			vector<int> temp0 = prime_factorise(n / i);
			for (int j = 0; j < temp0.size(); ++j)
				prim_facts.push_back(temp0[j]);
			return prim_facts;
		}
	}

	//Only if it is prime will it reach here so it only contains itself
	prim_facts.push_back(n);
	return prim_facts;
}

int num_unique(const vector<int> &vec)
{
	int res = 0;
	for (int i = 0; i < vec.size(); ++i)
	{
		if (i == 0)
			++res;
		else if (vec[i] != vec[i - 1])
			++res;
	}
	return res;
}

int main()
{
	int curr = -1;
	int mult = 1;
	for (int i = 3; i < 1000000; ++i)
	{
		vector<int> vec = prime_factorise(i);
		sort(vec.begin(), vec.end());

		int unq_fac  = num_unique(vec);
		if (unq_fac == curr)
			++mult;
		else mult = 1;
		curr = unq_fac;
		if (mult == 4 && curr == 4)
			cout << i-3 << " " << i - 2 << " " << i - 1 << " " << i << endl;

	}

	return 0;
}