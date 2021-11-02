#include <iostream>
#include "../../helper.h"

using namespace std;

int main()
{
	seive();
	long long res = 0;
	int ind = 1;
	for (int i = 2; i <= 1000000; ++i)
	{
		res += phi(i);
		/*double curr = (double)i / phi(i);
		if (curr > res)
		{
			res = curr;
			ind = i;
		}
		*/
	}
	cout << res << endl;
}