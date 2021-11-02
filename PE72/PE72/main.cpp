#include <iostream>
#include "../../helper.h"

using namespace std;

int main()
{
	seive();
	long long res = 0;
	for (int i = 2; i <= 1000000; ++i)
	{
		res += phi(i);
	}
	cout << res << endl;
}