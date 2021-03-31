//669171001
#include <iostream>

using namespace std;

constexpr int width = 1003;
constexpr int height = 1003;

//Adding one layer to the spiral
void add_layers(int startx, int starty, int count, int layers, int** spr)
{
	int currx = startx, curry = starty;

	//Go right one step
	++count;

	for (int i = 0; i < layers; ++i)
	{
		//Move up the diagonal for a new starting point
		currx = startx - i;
		curry = starty + i;
		
		//Go right one step
		++curry;
		//Go down as far as possible
		while (spr[currx][curry - 1] != 0)
		{
			spr[currx][curry] = count;
			++count;
			++currx;
		}

		//Go left as far as possible
		while (spr[currx - 1][curry] != 0)
		{
			spr[currx][curry] = count;
			++count;
			--curry;
		}

		//Go up as far as possible
		while (spr[currx][curry + 1] != 0)
		{
			spr[currx][curry] = count;
			++count;
			--currx;
		}

		//Go right as far as possible
		while (spr[currx + 1][curry] != 0)
		{
			spr[currx][curry] = count;
			++count;
			++curry;
		}
	}
}

void display_spiral(int **spr)
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			cout << spr[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	//Create spiral array
	int** spiral = new int*[height];
	for (int i = 0; i < height; ++i)
	{
		spiral[i] = new int[width];
	}
	
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			spiral[i][j] = 0;
		}
	}

	int startx = width / 2;
	int starty = height / 2;
	spiral[startx][starty] = 1;


	add_layers(startx, starty, 1, height / 2-1, spiral);

	//display_spiral(spiral);
	long long diagonal_sums = 0;
	for (int i = 0; i < width/*aka size*/; ++i)
	{
		diagonal_sums += (long long)spiral[(height - 1) - i][i] + (long long)spiral[i][i];
	}

	cout << "Result: " << diagonal_sums - spiral[width / 2][height / 2];

	//Delete spiral array
	for (int i = 0; i < height; ++i)
	{
		delete[]spiral[i];
		spiral[i] = NULL;
	}
	delete[]spiral;
	spiral = NULL;
	return 0;
}