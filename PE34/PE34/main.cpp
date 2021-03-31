#include <iostream>

using namespace std;

int factorial[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

int sum_fac_dig(int n)
{
	int res = 0;
	while (n != 0)
	{
		res += factorial[n % 10];
		n /= 10;
	}
	return res;
}

int main()
{
	long long res = 0;
	for (int i = 10; i < 100000000; ++i)
	{
		if (sum_fac_dig(i) == i)
		{
			res += i;
			cout << i << endl;
		}
	}
	cout << "Result: " << res << endl;
	return 0;
}