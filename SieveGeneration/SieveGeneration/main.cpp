#include <iostream>
#include <vector>

using namespace std;

const int n = 10000;

int main()
{

	bool is_prime[n];
	
	for (int i = 2; i < n; ++i)
	{
		is_prime[i] = true;
	}

	vector<int> primes;
	for (int i = 2; i < n; ++i)
	{
		for (int j = i * i; j < n; j += i)
		{
			is_prime[j] = false;
		}
	}

	for (int i = 2; i < n; ++i)
	{
		if (is_prime[i])
			cout << i << endl;
	}
	return 0;
}