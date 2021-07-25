/*
	Author: Leul Shiferaw
	Helper functions for solving problems
*/
#pragma once

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

constexpr int sz = 1000000;
bool is_prime[sz + 5];
vector<int> primes;
bool has_seived = false;

void seive();
int num_digs(int n);
int phi(long long n);
int gcd(int a, int b);
bool isPrime(int n);
bool is_long(double n);
bool is_integer(double n);
bool is_pandigital(long long n);
int convert_string_int(const string&);
long long convert_str_ll(const string&);
//helper functions for permutation
vector<string> add_everywhere(const char& c, vector<string> perms);
vector<string> add_everywhere(const char& c, string str);
vector<string> permutation(string str);

template <class T>
void display(const vector<T>& vec);


//Implementation
void seive()
{
	has_seived = true;
	is_prime[1] = false;
	for (int i = 2; i < sz + 1; ++i)
	{
		is_prime[i] = true;
	}

	for (long long i = 2; i < sz + 1; ++i)
	{
		if (is_prime[i])
			primes.push_back(i);
		for (long long j = i * i; j < sz + 1; j += i)
		{
			is_prime[j] = false;
		}
	}
}

int num_digs(int n)
{
	return floor(log10(n)) + 1;
}

int gcd(int a, int b)
{
	if (b < a)
		swap(a, b);

	if (a == 0)
		return b;

	return gcd(a, b % a);
}

int phi(long long n)
{
	double res = n;

	long long sqrt_n = sqrt(n);
	for (int i = 0; i < primes.size() && primes[i] <= sqrt_n; ++i)
	{
		if (n % primes[i] == 0)
		{
			while (n % primes[i] == 0)
				n /= (long long)primes[i];
			res *= 1.0 - (1.0 / primes[i]);
		}
	}
	
	if (n > 1)
	{
		res *= 1.0 - (1.0 / n);
	}
	
	return res;
}

bool isPrime(int n)
{
	if (!has_seived)
		seive();

	if (n < sz)
	{
		return is_prime[n];
	}
	else
	{
		int temp = ceil(sqrt(n));
		for (int i = 0; i < primes.size(); ++i)
		{
			if (primes[i] > temp)
				break;
			if (n % primes[i] == 0)
				return false;
		}
		return true;
	}
}

bool is_integer(double n)
{
	return int(n) == n;
}

bool is_long(double n)
{
	return (long long)n == n;
}

bool is_pandigital(long long n)
{
	string str = to_string(n);
	sort(str.begin(), str.end());
	for (int i = 1; i <= n; ++i)
	{
		if (str[i] - '0' != 1)
			return false;
	}
	return true;
}

int convert_string_int(const string& str)
{
	int curr = 1;
	int res = 0;
	for (int i = str.size() - 1; i >= 0; --i)
	{
		res += curr * (str[i] - '0');
		curr *= 10;
	}
	return res;
}

long long convert_string_ll(const string& str)
{
	long long res = 0;
	long long curr = 1;
	for (int i = str.size() - 1; i >= 0; --i)
	{
		res += curr * (str[i] - '0');
		curr *= 10;
	}
	return res;
}

vector<string> add_everywhere(const char& c, vector<string> perms)
{
	vector<string> res;
	for (int i = 0; i < perms.size(); ++i)
	{
		string str = "";
		for (int j = 0; j < perms[i].size(); ++j)
		{
			str = perms[i].substr(0, j) + c + perms[i].substr(j, perms[i].size() - j);
			res.push_back(str);
		}
		res.push_back(perms[i] + c);
	}
	return res;
}

vector<string> add_everywhere(const char& c, string str)
{
	vector<string> res;
	string strng = "";
	for (int i = 0; i < str.size(); ++i)
	{
		strng = str.substr(0, i) + c + str.substr(i, str.size() - i);
		res.push_back(strng);
	}
	res.push_back(str + c);
	return res;
}

vector<string> permutation(string str)
{
	if (str.size() == 1)
	{
		vector<string> vec;
		vec.push_back(str);
		return vec;
	}

	return add_everywhere(str[0], permutation(str.substr(1, str.size() - 1)));

}

template <class T>
void display(const vector<T>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << endl;
	}
	cout << endl;
}