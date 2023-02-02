#include <cstring>
#include <iostream>
#include "../helper.h"

using namespace std;

long long countDivisors(long long n)
{
    if(n == 1)
        return 1;
    
    long long res = 1;
    for(int i = 0; i<pr.size(); ++i)
    {
        if(pr[i] > n)
            break;
        
        long long cnt = 1;
        while(n%pr[i] == 0)
        {
            ++cnt;
            n/=pr[i];
        }

        res *= cnt;
    }
    return res;
}

long long cntDivN2(long long n)
{
    if(n == 1)
        return 1;
    
    long long res = 1;
    for(int i = 0; i<pr.size(); ++i)
    {
        if(pr[i] > n)
            break;
        
        long long cnt = 0;
        while(n%pr[i] == 0)
        {
            ++cnt;
            n/=pr[i];
        }

        res *= 2LL*cnt+1LL;
    }
    return res;
}

int Solutions(long long n)
{    
    bool hash[n + 1];
    memset(hash, true, sizeof(hash));
    for (int p = 2; p * p < n; p++)
        if (hash[p] == true)
            for (int i = p * 2; i < n; i += p)
                hash[i] = false;
  
    
    int total = 1;
    for (int p = 2; p <= n; p++) {
        if (hash[p]) {            
            int count = 0;
            if (n % p == 0) {
                while (n % p == 0) {
                    n = n / p;
                    count++;
                }
                total = total * (2*count + 1);
            }
        }
    }
    return total;
} 

int main()
{
    seive();
    long long n = 2;
    while(true)
    {
        if(cntDivN2(n)/2 > 4000000)
        {
            cout << n << endl;
            return 0;
        }
        n++;
    }
    return 0;
}