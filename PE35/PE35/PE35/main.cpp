#include <vector>
#include <iostream>

using namespace std;

constexpr int sz = 10000 + 4;
vector<int> primes;
bool is_prime[sz + 5];

vector<int> seive()
{
	//Initialize
	is_prime[1] = false;
	for (int i = 0; i < sz + 1; ++i)
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

	return primes;
}

bool isPrime(int n)
{
	if (n < sz)
	{
		return is_prime[n];
	}
	else
	{
		int temp = sqrt(n);
		for (int i = 0; i < primes.size(); ++i)
		{
			if (primes[i] > temp)
				break;
			if (n % primes[i] == 0)
			{
				return false;
			}
		}
		return true;
	}
}

int num_digs(int n)
{
	return floor(log10(n)) + 1;
}

int circulate(int &n)
{
	int temp = n % 10;
	n /= 10;
	n += pow(10, num_digs(n)) * temp;
	return n;
}

bool is_circular_prime(int n)
{
	if (!isPrime(n))
		return false;
	int len = num_digs(n);
	for (int i = 0; i < len; ++i)
	{
		if (!isPrime(circulate(n)))
			return false;
	}

	return true;
}

int main()
{
	primes = seive();

	int res = 0;
	for(int i = 2; i<1000000; ++i)
	{
		if (i < 10)
		{
			if (is_prime[i])
				++res;
			continue;
		}
		if (is_circular_prime(i))
			++res;
	}

	cout << res << endl;
	return 0;
}