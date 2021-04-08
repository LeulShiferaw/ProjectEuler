//Passes the 1 min rule
#include <iostream>

using namespace std;

int main()
{
	int largest = 0;
	int value = -1;
	for (int p = 1; p <= 1000; ++p)
	{
		cout << p << endl;
		int curr = 0;
		for (int a = 1; a <= p; ++a)
		{
			for (int b = a; b <= p; ++b)
			{
				if (a + b >= p)
					break;
				for (int c = b; c <= p; ++c)
				{
					if (a + b + c == p)
					{
						if (a * a + b * b == c * c)
						{
							cout << a << ", " << b << ", " << c << endl;
							++curr;
						}
					}
				}
			}
		}
		if (curr > largest)
		{
			value = p;
			largest = curr;
		}
	}
	cout << largest << endl;
	cout << "Value: " << value << endl;
	return 0;
}