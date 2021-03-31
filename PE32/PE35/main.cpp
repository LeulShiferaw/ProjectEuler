#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

int num_dig(int n)
{
	return ceil(log10(n)) + 1;
}

bool is_pandig_prod(int a, int b)
{
	vector<int> nums;
	int prod = a * b;
	while (prod != 0)
	{
		nums.push_back(prod % 10);
		prod /= 10;
	}

	while (a != 0)
	{
		nums.push_back(a % 10);
		a /= 10;
	}

	while (b != 0)
	{
		nums.push_back(b % 10);
		b /= 10;
	}

	sort(nums.begin(), nums.end());

	if (nums[0] == 1 && nums.size() == 9)
	{
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[i] != nums[i - 1] + 1)
				return false;
		}
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int limit = 10000;
	long long res = 0;
	set<int> pandigs;

	for (int i = 1; i <= limit; ++i)
	{
		for (int j = 1; j <= limit; ++j)
		{
			if (is_pandig_prod(i, j))
			{
				if (pandigs.find(i * j) == pandigs.end())
				{
					pandigs.insert(i * j);
					res += i * j;
					cout << i << " " << j << " " << i * j << endl;
					cout << res << endl;
				}
			}
		}
	}
	cout << "Result: " << res << endl;


	return 0;
}