#include <set>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

//When the n is odd you can calculate that the only term that matters
//is 2na which is the last term
//When n is even it is only 2t 
long long my_remainder(long long a, long long n)
{
    if(n%2 == 0)
    {
        return (2) % (a*a);
    }
    else {
        return (2ll*n*a) % (a*a);
    }
}

int main()
{  
    long long res = 0;
    for(long long a = 3; a<=1000; ++a)
    {
        long long uniq = my_remainder(a, 3);
        long long mx = max(2LL, uniq);
        for(long long i = 5; true; i+=2)
        {
            long long temp = my_remainder(a, i);
            mx = max(mx, temp);
            if(temp == uniq)
                break;
        }
        res += mx;
    }
    cout << "ANS: " << res << endl;
}
