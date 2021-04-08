#include <iostream>
#include "../../helper.h"

using namespace std;

int div_primes[10] = { 2, 3, 5, 7, 11, 13, 17 };

//For ten digit string numbers only
bool is_sub_str_div(string str)
{
	for (int i = 1; i <= 7; ++i)
	{
		if (convert_string_int(str.substr(i, 3)) % div_primes[i - 1] != 0)
			return false;
	}
	return true;
}

int main()
{
	long long res = 0;
	string str = "9876543210";
	do
	{
		if (is_sub_str_div(str))
		{
			cout << str << endl;
			res += convert_string_ll(str);
			cout << convert_string_ll(str) << endl;
		}
		prev_permutation(str.begin(), str.end());
	} while (str != "0123456789");
	cout << "Result: " << res << endl;

}