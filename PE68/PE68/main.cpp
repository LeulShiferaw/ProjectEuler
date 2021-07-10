//Magic-5-gon string
//Name: Leul Shiferaw
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool test(int a, int b)
{
	if (a == b)
		return true;
	return false;
}

int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	string max = "0";

	do
	{
		//Find lowest external node
		int smallest = arr[5];
		int smallest_ind = 5;
		for (int i = 5; i < 10; ++i)
		{
			if (arr[i] < smallest)
			{
				smallest = arr[i];
				smallest_ind = i;
			}
		}

		//Start n-string from lowest external node
		switch (smallest_ind)
		{	
		case 5:
		{
			int standard = arr[5] + arr[0] + arr[1];
			if (test(standard, arr[6] + arr[1] + arr[2]) && test(standard, arr[7] + arr[2] + arr[3]) && test(standard, arr[8] + arr[3] + arr[4]) && test(standard, arr[9] + arr[4] + arr[0]))
			{
				string curr = to_string(arr[5]) + to_string(arr[0]) + to_string(arr[1]) + to_string(arr[6]) + to_string(arr[1]) + to_string(arr[2]) + to_string(arr[7]) + to_string(arr[2])
					+ to_string(arr[3]) + to_string(arr[8]) + to_string(arr[3]) + to_string(arr[4]) + to_string(arr[9]) + to_string(arr[4]) + to_string(arr[0]);
				cout << curr << endl;
				if (curr > max && curr.size() == 16)
					max = curr;
			}
			break;
		}

		case 6:
		{
			int standard = arr[6] + arr[1] + arr[2];
			if (test(standard, arr[5] + arr[0] + arr[1]) && test(standard, arr[7] + arr[2] + arr[3]) && test(standard, arr[8] + arr[3] + arr[4]) && test(standard, arr[9] + arr[4] + arr[0]))
			{
				string curr = to_string(arr[6]) + to_string(arr[1]) + to_string(arr[2]) + to_string(arr[7]) + to_string(arr[2]) + to_string(arr[3]) + to_string(arr[8]) + to_string(arr[3]) + to_string(arr[4]) 
					+ to_string(arr[9]) + to_string(arr[4]) + to_string(arr[0]) + to_string(arr[5]) + to_string(arr[0]) + to_string(arr[1]);
				cout << curr << endl;
				if (curr > max && curr.size() == 16)
					max = curr;
			}
			break;
		}

		case 7:
		{
			int standard = arr[6] + arr[1] + arr[2];
			if (test(standard, arr[5] + arr[0] + arr[1]) && test(standard, arr[7] + arr[2] + arr[3]) && test(standard, arr[8] + arr[3] + arr[4]) && test(standard, arr[9] + arr[4] + arr[0]))
			{
				string curr = to_string(arr[7]) + to_string(arr[2]) + to_string(arr[3]) + to_string(arr[8]) + to_string(arr[3]) + to_string(arr[4])
					+ to_string(arr[9]) + to_string(arr[4]) + to_string(arr[0]) + to_string(arr[5]) + to_string(arr[0]) + to_string(arr[1]) + to_string(arr[6]) + to_string(arr[1]) + to_string(arr[2]);
				cout << curr << endl;
				if (curr > max && curr.size() == 16)
					max = curr;
			}
			break;
		}

		case 8:
		{
			int standard = arr[6] + arr[1] + arr[2];
			if (test(standard, arr[5] + arr[0] + arr[1]) && test(standard, arr[7] + arr[2] + arr[3]) && test(standard, arr[8] + arr[3] + arr[4]) && test(standard, arr[9] + arr[4] + arr[0]))
			{
				string curr = to_string(arr[8]) + to_string(arr[3]) + to_string(arr[4])
					+ to_string(arr[9]) + to_string(arr[4]) + to_string(arr[0]) + to_string(arr[5]) + to_string(arr[0]) + to_string(arr[1]) + to_string(arr[6]) + to_string(arr[1]) + to_string(arr[2])
					+ to_string(arr[7]) + to_string(arr[2]) + to_string(arr[3]);
				cout << curr << endl;
				if (curr > max && curr.size() == 16)
					max = curr;
			}
			break;
		}
		case 9:
		{
			int standard = arr[6] + arr[1] + arr[2];
			if (test(standard, arr[5] + arr[0] + arr[1]) && test(standard, arr[7] + arr[2] + arr[3]) && test(standard, arr[8] + arr[3] + arr[4]) && test(standard, arr[9] + arr[4] + arr[0]))
			{
				string curr = to_string(arr[9]) + to_string(arr[4]) + to_string(arr[0]) + to_string(arr[5]) + to_string(arr[0]) + to_string(arr[1]) + to_string(arr[6]) + to_string(arr[1]) + to_string(arr[2])
					+ to_string(arr[7]) + to_string(arr[2]) + to_string(arr[3]) + to_string(arr[8]) + to_string(arr[3]) + to_string(arr[4]);
				cout << curr << endl;
				if (curr > max && curr.size() == 16)
					max = curr;
			}
			break;
		}
		default:
			cout << "Error in default" << endl;
			return 0;
		}
		
	} while (next_permutation(arr, arr + 10));
	cout << "Max: " << max << endl;
	return 0;
}