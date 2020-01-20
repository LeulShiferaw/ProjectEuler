#include <iostream>

using namespace std;

bool is_prime(int n)
{
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;
	int temp = sqrt(n);
	for (int i = 3; i <= temp; i += 2)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	long long res = 0;
	for (int i = 2; i < 2000000; ++i)
	{
		if (is_prime(i))
			res += i;
	}
	cout << res << endl;
	return 0;
}