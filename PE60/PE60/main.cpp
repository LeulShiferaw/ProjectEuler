#include <climits>
#include <sstream>
#include <iostream>
#include "../../helper.h"

using namespace std;

long long concatenate(int a, int b)
{
	stringstream ss;
	ss << a << b;
	return stoll(ss.str());
}

long long min_sum = INT_MAX;
void findFive(int s, int e, vector<int> &currPrimes)
{
	if(currPrimes.size() == 5)
	{
		long long sum = 0;
		for(int x : currPrimes)
		{
			sum += x;
		}
		min_sum = min(min_sum, sum);
		cout << "Min Sum: " << min_sum << endl;
		return;
	}

	if(s >= e)
		return;
	bool con = true;
	for(int i = 0; i<currPrimes.size(); ++i)
	{
		if(!isPrime(concatenate(pr[s], currPrimes[i])) || !isPrime(concatenate(currPrimes[i], pr[s])))
		{
			con = false;
			break;
		}
	}
	if(con)
	{
		currPrimes.push_back(pr[s]);
		findFive(s+1, e, currPrimes);
		currPrimes.pop_back();
	}
	findFive(s+1, e, currPrimes);
}

int main()
{
	seive();
	vector<int> c_primes;
	findFive(0, 10000, c_primes);
	return 0;
}