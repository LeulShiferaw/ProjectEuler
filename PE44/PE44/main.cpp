#include <iostream>
#include "../../helper.h"

using namespace std;

long long pent(int n)
{
	return(long long)((long long)n * (3ll * (long long)n - 1ll) / 2ll);
}

//Generate pentagonal numbers
vector<long long> generate_pent(int n)
{
	vector<long long> res;
	for (int i = 1; i <= n; ++i)
		res.push_back(pent(i));
	return res;
}

bool is_pentagonal(long long pn)
{
	if (is_integer((1.0 + sqrt(1.0 + 24.0 * pn)) / 2.0))
	{
		return true;
	}
	return false;
}

int main()
{
	int smallest = 1000000000;
	long long p1 = 0, p2 = 0;
	vector<long long> pents = generate_pent(10000000);
	for (int i = 0; i < pents.size(); ++i)
	{
		for (int j = i + 1; j < pents.size(); ++j)
		{
			if(abs(pents[j]-pents[i])>smallest)
				break;
			if (i == 3 && j == 7)
				cout << "Break!" << endl;
			if (is_pentagonal(pents[i] + pents[j]) && is_pentagonal(abs(pents[j] - pents[i])))
			{
				cout << "P1: " << pents[i] << endl;
				cout << "P2: " << pents[j] << endl << endl;
				if (abs(pents[j] - pents[i]) < smallest)
				{
					smallest = abs(pents[j] - pents[i]);
					p1 = pents[i];
					p2 = pents[j];
				}
			}
		}
	}
	cout << "p1: " << p1 << endl;
	cout << "p2: " << p2 << endl;
	return 0;
}