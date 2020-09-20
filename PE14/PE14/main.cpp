#include <iostream>

using namespace std;

const int L = 400000000;

int length[L];

int collatz_len(int n)
{
	if (length[n] != 0)
		return length[n];

	if (n % 2 == 0)
	{
		int new_n = n / 2;
		if (length[new_n] == 0)
			length[new_n] = collatz_len(new_n);
		length[n] = 1 + length[new_n];
	}
	else
	{
		int new_n = 3 * n + 1;
		if (length[new_n] == 0)
			length[new_n] = collatz_len(new_n);
		length[n] = 1 + length[new_n];
	}
	return length[n];
}

int norm_collatz_len(long long n)
{
	if (n == 1)
		return 1;
	if (n % 2 == 0)
		return 1 + norm_collatz_len(n / 2);
	else
		return 1 + norm_collatz_len(3 * n + 1);
}

int main()
{
	for (int i = 0; i < L; ++i)
	{
		length[i] = 0;
	}
	length[1] = 1;

	int longest = 0;
	int start_num = 0;
	for (int i = 2; i < 1000000; ++i)
	{
		int temp = norm_collatz_len(i);
		if (temp > longest)
		{
			longest = temp;
			start_num = i;
		}
	}
	cout << longest << endl;
	cout << "Start Num: " << start_num << endl;

	return 0;
}