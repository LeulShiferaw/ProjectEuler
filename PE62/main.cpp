#include <map>
#include <cmath>
#include <vector>
#include <climits>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int num_dig(long long num)
{
    return floor(log10(num)) + 1;
}

string sortedString(long long n)
{
    stringstream ss;
    ss << n;
    string str = ss.str();
    sort(str.begin(), str.end());
    return str;
}

int main()
{
    map<string, vector<int>> cubes;
    long long n = 1;
    long long res = INT_MAX;
    while(true)
    {
        long long curr_cube = n*n*n;
        string strSortCube = sortedString(curr_cube);
        if(cubes.find(strSortCube) != cubes.end())
        {
            cubes[strSortCube].push_back(n);
            if(cubes[strSortCube].size() == 5)
            {
                for(int i = 0; i<cubes[strSortCube].size(); ++i)
                {
                    cout << cubes[strSortCube][i] << " ";
                    res = min(res, (long long)cubes[strSortCube][i]);
                }
                cout << endl;
                cout << "min: " << res*res*res << endl;
            }
        }
        else
        {
            vector<int> temp(1);
            temp[0] = n;
            cubes[strSortCube] = temp;
        }
        ++n;
    }
    return 0;
}