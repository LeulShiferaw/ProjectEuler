#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool find(const vector<double>& vec, double ele)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		if (abs(vec[i] - ele) < 0.0001)
			return true;
	}
	return false;
}

int main()
{
	int res = 0;
	for (int i = 1; i <= 10000; ++i)
	{
		int a = i;
		int b = floor(sqrt(i));
		int d = 1;
		int k = (a - (b * b)) / (double)d;

		vector<pair<int, int>> vec;
		while (true)
		{
			int q = floor((sqrt(a) + b) / (double)k);
			int new_b = -(b - q * k);
			int new_k = (a - (b - q * k) * (b - q * k)) / (double)k;
			auto it = find(vec.begin(), vec.end(), make_pair(new_b, new_k))

		}

	}

	cout << res << endl;
	return 0;
}