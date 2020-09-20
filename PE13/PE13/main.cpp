#include <deque>
#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	ifstream file("numbers.txt");

	string numbers[100];
	for (int i = 0; i < 100; ++i)
	{
		file >> numbers[i];
	}

	deque<int> res;
	int remainder = 0; 
	for (int i = 49; i >= 0; --i)
	{
		long long sum = remainder;
		for (int j = 0; j < 100; ++j)
		{
			sum += numbers[j][i] - '0';
		}
		if (i <= 10)
		{
			if (i == 0)
				res.push_front(sum);
			else
				res.push_front(sum % 10);
		}
		remainder = sum / 10;
	}

	for (int x : res)
	{
		cout << x;
	}

	file.close();
	return 0;
}