#include <iostream>
#include <string>

using namespace std;

//Must be a number char
int num_char_to_int(char c)
{
	return c - '0';
}
int main()
{
	string str = "0";
	for (int i = 1; i < 1000000; ++i)
		str += to_string(i);
	cout << "Ans: " << num_char_to_int(str[1]) * num_char_to_int(str[10]) * num_char_to_int(str[100]) * num_char_to_int(str[1000]) * num_char_to_int(str[10000]) * num_char_to_int(str[100000])
			* num_char_to_int(str[1000000]) << endl;
	return 0;
}