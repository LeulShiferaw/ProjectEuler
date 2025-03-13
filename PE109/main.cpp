#include <bits/stdc++.h>

using namespace std;

/*
    Darts simulation
*/

void solve() {
    vector<pair<int, string>> scores; //All kinds of scores S1, T1, D1 .... 
    for(int i=1; i<=20; ++i) {
        scores.push_back(make_pair(i, "S"));
        scores.push_back(make_pair(i, "D"));
        scores.push_back(make_pair(i, "T"));
    }

    //Bulls-eye
    scores.push_back(make_pair(25, "S"));
    scores.push_back(make_pair(25, "D"));

    //All possible 3 scores, 2 scores, and 1 scores that end with a double
    vector<vector<pair<int, string>>> possible_scores;
    for(auto &x : scores) {
        for(auto &y : scores) {
            for(auto &z : scores) {
                if(z.second != "D") continue;
                possible_scores.push_back({x, y, z});
            }
        }
    }

    for(auto &x : scores) {
        for(auto &y : scores) {
            if(y.second != "D") continue;
            possible_scores.push_back({x, y});
        }
    }

    for(auto &x : scores) {
        if(x.second != "D") continue;
        possible_scores.push_back({x});
    }

    //Calculate the sum of a set of scores
    auto calc_sum  = [&](const vector<pair<int, string>> &in) {
        int soln = 0;
        for(auto &x : in) {
            if(x.second == "S") soln += x.first;
            else if(x.second == "D") soln += 2*x.first;
            else if(x.second == "T") soln += 3*x.first;
            else cerr << "ERROR!" << endl;
        }
        return soln;
    };

    //Calculate the number of solutions that sum to a score
    auto calc = [&](int score) {
        vector<vector<pair<int, string>>> match_scores; //All the scores that sum to score
        for(auto &x : possible_scores) {
            if(calc_sum(x) == score) match_scores.push_back(x);
        }

        //Sort the everything but the last
        //Last should be a fixed double 
        //The rest are interchangeable
        for(auto &x : match_scores) {
            sort(x.begin(), x.end()-1);
        } 

        //Sort the whole set of scores
        sort(match_scores.begin(), match_scores.end());

        //Remove duplicates
        auto itr = unique(match_scores.begin(), match_scores.end());
        match_scores.resize(distance(match_scores.begin(), itr));

        //Return number of solns left after removing duplicates
        return match_scores.size();
    };
   
    //Soln for scores below 100
    int soln = 0;
    for(int i=99; i>=1; --i) soln += calc(i);
    cout << soln << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}