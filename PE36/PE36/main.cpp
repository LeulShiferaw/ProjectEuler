#include <iostream>
#include <string>

using namespace std;

bool is_palindromic(const string& str)
{
	int len = str.size() / 2;
	for (int i = 0; i < len; ++i)
	{
		if (str[i] != str[str.size() - 1 - i])
			return false;
	}
	return true;
}

string convert_to_binary(int n)
{
	string res = "";
	do
	{
		if ((n & 1) == 0)
		{
			res += "0";
		}
		else
			res += "1";
		n = (n >> 1);
	} while (n > 0);

	return res;
}

int main()
{
	int res = 0;
	
	for (int i = 1; i < 1000000; ++i)
	{
		if (is_palindromic(to_string(i)) && is_palindromic(convert_to_binary(i)))
		{
			res += i;
		}
	}
	cout << res << endl;
	return 0;
}