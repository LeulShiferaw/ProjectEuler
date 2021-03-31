//-59231
#include <iostream>
#include <vector>

using namespace std;

constexpr int sz = 10000;//Sieve size

int func(const int &a, const int &b, const int &n)
{
	return n * n + n * a + b;
}

vector<int> seive()
{
	vector<int> primes;
	bool is_prime[sz + 5];
	is_prime[1] = false;
	for (int i = 0; i < sz + 1; ++i)
	{
		is_prime[i] = true;
	}

	for (int i = 2; i < sz + 1; ++i)
	{
		if(is_prime[i])
			primes.push_back(i);
		for (int j = i * i; j < sz + 1; j += i)
		{
			is_prime[j] = false;
		}
	}

	return primes;
}

//Input: int n and a vector of primes(from sieve)
//Result: true if n is a prime or false if n is not a prime
bool is_prime(int n, const vector<int> &primes)
{
	if (n < 0)
		n = abs(n);
	if (n <= 1)
		return false;
	for (int x : primes)
	{
		if (x == n)
			return true;
		if (x > sqrt(n))
			return true;
		if (n % x == 0)
			return false;
	}
	return true;
}

int main()
{
	vector<int> primes = seive();

	int prod = 1;
	int longest = -1;
	for (int a = -999; a < 1000; ++a)
	{
		for (int b = -1000; b < 1001; ++b)
		{
			int n = 0;
			int num = 0;
			while (true)
			{
				if (is_prime(func(a, b, n), primes))
				{
					++num;
				}
				else
					break;
				++n;
			}
			if (num > longest)
			{
				longest = num;
				prod = a * b;
			}
		}
	}

	cout << prod << endl;
	return 0;
}