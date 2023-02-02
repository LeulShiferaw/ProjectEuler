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
    soln[2] = 1;
    soln[3] = 2;
}

long long f(int n)
{
    if(n<0)
        return 1;
    if(soln[n]!=-1)
        return soln[n];
    int k = n-2;
    long long res = k+1;
    for(int i = k-1; i>0; --i)
    {
        res += i*f(k-1-i);
    }
    soln[n] = res;
    return res;
}

int main()
{
    initialize();
    cout << f(50) << endl;
    return 0;
}