#include <bits/stdc++.h>

using namespace std;

int soln[200+5];

void initialize() {
    for(int i=0; i<=200; ++i) {
        soln[i] = -1;
    }
}

int next_highest(int start, int curr, int target) {
    for(int i=start; i>=1; --i) {
        if(soln[i] != -1 && i + curr <= target) return i;
    }
    return 1;
}

int effExp(int target) {
    if(soln[target] != -1) return 0;

    int res = INT_MAX;
    for(int i=1; i<=target/2; ++i) {
        int tmp1 = effExp(i);
        int tmp2 = effExp(target-i);
        res = min(res, tmp1 + tmp2 + 1);
    }
    soln[target] = res;
    return res;
}

int main()
{
    /*
    int res = 0;
    for(int i = 2; i<=200; ++i)
    {   
        initialize();
        soln[1] = 1;
        res += effExp(i);
    }
    */

    initialize();
    soln[1] = 0;
    cout << effExp(4) << endl;
    //cout << res << endl;
    return 0;
}