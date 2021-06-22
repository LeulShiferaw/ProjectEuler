//Project EUler 58

#include <iostream>
#include "../../helper.h"

using namespace std;

int main()
{
	int num_primes = 0;
	int tot_diag = 1;
	int curr_length = 1;
	long long curr = 1;
	int incr = 2;
	while (true)
	{
		for (int i = 0; i < 4; ++i)
		{
			curr += incr;
			if (isPrime(curr))
				++num_primes;
			++tot_diag;
		}
		curr_length += 2;
		incr += 2;
		
		cout << curr << endl;
		//cout << "Prime: " << num_primes << endl;
		//cout << "Tot: " << tot_diag << endl;
		if (100*((double)num_primes / (double)tot_diag) < 10)
		{
			cout << curr_length << endl;
			break;
		}
	}
	return 0;
}