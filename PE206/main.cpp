#include <iostream>

using namespace std;

bool is_correct(long long &sqr)
{
    for(int i=9; i>=1; --i)
    {
        if(sqr%10 != i)
            return false;
        sqr/=100;
    }
    if(sqr != 0)
        return false;
    return true;
}

int main()
{
    long long MX = 138902662+1;

    for(long long i = 1; i<=MX; i++)
    {
        long long sqr = i*i;
        if(is_correct(sqr))
        {
            cout << i << endl;
            cout << i*i << endl;
            return 0;
        }
    }
    return 0;
}