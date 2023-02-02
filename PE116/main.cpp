//Dynamic programming once you get the formula
//This one has a different recurrence than the previous one
#include <iostream>

using namespace std;

constexpr int N = 50;
long long soln[5][N+5];

void initialize()
{
    for(int j = 0; j<5; ++j)
    {
        for(int i = 0; i<N+1; ++i)
        {
            soln[j][i] = -1;
        }
    }

    for(int K = 0; K<5; ++K)
    {
        for(int i = 0; i<K; ++i)
        {
            soln[K][i] = 0;
        }
    }

    for(int i=0; i<5; ++i)
    {
        soln[i][i] = 1;
    }
}

long long f(int K, int n)
{
    if(n<0)
        return 1;
    if(soln[K][n]!=-1)
        return soln[K][n];
    long long res = 0; 
    for(int i = K; i<=n; ++i)
    {
        res += 1+f(K, n-i);
    }
    soln[K][n] = res;
    return res;
}

int main()
{
    initialize();
    cout << f(2, N) + f(3, N) + f(4, N) << endl;
    return 0;
}