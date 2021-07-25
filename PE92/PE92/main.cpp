//Project Euler - PE92
#include <vector>
#include <iostream>

using namespace std;

vector<int> arr;

int sum_dig(int n)
{
	int sum = 0;
	while (n > 0)
	{
		sum += (n % 10) * (n % 10);
		n /= 10;
	}
	return sum;
}

int end(int n)
{
	if (n == 89)
		return 89;
	else if (n == 1)
		return 1;

	if (arr[n] == -1)
	{
		arr[n] = end(sum_dig(n));
		return arr[n];
	}
	else
		return arr[n];

}

int main()
{
	for (int i = 0; i < 10000000; ++i)
		arr.push_back(-1);

	arr[85] = 89;
	arr[89] = 89;
	arr[145] = 89;
	arr[42] = 89;
	arr[20] = 89;
	arr[4] = 89;
	arr[16] = 89;
	arr[37] = 89;
	arr[58] = 89;

	arr[44] = 1;
	arr[32] = 1;
	arr[13] = 1;
	arr[10] = 1;
	arr[1] = 1;

	cout << "PART 1" << endl;
	int res = 0;
	for (int s = 1; s < 10000000; ++s)
	{
		if (end(s) == 89)
			++res;
	}
	cout << res << endl;
	return 0;
}