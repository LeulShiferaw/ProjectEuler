#include <vector>
#include <fstream>
#include <iostream>
#include "../../helper.h"

using namespace std;

bool is_triangle_num(int tn)
{
	if (is_integer((sqrt(8.0 * tn + 1.0) - 1.0) / 2.0))
	{
		return true;
	}
	return false;
}

int sum_char(const string& str)
{
	int res = 0;
	for (char c : str)
		res += c - 'A' + 1;
	return res;
}



int main()
{
	char c;
	fstream file("words.txt", ios::in);

	//Read file to vec words
	bool start = true;
	string curr = "";
	vector<string> words;
	while (file >> c)
	{
		if (c == '"')
		{
			if (start)
			{
				start = !start;
			}
			else
			{
				start = !start;
				words.push_back(curr);
				curr = "";
			}
		}
		else if (c == ',')
			continue;
		else
			curr += c;
	}

	int res = 0;
	for (string str : words)
	{
		if (is_triangle_num(sum_char(str)))
		{
			++res;
		}
	}
	cout << res << endl;
	return 0;
}