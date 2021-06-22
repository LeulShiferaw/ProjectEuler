//Key: exp
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

vector<int> read_file()
{
	vector<int> res;
	ifstream file("cipher.txt");

	int num;
	char ch;
	while (true)
	{
		file >> num;
		res.push_back(num);
		if (file >> ch)
			continue;
		else
			break;
	}

	return res;
}

vector<string> generate_keys()
{
	vector<string> res;
	string key = "aaa";
	for (int i = 1; i <= 26; ++i)
	{
		key[0] = 'a' + (i - 1);
		for (int j = 1; j <= 26; ++j)
		{
			key[1] = 'a' + (j - 1);
			for (int k = 1; k <= 26; ++k)
			{
				key[2] = 'a' + (k - 1);
				res.push_back(key);
			}
		}
	}
	return res;
}

vector<int> decypher(const vector<int> &file, string key)
{
	vector<int> res;
	for (int i = 0; i < file.size(); i += 3)
	{
		res.push_back(file[i] xor key[0]);
		if ((i + 1) < file.size())
			res.push_back(file[i + 1] xor key[1]);
		if ((i + 2) < file.size())
			res.push_back(file[i + 2] xor key[2]);
	}
	return res;
}

bool contains_the(const vector<int>& file)
{
	for (int i = 0; i < file.size() - 5; ++i)
	{
		if (file[i] == ' ' && file[i+1] == 't' && file[i + 2] == 'h' && file[i + 3] == 'e' && file[i+4] == ' ')
		{
			return true;
		}
	}
	return false;
}

int main()
{
	vector<int> file = read_file();
	vector<string> keys = generate_keys();
	for (string key : keys)
	{
		vector<int> res = decypher(file, key);
		if (contains_the(res))
		{
			long long result = 0;
			for (int x : res)
			{
				result += x;
			}
			cout << result << endl;
		}
	}
	return 0;
}