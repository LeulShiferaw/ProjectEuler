#pragma once

#include <vector>

using namespace std;

constexpr int sz = 10000;
bool is_prime[sz + 5];
vector<int> primes;
bool has_seived = false;

void seive()
{
	has_seived = true;
	is_prime[1] = false;
	for (int i = 2; i < sz + 1; ++i)
	{
		is_prime[i] = true;
	}

	for (int i = 2; i < sz + 1; ++i)
	{
		if (is_prime[i])
			primes.push_back(i);
		for (int j = i * i; j < sz + 1; j += i)
		{
			is_prime[j] = false;
		}
	}
}

int num_digs(int n)
{
	return floor(log10(n)) + 1;
}

bool isPrime(int n)
{
	if (!has_seived)
		seive();

	if (n < sz)
	{
		return is_prime[n];
	}
	else
	{
		int temp = ceil(sqrt(n));
		for (int i = 0; i < primes.size(); ++i)
		{
			if (primes[i] > temp)
				break;
			if (n % primes[i] == 0)
				return false;
		}
		return true;
	}
}

bool is_integer(double n)
{
	return floor(n) == n;
}