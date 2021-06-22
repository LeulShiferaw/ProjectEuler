/*
	Author: Leul Shiferaw
	Project Euler Problem 51
*/
#include <string>
#include <iostream>
#include <assert.h>
#include "../../helper.h"

using namespace std;

bool is_partner(int a, int b)
{
	string str = to_string(abs(b - a));
	sort(str.begin(), str.end());

	if (str[0] != '0')
		return false;
	int i = 0;
	while (str[i] == '0')
	{
		++i;
	}
	++i;
	for (; i < str.size(); ++i)
	{
		if (str[i] != str[i - 1])
			return false;
	}

	return true;
}

void unit_test_partner()
{
	assert(is_partner(56003, 56113));
	assert(is_partner)
}

int main()
{

	return 0;
}