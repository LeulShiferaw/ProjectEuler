#include <iostream>

using namespace std;

int main()
{
	int fib1 = 1;
	int fibn = 2;

	long long sum = 0;
	while (fibn < 4000000)
	{
		if (fibn % 2 == 0)
			sum += fibn;
		int temp = fibn;
		fibn = fib1 + fibn;
		fib1 = temp;
	}
	
	cout << sum << endl;
	return 0;
}