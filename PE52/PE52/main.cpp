#include <string>
#include <vector>
#include <iostream>
#include "../../helper.h"

using namespace std;

string convert_int_str(int x)
{
	string res = "";
	while (x != 0)
	{
		int temp = x % 10;
		x /= 10;
		res = char('0' + temp) + res;
	}
	return res;
}

int main()
{
	int x = 1;
	while (true)
	{
		string tmp0 = convert_int_str(2 * x);
		string tmp1 = convert_int_str(3 * x);
		string tmp2 = convert_int_str(4 * x);
		string tmp3 = convert_int_str(5 * x);
		string tmp4 = convert_int_str(6 * x);

		sort(tmp0.begin(), tmp0.end());
		sort(tmp1.begin(), tmp1.end());
		sort(tmp2.begin(), tmp2.end());
		sort(tmp3.begin(), tmp3.end());
		sort(tmp4.begin(), tmp4.end());

		if (tmp0 == tmp1 && tmp1 == tmp2 && tmp2 == tmp3 && tmp3 == tmp4)
			cout << x << endl;
		++x;
	}
	return 0;
}