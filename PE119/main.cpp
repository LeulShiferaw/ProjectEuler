#include <set>
#include <cmath>
#include <tuple>
#include <iostream>

using namespace std;

long long sum_digs(long long n)
{
    long long res = 0;
    while(n!=0)
    {
        res += n%10;
        n/=10;
    }
    return res;
}

bool hasLog(long long sd, long long n)
{
    long long b = sd;
    while(b <= n)
    {
        if(b == n)
            return true;
        b*=sd;
    }
    return false;
}

int main()
{
    set<long long> results;
    for(int i = 2; i<=180; ++i)
    {
        long long ip = i; // i^p for some p initially 1
        long long next = ip*i;
        do
        {
            if(ip >= 10)
            {
                long long sd = sum_digs(ip);
                if(sd == 1)
                {
                    ip*=i;
                    next*=i;
                    continue;
                }
                if(hasLog(sd, ip))
                {
                    results.insert(ip);
                }
            }
            ip*=i;
            next*=i;
        } while(next/i == ip);
    }

    cout << results.size() << endl;
    auto myres = results.begin();
    advance(myres, 29);
    cout << *myres << endl;
    return 0;
}