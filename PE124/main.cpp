#include <iostream>
#include "../helper.h"

using namespace std;

int main()
{   
    seive();
    vector<pair<int, int>> res;
    res.push_back(make_pair(1, 1));
    for(int i = 2; i<=100000; ++i)
    {
        set<int> temp;
        primeFactors(i, temp);

        int mult = 1;
        for(auto x : temp)
            mult*=x;
        res.push_back(make_pair(mult, i));
    }

    
    sort(res.begin(), res.end());
    for(auto x : res)
    {
        cout << x.first << " " << x.second << endl;
    }

    cout << res[10000-1].second << endl;
    
    return 0;
}