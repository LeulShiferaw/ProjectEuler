#include <iostream>

using namespace std;

int main()
{
	for (int c = 1000; c >= 0; --c)
	{
		for (int b = c - 1; b >= 0; --b)
		{
			for (int a = b - 1; a >= 0; --a)
			{
				if (a + b + c == 1000)
				{
					if (a * a + b * b == c * c)
					{
						cout << a * b * c << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << "Failed" << endl;
	return 0;
}