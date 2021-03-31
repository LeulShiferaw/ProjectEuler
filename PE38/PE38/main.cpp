#include <string>
#include <iostream>
#include <algorithm>
#include "../../helper.h"

using namespace std;

bool is_pandig(string n)
{
	sort(n.begin(), n.end());
	if (n[0] != '1')
		return false;

	for (int i = 1; i < n.size(); ++i)
	{
		if (n[i] != n[i - 1] + 1)
			return false;
	}
	return true;
}

string get_value(int n)
{
	int curr = 1;
	string val = "";
	while (val.size() < 9)
	{
		val += to_string(n * (curr++));
	}
	return val;
}

int main()
{

	int i = 1; 
	if (is_pandig(get_value(1)))
		cout << "True" << endl;
	while (true)
	{
		string temp = get_value(i);
		if (is_pandig(temp))
			cout << i << ", " << temp << endl;
		++i;
	}

	return 0;
}