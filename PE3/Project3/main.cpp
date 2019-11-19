#include <iostream>

using namespace std;

typedef long long ll;
ll num = 600851475143;

bool is_prime(const ll& n)
{
	if (n % 2 == 0)
		return false;

	ll sqrtN = sqrt(n);
	for (ll i = 3; i < sqrtN; i+=2)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

//100 = 2*50 = 2*2*25
long largest_prime_factor(ll n)
{
	for (ll i = 2; i < n; ++i)
	{
		if (n % i == 0)
		{
			if (is_prime(n / i))
				return n / i;
			else return largest_prime_factor(n / i);
		}
	}
	return -1;
		
}
int main()
{
	cout << num << endl;
	cout << largest_prime_factor(num) << endl;
	return 0;
}