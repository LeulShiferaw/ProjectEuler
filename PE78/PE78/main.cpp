#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<long long> p(5);
	for (int i = 0; i < p.size(); ++i)
		p[i] = -1;
	p[1] = 1;

	int n = 2;
	while (true)
	{
		p.push_back(-1);
		p[n] = p[n - 1] + (n / 2);
		if (p[n] % 1000000 == 0)
		{
			cout << n << endl;
			break;
		}
		++n;
	}

	return 0;
}