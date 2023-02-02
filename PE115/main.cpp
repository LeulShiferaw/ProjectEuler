//Dynamic programming once you get the formulat
//k = n-2
//f(n) = k*f(-1)+(k-1)*f(0)+(k-2)*f(1) ... 1*f(k) + 1
#include <iostream>

using namespace std;

int K = 50;
constexpr int N = 1000000;
long long soln[N+5];

void initialize()
{
    for(int i = 0; i<N+1; ++i)
    {
        soln[i] = -1;
    }
    for(int i = 0; i<K; ++i)
        soln[i] = 1;
    soln[K] = 2;
}

long long f(int n)
{
    if(n<0)
        return 1;
    if(soln[n]!=-1)
        return soln[n];
    int k = n-(K-1);
    long long res = k+1; //Plus one for the case with no red tiles and k for the first one (k-1)*f(-1), where f(-1) = 1
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
    for(int n = 50;;++n)
    {
        cout << f(n) << endl;
        if(f(n) > 1000000)
        {
            cout << n << endl;
            break;
        }
    }
    return 0;
}