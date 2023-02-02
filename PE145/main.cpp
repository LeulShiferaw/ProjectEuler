#include <set>
#include <unordered_set>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

bool isOdd(long long n)
{
    if(n==0)
        return false;
    while(n!=0)
    {
        if((n%10)%2==0)
            return false;
        n/=10;
    }
    return true;
}

long long rev(long long n)
{
    long long rev_num = 0;
    while(n!=0)
    {
        rev_num = rev_num*10 + (n%10);
        n/=10;
    }

    return rev_num;
}

int main()
{
    int res = 0;
    for(long long i= 1; i<1000000000; ++i)
    {
        if(i%10 == 0)
            continue;
        if(isOdd(i+rev(i)))
        {
            ++res;
        }
    }
    cout << res << endl;
    return 0;
}