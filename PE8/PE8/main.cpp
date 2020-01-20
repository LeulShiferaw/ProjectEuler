#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream file("number.h");
	if (!file.is_open())
		return false;

	//Read into grid
	string str;
	string num = "";
	while (getline(file, str, '\n'))
	{
		num += str;
	}

	int n = 13;
	long long curr = 1;
	long long largest = 1;
	for (int i = 0; i < num.size() - n; ++i)
	{
		curr = 1;
		for (int j = 0; j < n; ++j)
		{
			curr *= num[i + j] - '0';
		}
		if (curr > largest)
			largest = curr;
	}

	cout << largest << endl;

	file.close();
	return 0;
}