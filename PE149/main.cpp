#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<vector<long long>> graph = {{-2, 5, 3, 2},
                                 {9, -6, 5, 1},
                                 {3, 2, 7, 3},
                                 {-1, 8, -4, 8}};

    auto generate_graph = []() {
        vector<vector<long long>> graph(2000, vector<long long>(2000, 0));
        vector<long long> s(4000000+1, 0);
        long long cntk = 1;
        for(int i=0; i<2000; ++i) {
            for(int j=0; j<2000; ++j) {
                if(cntk <= 55) {
                    graph[i][j] = (100003 - 200003*cntk + 300007*cntk*cntk*cntk) % 1000000 - 500000;
                    s[cntk] = graph[i][j];
                } else {
                    graph[i][j] = (s[cntk-24] + s[cntk-55] + 1000000ll) % 1000000ll - 500000ll;
                    s[cntk] = graph[i][j];
                }

                ++cntk;
            }
        }
        return graph;
    };

    graph = generate_graph();

    auto max_sub_sum = [](const vector<long long> &vec) {
        auto curr = 0ll;
        auto res = vec[0];
        for(const auto &x : vec) {
            curr += x;
            res = max(res, curr);
            if(curr < 0) curr = 0; 
        }
        return res;
    };

    auto generate_diag1 = [](const vector<vector<long long>> &vec) {
        vector<vector<long long>> ans;
        for(int i=0; i<(int)vec.size(); ++i) {
            int currx = i, curry = 0;
            vector<long long> tmp;
            while(currx >= 0 && curry < (int)vec.size()) {
                tmp.push_back(vec[currx--][curry++]);
            }
            ans.push_back(tmp);
        }

        for(int i=1; i<(int)vec.size(); ++i) {
            int currx = vec.size()-1, curry = i;
            vector<long long> tmp;
            while(currx >= 0 && curry < (int)vec.size()) {
                tmp.push_back(vec[currx--][curry++]);
            }
            ans.push_back(tmp);
        }
        return ans;
    };

    auto generate_diag2 = [](const vector<vector<long long>> &vec) {
        vector<vector<long long>> ans;
        for(int i=0; i<(int)vec.size(); ++i) {
            int currx = i, curry = 0;
            vector<long long> tmp;
            while(curry < (int)vec.size() && currx < (int)vec.size()) {
                tmp.push_back(vec[currx++][curry++]);
            }
            ans.push_back(tmp);
        }

        for(int i=1; i<(int)vec.size(); ++i) {
            int currx = 0, curry = i;
            vector<long long> tmp;
            while(currx < (int)vec.size() && curry < (int)vec.size()) {
                tmp.push_back(vec[currx++][curry++]);
            }
            ans.push_back(tmp);
        }
        return ans;
    };

    auto generate_vert = [](const vector<vector<long long>> &vec) {
        vector<vector<long long>> ans;
        for(int i=0; i<(int)vec.size(); ++i) {
            vector<long long> tmp;
            for(int j=0; j<(int)vec[i].size(); ++j) {
                tmp.push_back(vec[j][i]);
            }
            ans.push_back(tmp);
        }
        return ans;
    };


    auto vec = generate_diag1(graph);
    auto vec2 = generate_diag2(graph);
    auto vec3 = generate_vert(graph);

    auto soln = -LLONG_MAX;
    for(auto &arr : vec) {
        soln = max(soln, max_sub_sum(arr));
    }

    for(auto &arr : vec2) {
        soln = max(soln, max_sub_sum(arr));
    }

    for(auto &arr : vec3) {
        soln = max(soln, max_sub_sum(arr));
    }

    for(auto &arr : graph) {
        soln = max(soln, max_sub_sum(arr));
    }

    cout << soln << endl;
    return 0;
}