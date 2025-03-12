#include <bits/stdc++.h>

using namespace std;

/*
    The answer is off by one and I don't know why!!

    DP solution to calculate the answer
*/

constexpr int SIZE = 6;

void solve() {
    vector<vector<long long>> dp_increase(10, vector<long long>(SIZE, -1));
    vector<vector<long long>> dp_decrease(10, vector<long long>(SIZE, -1));

    function<long long(int, int)> calc_increase = [&](int prev, int ind) -> long long {
        if(ind >= SIZE) {
            return 1;
        }
        
        if(dp_increase[prev][ind] != -1) return dp_increase[prev][ind];
        long long soln = 0;
        for(int i=prev; i<10; ++i) {  //Start from previous and go up
            soln += calc_increase(i, ind+1);
        }
        dp_increase[prev][ind] = soln;
        return soln;
    };

    function<long long(int, int)> calc_decrease = [&](int prev, int ind) -> long long {
        if(ind >= SIZE) {
            return 1;
        }
        
        if(dp_decrease[prev][ind] != -1) return dp_decrease[prev][ind];
        long long soln = 0;
        for(int i=prev; i>=0; --i) { //Decrement from previous and go down
            soln += calc_decrease(i, ind+1);
        }
        dp_decrease[prev][ind] = soln;
        return soln;
    };

    auto val1 = calc_increase(0, 0);
    long long val2 = 0;
    for(int i=0; i<SIZE; ++i) {
        val2 += calc_decrease(9, i) - 1; //Subtract one because 0 is calculated each time the leading number is 0. This is also why this loop exists because it doesn't go from 100 -> 99 but straight to 0
    }
    cout << "Increase: " << val1 << endl;
    cout << "Decrease: " << val2 << endl;
    cout << "Total: " << val1 + val2 - 9*SIZE  << endl; //0 is removed now subtract 1->9 for each possible number of digits. This will delete 11->22->...->99 for example.
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}