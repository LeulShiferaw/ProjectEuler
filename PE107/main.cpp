#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

class DSU
{
    private:
        int *parent;
    public:
        DSU(int n);
        int find(int x);
        void unite(int x, int y);
};

DSU::DSU(int n)
{
    parent = new int[n];
    for(int i = 0; i<n; ++i)
        parent[i] = -1;
}

int DSU::find(int x)
{
    if(parent[x] == -1)
        return x;
    return find(parent[x]);
}

void DSU::unite(int x, int y)
{
    int p1 = find(x);
    int p2 = find(y);

    if(p1 != p2)
        parent[p2] = p1; 
}

/*
vector<vector<int>> edges = {{-1, 16, 12, 21, -1, -1, -1},
                             {16, -1, -1, 17, 20, -1, -1},
                             {12, -1, -1, 28, -1, 31, -1},
                             {21, 17, 28, -1, 18, 19, 23},
                             {-1, 20, -1, 18, -1, -1, 11},
                             {-1, -1, 31, 19, -1, -1, 27},
                             {-1, -1, -1, 23, 11, 27, -1}};
*/

vector<vector<int>> edges;

int main()
{
    ifstream file("networks.txt");

    for(int j = 0; j<40; ++j)
    {
        string line = "";
        getline(file, line);

        vector<int> row;
        string new_val = "";
        for(int i=0; i<line.size(); ++i)
        {
            if(line[i] == ',')
            {
                if(new_val == "-")
                    row.push_back(-1);
                else
                    row.push_back(stoi(new_val));
                new_val = "";
            }
            else new_val += line[i];
        }
        if(new_val[0] == '-')
        {
            row.push_back(-1);
        }
        else row.push_back(stoi(new_val));
        edges.push_back(row);
    }

    long long total = 0;
    vector<vector<int>> edgeList;
    for(int i = 0; i<edges.size(); ++i)
    {
        for(int j = i; j<edges.size(); ++j)
        {
            if(edges[i][j] != -1)
            {
                edgeList.push_back({edges[i][j], i, j});
                total += edges[i][j];
            }
        }
    }

    sort(edgeList.begin(), edgeList.end());

    int res = 0;
    DSU dsu(edges.size());
    for(auto edge: edgeList)
    {
        int w = edge[0];
        int x = edge[1];
        int y = edge[2];

        if(dsu.find(x) == dsu.find(y))
            continue;
        dsu.unite(x, y);
        res += w;
    }

    cout << "Total: " << total << endl;
    cout << "New weight: " << res << endl;
    cout << "Saved: " << total-res << endl;
    return 0;
}