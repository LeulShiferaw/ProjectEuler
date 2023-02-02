/*
    Problem 117
    This is just a different form of the previous question.
    You can just combine them, and also you don't have to use any too.
    This makes memoization easier.
 */
#include <iostream>

using namespace std;

constexpr int N = 50;
long long soln[N+5];

void initialize()
{
    for(int i = 0; i<N+1; ++i)
    {
        soln[i] = -1;
    }
    soln[0] = 1;
    soln[1] = 1;
    soln[2] = 2;
}

long long f(int n)
{
    if(n<0)
        return 1;
    if(soln[n]!=-1)
        return soln[n];

    long long res = 1;
    for(int i = 2; i<=n; ++i)
        res += f(n-i);
    for(int i = 3; i<=n; ++i)
        res += f(n-i);
    for(int i = 4; i<=n; ++i)
        res += f(n-i);
    soln[n] = res;
    return res;
}

int main()
{
    initialize();
    cout << f(50) << endl;
    return 0;
}