//Runs longer than a minute
#include <iostream>
#include "../../helper.h"

using namespace std;

int main()
{
	seive();
	/*
	long long n = 1;
	long long phi_n = 1;
	for (int i = 0; i < primes.size(); ++i)
	{
		if (n > 10000000)
			break;
		n *= (long long)primes[i];
		phi_n *= (long long)primes[i];
		phi_n *= 1.0 - 1.0 / primes[i];
		cout << n << ", " << phi_n << endl;
		cin.get();
	}
	*/
	double min = INT_MAX;
	double mini = 2;
	for (int i = 10000000-1; i > 2; --i)
	{
		int phin = phi(i);
		string strphi_n = to_string(phin);
		string strn = to_string(i);
		if (is_permutation(strphi_n.begin(), strphi_n.end(), strn.begin()))
		{
			double curr = (double)i / phin;
			if (curr < min)
			{
				min = curr;
				cout << i << ", " << strphi_n << endl;
				mini = i;
			}
		}
	}
	cout << "ANS: " << mini << endl;
	return 0;
}