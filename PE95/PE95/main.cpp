//Doesn't work accurately because the answer doesn't complete till 1000000 in less than 60 seconds, but the best answer you get in like the first 20 seconds is 
//the actual answer.
#include <set>
#include <iostream>
#include "../../helper.h"

using namespace std;

int main()
{
	seive();
	int largest = -1;
	int res = 0;

	for (int i = 1; i < 1000000; ++i)
	{
		if (isPrime(i))
			continue;
		long long start = i;
		long long curr = start;
		int chain_len = 0;
		set<long long> found;
		do
		{
			curr = sum_divisor(curr);
			++chain_len;
			if (found.find(curr) != found.end() || curr >= 1000000 || curr == 0)
			{
				chain_len = -1;
				break;
			}
			found.insert(curr);
		} while (curr != start);

		if (chain_len > largest)
		{
			res = i;
			largest = chain_len;
			cout << res << endl;
			cout << largest << endl;
		}
	}

	cout << res << endl;
	return 0;
}