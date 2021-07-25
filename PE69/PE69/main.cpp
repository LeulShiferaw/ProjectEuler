#include <iostream>
#include "../../helper.h"

using namespace std;

int main()
{
	seive();
	double res = -1;
	int ind = 1;
	for (int i = 1; i <= 1000000; ++i)
	{
		double curr = (double)i / phi(i);
		if (curr > res)
		{
			res = curr;
			ind = i;
		}
	}
	cout << ind << endl;
}