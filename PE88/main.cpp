#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

vi prime_fac[12010+5];

void initialize_primefac()
{

}

long long value(int n)
{
    long double k = pow(n, (double)n/(n-1));
    return ceil(k);
}

const int sz = 4*1000000;
    vector<int> pr;
    int lp[sz+5];
    bool has_seived = false;
    void seive()
    {
        has_seived = true;
        for (int i = 2; i < sz + 1; ++i)
        {
            if(lp[i] == 0)
            {
                lp[i] = i;
                pr.push_back(i);
            }

            for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i*pr[j] <= sz; ++j)
            {
                lp[i*pr[j]] = pr[j];
            }
        }
    }
    
    bool isPrime(long long n)
    {
        if (!has_seived)
            seive();

        if (n < sz)
        {
            return lp[n] == n;
        }
        else
        {
            long long temp = ceil(sqrt(n));
            for (int i = 0; i < pr.size(); ++i)
            {
                if (pr[i] > temp)
                    break;
                if (n % pr[i] == 0)
                    return false;
            }
            return true;
        }
    }

void solve()
{
    seive();
    cout << isPrime(896) << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}