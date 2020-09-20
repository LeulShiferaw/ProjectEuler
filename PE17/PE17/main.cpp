#include <string>
#include <iostream>

using namespace std;

string num_letters[1001];

int main()
{
	num_letters[1] = "one";
	num_letters[2] = "two";
	num_letters[3] = "three";
	num_letters[4] = "four";
	num_letters[5] = "five";
	num_letters[6] = "six";
	num_letters[7] = "seven";
	num_letters[8] = "eight";
	num_letters[9] = "nine";
	num_letters[10] = "ten";
	num_letters[11] = "eleven";
	num_letters[12] = "twelve";
	num_letters[13] = "thirteen";
	num_letters[14] = "fourteen";
	num_letters[15] = "fifteen";
	num_letters[16] = "sixteen";
	num_letters[17] = "seventeen";
	num_letters[18] = "eighteen";
	num_letters[19] = "nineteen";
	num_letters[20] = "twenty";
	num_letters[30] = "thirty";
	num_letters[40] = "forty";
	num_letters[50] = "fifty";
	num_letters[60] = "sixty";
	num_letters[70] = "seventy";
	num_letters[80] = "eighty";
	num_letters[90] = "ninety";
	num_letters[1000] = "onethousand";

	for (int i = 20; i <= 90; i += 10)
	{
		for (int j = 1; j < 10; ++j)
		{
			num_letters[i + j] = num_letters[i] + num_letters[j];
		}
	}

	for (int i = 100; i < 1000; ++i)
	{
		if (i % 100 == 0)
		{
			num_letters[i] = num_letters[i / 100] + "hundred";
		}
		else
		{

			num_letters[i] = num_letters[i / 100] + "hundred" + "and" + num_letters[i % 100];
		}
	}

	long long res = 0;
	for (int i = 1; i <= 1000; ++i)
	{
		res += num_letters[i].size();
	}

	cout << res << endl;

	return 0;
}