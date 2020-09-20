#include <iostream>
#include <vector>

using namespace std;

const int n = 10000;
vector<int> primes;

//Gets the number of factors of n
//Using the prime factorisation method
//Make sure that primes are calculated before hand
int num_fact(int n)
{
	int res = 1;
	int curr = 0;//Divide each prime until it can't be divided; the number of times it divided is the power to that prime.
	for (int i = 0; i < primes.size();)
	{	
		if (n % primes[i] == 0)
		{
			n /= primes[i];
			++curr;
		}
		else
		{
			res *= curr + 1;
			curr = 0;
			++i;
		}
	}
	return res;
}

int main()
{
	bool is_prime[n];

	for (int i = 2; i < n; ++i)
	{
		is_prime[i] = true;
	}

	//Prime Generation using Sieve Method
	for (int i = 2; i < n; ++i)
	{
		if (!is_prime[i])
			continue;
		primes.push_back(i);
		for (int j = i * i; j < n; j += i)
		{
			is_prime[j] = false;
		}
	}
	
	//Number of facts(sum(1, n)) = num_fact(n*(n+1)/2)
	for (int i = 3; i < 1000000; ++i)
	{
		if (i % 2 == 0)
		{
			if (num_fact(i / 2) * num_fact(i + 1) > 500)
			{
				cout << i * (i + 1) / 2 << endl;
				return 0;
			}
		}
		else
		{
			if ((num_fact((i + 1) / 2) * num_fact(i)) > 500)
			{
				cout << i * (i + 1) / 2 << endl;
				return 0;
			}

		}
	}
	return 0;
}