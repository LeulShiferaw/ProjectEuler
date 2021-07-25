#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	int line = 0;
	int curr_line = 1;
	double greatest = -1;
	ifstream file("file.txt");
	while (true)
	{
		long long b, e;
		if (file >> b)
		{
			char c;
			file >> c;
			file >> e;
			double curr = log10(b) * (double)e;
			if (curr > greatest)
			{
				greatest = curr;
				line = curr_line;
			}
		}
		else
			break;
		++curr_line;
	}
	printf("%d\n", line);
	return 0;
}