#include <math.h>
#include <iostream>

using namespace std;

int soln[200+5];

int effExp(int n)
{
    for(int i = 3; i<=n; ++i)
    {
        int minExp = INT_MAX;
        for(int j = 1; j<=i/2; ++j)
        {
            minExp = min(minExp, effExp[j]+effExp)
        }
    }
}

int main()
{
    for(int i = 0; i<=200; ++i)
    {
        soln[i] = 0;
    }

    int n = 15;
    cout << effExp(n);
    return 0;
}