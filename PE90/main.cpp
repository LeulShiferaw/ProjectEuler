#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

/*
    Easy! Just generate all 6 combinations of the 10 elements
    Now do a double for loop on this and check if the two can become
    pairs.
    If they can increment.
    Also start from i+1 for the second one because otherwise you will count twice for some
*/

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for(int i = a; i<b; i++)

using indexed_set =  tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

void display(const vector<int> &v) {
    for(auto x : v) cout << x << " ";
    cout << endl;
}

vector<pi> squares = {{0, 1}, {0, 4}, {0, 9}, {1, 6}, {2, 5}, {3, 6}, {4, 9}, {6, 4}, {8, 1}};
bool isPair(const vector<int> &v1, const vector<int> &v2) //Can be pairs of a dice
{
    unordered_set<int> set_v1, set_v2;
    REP(i, 0, v1.size()) {
        if(v1[i] == 6) set_v1.insert(9);
        if(v1[i] == 9) set_v1.insert(6);
        if(v2[i] == 6) set_v2.insert(9);
        if(v2[i] == 9) set_v2.insert(6);
        set_v1.insert(v1[i]);
        set_v2.insert(v2[i]);
    }

    REP(i, 0, squares.size()) {
        auto temp = set_v1.find(squares[i].first);
        auto temp1 = set_v1.find(squares[i].second);
        auto temp2 = set_v2.find(squares[i].first);
        auto temp3 = set_v2.find(squares[i].second);

        if(temp != set_v1.end())
        {
            if(temp1 != set_v1.end())
            {
                if(temp2 == set_v2.end() && temp3 == set_v2.end()) return false;
            } else {
                if(temp3 == set_v2.end()) return false;
            }
        } else if(temp1 != set_v1.end()) {
            if(temp2 == set_v2.end()) return false;
        } else {
            return false;
        }
    }
    return true;
}

void generate_all(vector<vector<int>> &soln, vector<int> &curr, int start)
{
    if(curr.size() == 6)
    {
        soln.push_back(curr);
        return;
    }

    for(int i = start; i<=9; ++i)
    {
        curr.push_back(i);
        generate_all(soln, curr, i+1);
        curr.pop_back();
    }
}

void solve()
{
    vector<int> curr; 
    vector<vector<int>> soln;
    generate_all(soln, curr, 0);

    int res = 0;
    REP(i, 0, soln.size())
    {
        REP(j, i+1, soln.size())
        {
            if(isPair(soln[i], soln[j])) ++res;
        }
    }
    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}