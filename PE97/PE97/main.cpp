#include <iostream>

using namespace std;

const long long ten_ten = 10000000000LL;

int main()
{
	long long res = 28433;

	for (int i = 0; i < 7830457; ++i)
	{
		res *= 2;
		res %= ten_ten;
	}

	++res;
	cout << res % ten_ten << endl;
	return 0;
}