#include <iostream>

using namespace std;

long long fac(int n)
{
	long long res = 1;
	for (int i = n; i > 0; --i)
		res *= i;
	return res;
}

int num_vals(int n)
{
	int res = 0;
	long long num = fac(n);
	long long den = fac(n / 2) * fac(n - (n / 2));
	for (int i = n / 2; i >= 0; --i)
	{
		if ((num / den) > 1000000)
		{
			if (i == n / 2 && (n - i) == i)
				++res;
			else res += 2;
		}
		num *= i;
		den *= (n - i + 1);
	}
	return res;
}

int main()
{
	long long res = 0;
	cout << "Hello world";
	for (int i = 1; i < 100; ++i)
	{
		cout << "Hello world" << i << endl;
		res+=num_vals(i);
	}
	cout << "Result: " << res << endl;
	
	return 0;
}