#include <iostream>

using namespace std;

int main()
{
	/*
		A simpler way to do would be to not even use a computer and calculate
	*/	
	int sum = 0;
	for(int i=1; i<1000; ++i)
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
	cout << sum << endl;//Print function for C++
	return 0;
}