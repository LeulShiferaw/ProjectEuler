#include <set>
#include <iostream>

using namespace std;

int fac[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

int sum_fac(int n)
{
	int res = 0;
	while (n != 0)
	{
		res += fac[n % 10];
		n /= 10;
	}
	return res;
}

int main()
{
	int res = 0;
	for (int i = 1; i < 1000000; ++i)
	{
		set<int> ls;
		int curr = 0;
		int ele = i;
		while (true)
		{
			if (ls.find(ele) == ls.end())
			{
				ls.insert(ele);
				++curr;
			}
			else
				break;
			ele = sum_fac(ele);
		}
		if (curr == 60)
		{
			printf("%d, %d, %d\n", i, curr, res);
			++res;
		}
	}
	printf("%d\n", res);
	return 0;
}