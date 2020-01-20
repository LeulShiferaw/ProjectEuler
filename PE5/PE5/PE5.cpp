#include <iostream>

using namespace std;

int main()
{
	long long sum1 = 0;
	for (int i = 1; i <= 100; ++i)
	{
		sum1 += i;
	}
	sum1 *= sum1;

	long long sum2 = 0;
	for (int i = 1; i <= 100; ++i)
		sum2 += i * i; 

	cout << abs(sum2 - sum1) << endl;
	return 0;
}