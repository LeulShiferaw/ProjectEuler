#include <tuple>
#include <cmath>
#include <iostream>

using namespace std;

double findC(long long a, long long L)
{
    double res = a*a + (L-a)*(L-a);
    res = (double)res / (double)(2LL*L-2LL*a);
    return res;
}

double findB(long long a, long long c, long long L)
{
    return L-(c+a);
}

bool isLL(double x)
{
    long long llx = x;
    return llx-x == 0;
}

int main()
{
    int res = 0;
    for(int i = 3; i<=1500000; ++i)
    {
        int rat = 0;
        tuple<int, int, int> curr_soln;
        for(int j = 1; j<i; ++j)
        {
            double c = findC(j, i);
            int b = findB(j, c, i);
            if(isLL(c))
            {
                if(c > 0 && b > 0 && j < b)
                {
                    curr_soln = make_tuple(j, b, c);
                    ++rat;
                    if(rat > 1)
                        break;
                }
            }
        }
        if(rat == 1)
        {
            ++res;
        }
    }

    cout << res << endl;

/*
    int num_solns[1500000+5];
    for(int i = 1; i<=1500000; ++i)
    {
        num_solns[i] = 0;
    }

    for(long long i = 3; i<=1500000; ++i)
    {
        cout << i << endl;
        for(long long j=i; j<=1500000; ++j)
        {
            double c = sqrt(i*i + j*j);
            if(j+i+c > 1500000)
                break;

            if(c == (long long)c)
                ++num_solns[j+i+(long long)c];
        }
    }
    */
    return 0;
}