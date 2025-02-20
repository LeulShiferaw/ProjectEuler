#include <bits/stdc++.h>

using namespace std;

/*
Fairly easy problem.
Only imporvement is to use prefix sums instead of bruteforce calculation
*/
int main() {
    vector<vector<long long>> array;
    long long t = 0;
    long long pow2_20 = 1048576;
    long long pow2_19 = pow2_20 / 2;
    int rows = 1000;

    for(int i=0; i<rows; ++i) {
        vector<long long> tmp;
        for(int j=0; j<=i; ++j) {
            t = (615949*t + 797807) % pow2_20;
            tmp.push_back(t-pow2_19);
        }
        array.push_back(tmp);
    }

    auto calc_pos = [&](int i, int j) {
        auto sum = 0ll;
        auto ans = LLONG_MAX;
        for(int k=i; k<rows; ++k) {
            for(int q=0; q<k-i+1; ++q) {
                sum += array[k][q+j];
            }
            ans = min(sum, ans);
        }
        return ans;
    };

    auto ans = LLONG_MAX;
    for(int i=0; i<rows; ++i) {
        for(int j=0; j<(int)array[i].size(); ++j) {
            auto val = calc_pos(i, j);
            ans = min(val, ans);
        }
    }
    cout << ans << endl;
    return 0;
}