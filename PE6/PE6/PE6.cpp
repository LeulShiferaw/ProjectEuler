#include <iostream>

using namespace std;

bool is_prime(int n)
{
	if (n % 2 == 0)
		return false;

	int temp = sqrt(n);
	for (int i = 3; i <= temp; i+=2)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{

}
