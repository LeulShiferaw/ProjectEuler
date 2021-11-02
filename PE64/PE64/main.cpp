//Just follow the algorithm in the problem statement, but do it without calculating the value but rather storing the formula. That way you don't lose precision
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class value
{
public:
	int t_sqrt;
	int t_val;
	int den;
public:
	value(const int& ts, const int& tv, const int& d)
	{
		t_sqrt = ts;
		t_val = tv;
		den = d;
	}

	void step();
	int extract();
};

void value::step()
{
	den = (t_sqrt - t_val * t_val) / (float)den;
	t_val = -t_val;
}

int value::extract()
{
	int val = (sqrt(t_sqrt) + t_val) / (float)den;
	t_val -= den * val;
	return val;
}

void display(const vector<int>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
		cout << vec[i] << " ";
	cout << endl;
}

int main()
{
	int res = 0;
	for (int i = 2; i <= 10000; ++i)
	{
		if (floor(sqrt(i)) == sqrt(i))
			continue;
		value curr_val(i, 0, 1);
		cout << curr_val.extract();

		value first_val = curr_val;
		int period = 0;
		while (true)
		{
			cout << ", ";
			curr_val.step();
			int temp = curr_val.extract();
			cout << temp;
			++period;
			if (curr_val.t_sqrt == first_val.t_sqrt && curr_val.t_val == first_val.t_val && curr_val.den == first_val.den)
				break;
		}
		cout << endl;
		if (period % 2 == 1)
			++res;
	}

	cout << res << endl;
	return 0;
}