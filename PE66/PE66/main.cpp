//Just follow the algorithm in the problem statement, but do it without calculating the value but rather storing the formula. That way you don't lose precision
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <algorithm>

using namespace std;
using namespace boost::multiprecision;

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
	int val = (std::sqrt(t_sqrt) + t_val) / (float)den;
	t_val -= den * val;
	return val;
}

void display(const vector<int>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
		cout << vec[i] << " ";
	cout << endl;
}

//this returns the lth value from the vector vec.
int lth(const int& l, const vector<int>& vec)
{
	if (l == 0)
		return vec[0];

	return vec[1 + ((l - 1) % (vec.size() - 1))]; //1 + ((l-1) % period) where l is the lth value
}

pair<cpp_int, cpp_int> get_lth_value(int l, const vector<int>& vec)
{
	cpp_int  n = 1;
	cpp_int  d = lth(l, vec);

	for (int i = l - 1; i >= 1; --i)
	{
		long long curr = lth(i, vec);
		n = curr * d + n; //Compute curr + (n/d)
		swap(n, d);//This is the reciprocal part after the computation
	}
	n = lth(0, vec) * d + n;

	return make_pair(n, d);
}

pair<cpp_int , cpp_int> get_min_soln(const vector<int>& vec)
{
	int lth = 0;
	if ((vec.size() - 1) % 2 == 0)
		lth = (vec.size() - 1) - 1;
	else
		lth = 2 * (vec.size() - 1) - 1;

	return get_lth_value(lth, vec);
}

int main()
{
	cpp_int largest = -1;
	cpp_int d_value = -1;
	for (int i = 2; i <= 1000; ++i)
	{
		if (floor(std::sqrt(i)) == std::sqrt(i))
			continue;

		vector<int> values; //Stores a0, a1, ... an

		value curr_val(i, 0, 1); //Calculates a0, a1, ... an
		int temp = curr_val.extract();

		values.push_back(temp);

		value first_val = curr_val;
		while (true)
		{
			curr_val.step();
			temp = curr_val.extract();

			values.push_back(temp);

			if (curr_val.t_sqrt == first_val.t_sqrt && curr_val.t_val == first_val.t_val && curr_val.den == first_val.den)
				break;
		}
		auto soln = get_min_soln(values);
		if (soln.first > largest)
		{
			largest = soln.first;
			d_value = i;
		}
	}
	cout << largest << endl;
	cout << d_value << endl;
	return 0;
}