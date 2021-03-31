#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int name_score(const string &str)
{
    int res = 0;
    for(int i = 1; i<str.size()-1; ++i)
    {
        res += int(str[i] - 'A') + 1;
    }
    return res;
}

void display(const vector<string> &vec)
{
    for(string x : vec)
        cout << x << endl;
}

int main()
{

    ifstream file("names.txt");

    //Get Data
    string name;
    vector<string> names;
    while(getline(file, name, ','))
    {
        names.push_back(name);
    }

    //Sort Data
    sort(names.begin(), names.end());

    //Total results
    long long total = 0;
    for(int i = 0; i<names.size(); ++i)
    {
        total += name_score(names[i]) * i;
    }
    cout << total << endl;

    file.close();
    return 0;
}
