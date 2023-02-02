#include <cmath>
#include <iostream>

using namespace std;

int has_soln(long long a, long long b, long long c)
{
    double p = sqrt(pow(a+b, 2) + c*c);

    if(p == (long long)p)
        return 1;
    return 0;
}

int main()
{
    int M = 2000;
    int res = 0;
    for(int a = 1; a<=M; ++a)
    {
        for(int b = a; b<=M; ++b)
        {
            for(int c = b; c<=M; ++c)
            {
                if(has_soln(a, b, c))
                    ++res;
            }
        }
    }
    cout << res << endl;
    return 0;
}