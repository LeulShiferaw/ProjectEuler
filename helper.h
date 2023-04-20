/*
	Author: Leul Shiferaw
	Helper functions for solving problems
*/
#pragma once

#include <set>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

constexpr int sz = 10000000;
vector<int> pr;
int lp[sz+5];
bool has_seived = false;

long long sum_divisor(const int& n);
void seive();
int num_digs(int n);
int phi(long long n);
int gcd(int a, int b);
int lcm(int a, int b);
bool isPrime(long long n);
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
long long sum_divisor(const int& n)
{
	if (n == 1)
		return 0;
	long long res = 1;
	int start = 2;
	if (n % 2 != 0)
		start = 3;

	for (int i = start; i <= sqrt(n); i += (1 + (start == 3)))
	{
		if (n % i == 0)
		{
			res += (n / i);
			res += i;
		}
	}

	return res;
}

void seive()
{
	has_seived = true;
	for (int i = 2; i < sz + 1; ++i)
	{
	    if(lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }

		for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i*pr[j] <= sz; ++j)
		{
		    lp[i*pr[j]] = pr[j];
		}
	}
}

int num_digs(long long n)
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

int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}

int phi(long long n)
{
	double res = n;

	long long sqrt_n = sqrt(n);
	for (int i = 0; i < pr.size() && pr[i] <= sqrt_n; ++i)
	{
		if (n % pr[i] == 0)
		{
			while (n % pr[i] == 0)
				n /= (long long)pr[i];
			res *= 1.0 - (1.0 / pr[i]);
		}
	}

	if (n > 1)
	{
		res *= 1.0 - (1.0 / n);
	}

	return res;
}

bool isPrime(long long n)
{
	if (!has_seived)
		seive();

	if (n < sz)
	{
		return lp[n] == n;
	}
	else
	{
		long long temp = ceil(sqrt(n));
		for (int i = 0; i < pr.size(); ++i)
		{
			if (pr[i] > temp)
				break;
			if (n % pr[i] == 0)
				return false;
		}
		return true;
	}
}

void primeFactors(int n, vector<int> &primeFac)
{
	if(!has_seived)
		seive();

	if(n<sz)
	{
		if(lp[n] == n)
		{
			primeFac.push_back(n);
			return;
		}
	}
	long long temp = ceil(sqrt(n));
	for(int i = 0; i<pr.size(); ++i)
	{
		if(pr[i] > temp)
			break;
		if(n%pr[i] == 0)
		{
			primeFactors(n/pr[i], primeFac);
			primeFac.push_back(pr[i]);
			return;
		}		
	}
}

void primeFactors(int n, set<int> &primeFac)
{
	if(!has_seived)
		seive();

	if(n<sz)
	{
		if(lp[n] == n)
		{
			primeFac.insert(n);
			return;
		}
	}
	long long temp = ceil(sqrt(n));
	for(int i = 0; i<pr.size(); ++i)
	{
		if(pr[i] > temp)
			break;
		if(n%pr[i] == 0)
		{
			primeFactors(n/pr[i], primeFac);
			primeFac.insert(pr[i]);
			return;
		}		
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

vector<string> permutation(string str)
{
	sort(str.begin(), str.end());

	vector<string> res;
	do
	{
		res.push_back(str);
	} while (next_permutation(str.begin(), str.end()));

	return res;
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
