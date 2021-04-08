#include <string>
#include <limits>
#include <vector>
#include <iostream>
#include "../../helper.h"
#include <algorithm>

using namespace std;

template <class T>
void display(const vector<T> &vec)
{
	for (int i = 0; i < vec.size(); ++i)
		cout << vec[i] << endl;
	cout << endl;
}

string convert_int_str(int n)
{
	string str = "";
	while (n != 0)
	{
		str = str + char('0' + (n % 10));
		n /= 10;
	}
	return str;
}

int convert_string_int(string str)
{
	int curr = 1;
	int res = 0;
	for (int i = str.size() - 1; i >= 0; --i)
	{
		res += (str[i] - '0') * curr;
		curr *= 10;
	}
	return res;
}

int main()
{
	string curr_perm = "";
	int longest = 0;
	for (int i = 1; i <= 9; ++i)
	{
		curr_perm += to_string(i);
		vector<string> perms = permutation(curr_perm);
		for (int j = 0; j < perms.size(); ++j)
		{
			int temp = convert_string_int(perms[j]);
			if (isPrime(temp))
			{
				if (temp > longest)
				{
					cout << "Curr Longest: " << temp << endl;
					longest = temp;
				}
			}
		}
	}
	cout << "Longest: " << longest << endl;
	return 0;
}