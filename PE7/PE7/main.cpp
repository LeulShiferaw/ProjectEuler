#include <iostream>

using namespace std;

bool is_prime(int n)
{
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

	int n_prime = 1;

	int i = 3;
	int res = 0;
	while (1)
	{
		if (is_prime(i))
			++n_prime;
		if (n_prime == 10001)
		{
			res = i;
			break;
		}
		i += 2;
	}
	cout << res << endl;
	return 0;
}