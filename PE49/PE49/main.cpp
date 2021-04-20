/*
	Author: Leul Shiferaw
	Project Euler Problem 49
*/
#include <iostream>
#include "../../helper.h"

using namespace std;

//Return the unique elements assuming vec is sorted
vector<int> unique_vec(const vector<int>& vec)
{
	vector<int> res;
	for (int i = 0; i < vec.size(); ++i)
	{
		if (i == 0)
			res.push_back(vec[i]);
		else if (vec[i] != vec[i - 1])
			res.push_back(vec[i]);
	}
	return res;
}

int main()
{
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			for (int k = 0; k <= 9; ++k)
			{
				for (int h = 0; h <= 9; ++h)
				{
					int curr_value = -1;
					string str = to_string(i) + to_string(j) + to_string(k) + to_string(h); //Convert conactenation of ijkh to string
					vector<string> perms = permutation(str);//Find permuations
					vector<int> res;
					for (int i = 0; i < perms.size(); ++i)
					{
						int temp = convert_string_int(perms[i]);
						if (isPrime(temp) && ((temp % 1000) != (temp % 10000))) //If is prime and 4 digit
						{
							if (curr_value == -1)
							{
								res.push_back(temp);
								curr_value = temp;
							}
							else if (abs(temp - curr_value) == 3330)//And their difference is 3330 add to vector
							{
								curr_value = temp;
								res.push_back(temp);
							}
						}
					}

					if (res.size() >= 3)//If the number of primes is 3 or greater
					{
						sort(res.begin(), res.end());
						res = unique_vec(res);
						for (int i = 0; i < res.size(); ++i)
							cout << res[i] << " ";
						cout << endl;
					}
				}
			}
		}
	}
	return 0;
}