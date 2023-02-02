#include <set>
#include <queue>
#include <vector>
#include <iostream>
#include "../helper.h"

using namespace std;

constexpr int N = 70;
constexpr int NP = 100;
int DP[NP+5][N+5];

void initialize()
{
    for(int i = 0; i<NP+5; ++i)
    {
        for(int j = 0; j<N+5; ++j)
            DP[i][j] = -1;
    }
}

void display(const vector<int> &vec)
{
    for(int x : vec)
        cout << x << " ";
    cout << endl;
}

int num_ways(const vector<int> &primes, int s, int e, int n)
{
    if(n == primes[s])
        return 1;
    else if(n < primes[s])
        return 0;

    if(n == 0)
    {
        cout << "Red alert" << endl;
        return 0;
    }
    else if(n < 0)
        return 0;
    
    if(s == e-1)
    {
        if(n == primes[s])
            return 1;
        return 0;
    }

    int num1 = 0;
    if(DP[s][n-primes[s]] != -1)
        num1 = DP[s][n-primes[s]];
    else
    {
        num1 = num_ways(primes, s, e, n-primes[s]);
        DP[s][n-primes[s]] = num1;
    }

    int num2 = 0;
    if(DP[s+1][n] != -1)
        num2 = DP[s+1][n];
    else 
    {
        num2 = num_ways(primes, s+1, e, n);
        DP[s+1][n] = num2;
    }

    return num1 + num2;
}

int binarySearch(int s, int e)
{
    if(s == e-2)
    {
        int temp = num_ways(pr, 0, NP, s);
        int temp0 = num_ways(pr, 0, NP, s+1);
        if(temp > 5000)
            return s;
        else if(temp0 > 5000)
            return s+1;
    }
    else if(s == e-1)
    {
        if(num_ways(pr, 0, NP, s) > 5000)
            return s;
        else return -1;
    }

    int m = (s+e)/2;
    int first = num_ways(pr, 0, NP, m);
    int second = num_ways(pr, 0, NP, m-1);
    if(first > 5000 && second < 5000)
        return m;
    if(first < 5000)
        return binarySearch(m, e);
    return binarySearch(s, m);
}

int main()
{
    seive();
    initialize();

    vector<int> curr_primes;
    cout <<  num_ways(pr, 0, 1000, 1000) << endl;
    return 0;
}