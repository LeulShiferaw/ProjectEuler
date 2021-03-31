#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<double> log_a_pow_b;
	for (int a = 2; a <= 100; ++a)
	{
		for (int b = 2; b <= 100; ++b)
		{
			log_a_pow_b.insert(b * log10(a));
		}
	}
	cout << log_a_pow_b.size() << endl;
}