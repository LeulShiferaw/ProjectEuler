/*
	Author: Leul Shiferaw
	Project Euler Problem 51
	Answer is not 120303 but 121313 since that is the first one to be PART OF the family
*/
#include <string>
#include <climits>
#include <iostream>
#include "../../helper.h"

using namespace std;

int num_primes(int c, string num, vector<int> &replace)
{
	if(c >= num.size())
		return 0;	
	replace.push_back(c);

	int start = 0;
	if(replace[0] == 0)
		start = 1;

	int numPri = 0;
	string temp = num;
	for(int i = start; i<10; ++i)
	{
		for(int j = 0; j<replace.size(); ++j)
		{
			temp[replace[j]] = '0'+i;
		}
		if(isPrime(stoll(temp)))
			++numPri;
		if(numPri == 8)
		{
			for(int a = start; a<10; ++a)
			{
				for(int b = 0; b<replace.size(); ++b)
					temp[replace[b]] = '0'+a;

				if(isPrime(stoll(temp)))
				{
					cout << temp << " ";
				}
			}
			cout << endl;
		}
	}

	int num2 = num_primes(c+1, num, replace);

	replace.pop_back();

	int num3 = num_primes(c+1, num, replace);
	
	return max(numPri, max(num2, num3));
}

int main()
{
	seive();
	int n = 56003;
	while(true)
	{
		vector<int> replace;
		if(num_primes(0, to_string(n), replace) == 8)
		{
			cout << n << endl;
			break;
		}
		++n;
	}
	return 0;
}