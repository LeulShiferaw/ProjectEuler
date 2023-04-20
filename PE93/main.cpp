#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for(int i = a; i<b; i++);

using indexed_set =  tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

long double eps = 0.001;
int num_ways(vector<long double> arr)
{
    set<long double> res;
    do
    {
        vector<long double> vals;
        vals.PB(arr[0]);

        vector<long double> new_vals;
        for(int i = 1; i<4; ++i)
        {
            new_vals.clear();
            for(long double &x : vals) {
                new_vals.PB(x + arr[i]);
                new_vals.PB(x * arr[i]);
                new_vals.PB(x - arr[i]);
                new_vals.PB(arr[i] - x);
                if(arr[i] != 0 && abs(arr[i]-i) > eps) new_vals.PB(x/arr[i]);
                if(x != 0 && abs(x-i) > eps) new_vals.PB(arr[i]/x);

            }
            vals = new_vals;
        }
        for(int i = 0; i<vals.size(); ++i)
        {
            if(vals[i] <= 0) continue;
            res.insert(vals[i]);
        }
    }while(next_permutation(arr.begin(), arr.end()));

    long double i = 1;
    for(auto &x : res)
    {
        if((ll)x == x)
        {
            if(x != i) break;
            ++i;
        }
    }
    return i-1;
}

void solve()
{
    int res = 0;
    vector<int> v(4);
    vector<int> maxV(4, 0);
    int lim = 9;
    for(int d = 1; d<=lim; ++d)
    {
        for(int c = d+1; c <= lim; ++c) 
        {
            for(int b = c+1; b<=lim; ++b)
            {
                for(int a = b+1; a<=lim; ++a)
                {
                    auto temp = num_ways({(double)d, (double)c, (double)b, (double)a});
                    if(temp > res)
                    {
                        res = temp;
                        maxV = {d, c, b, a};
                    }
                }
            }
        }
    }
    cout << res << endl;
    for(auto x : maxV) cout << x << " ";
    cout << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}