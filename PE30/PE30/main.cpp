#include <iostream>
#include <stack>

using namespace std;

bool digits_equal(stack<int> digits, long long sum)
{
	while (!digits.empty())
	{
		if (digits.top() != sum % 10)
			return false;
		sum /= 10;
		digits.pop();
	}

	return true;
}

void print_digits(stack<int> digits)
{
	if (digits.empty())
		return;
	int x = digits.top();
	digits.pop();
	print_digits(digits);
	cout << x;
	digits.push(x);
}

void nth_pwr_sum(stack<int> digits, const int &depth, int curr, long long sum, long long &res, const int &n)
{
	if (curr == depth)
	{
		if (digits_equal(digits, sum))
		{
			print_digits(digits);
			cout << endl;
			cout << "Sum: " << sum << endl;
			res += sum;
			cout << "Result: " << res << endl;
		}
		return;
	}

	for (int i = 0; i < 10; ++i)
	{
		digits.push(i);
		nth_pwr_sum(digits, depth, curr + 1, sum + pow(i, n), res, n);
		digits.pop();
	}
}

int main()
{
	int dep = 7;
	long long res = 0;
	nth_pwr_sum(stack<int>(), dep, 0, 0, res, 5);
	cout << endl;
	cout << res << endl;
}