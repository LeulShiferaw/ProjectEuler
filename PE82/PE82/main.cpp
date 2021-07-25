#include <fstream>
#include <iostream>

using namespace std;

int soln[80][80];
int mat[80][80];
bool checked[80][80];

int min_path_sum(int i, int j)
{
	if (j == 79)
		return mat[i][j];



}

int main()
{
	ifstream file("file.txt");
	for (int i = 0; i < 80; ++i)
		for (int j = 0; j < 80; ++j)
		{
			int temp;
			file >> temp;

			if (j != 79)
			{
				char c;
				file >> c;
			}

			soln[i][j] = -1;
			mat[i][j] = temp;
			checked[i][j] = false;
		}
	file.close();

}