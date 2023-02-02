#include <iostream>

using namespace std;

long long num_increasing(int num_dig, int prev)
{
    if(num_dig == 1)
        return 9-prev+1;

    long long res = 0;
    for(int i = prev; i<=9; ++i)
        res += num_increasing(num_dig-1, i);
    return res;
}

long long num_decreasing(int num_dig, int prev)
{
    if(num_dig == 1)
        return prev-0+1;
    
    long long res = 0;
    for(int i = prev; i>=0; --i)
        res+=num_decreasing(num_dig-1, i);
    return res;
}

int main()
{
    long long res = 0;
    for(int i = 9; i>=0; --i)
    {
        res+=num_increasing(2, i) + num_decreasing(2, i);
    }
    res-=28;
    cout << res << endl;
    return 0;
}