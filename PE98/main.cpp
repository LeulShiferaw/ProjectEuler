#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

map<string, vector<string>> anagrams;

bool are_anagrams(string s1, string s2)
{
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if(s1 == s2)
        return true;
    return false;
}

int main()
{
    ifstream file("anagrams.txt");

    char c;
    vector<string> words;
    while(file >> c)
    {
        string str = "";
        if(c == '"')
        {
            getline(file, str, '"');
            words.push_back(str);
        }
        else if(c == ',')
            continue;
    }

    int res = 0;
    for(int i = 0; i<words.size(); ++i)
    {
        for(int j = i+1; j<words.size(); ++j)
        {
            if(are_anagrams(words[i], words[j]))
            {
                ++res;
            }
        }
    }
    cout << res << endl;
    return 0;
}