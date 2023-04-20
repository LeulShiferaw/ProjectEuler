#include <bits/stdc++.h>

using namespace std;

map<string, vector<string>> anagrams;
int max_square = 31622;
vector<int> squares;

bool are_anagrams(string s1, string s2)
{
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if(s1 == s2)
        return true;
    return false;
}

vector<int> getDigts(int n)
{
    vector<int> res;
    while(n != 0)
    {
        res.push_back(n%10);
        n/=10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int num_dig(int n)
{
    return floor(log10(n)) + 1;
}

bool isInt(double x)
{
    if(x == (int)x) return true;
    return false;
}

int max_res = 0;
bool anagram_sq_pairs(const string &w1, const string &w2, vector<int> &&digs)
{
    assert(w1.size() == w2.size());
    unordered_map<char, int> pairing;
    unordered_map<int, char> rpairing;
    for (int i = 0; i < w1.size(); ++i)
    {
        auto temp = pairing.find(w1[i]);
        auto temp1 = rpairing.find(digs[i]);
        if (temp == pairing.end()) {
            if (temp1 == rpairing.end())
            {
                pairing[w1[i]] = digs[i];
                rpairing[digs[i]] = w1[i];
            }
            else if (rpairing[digs[i]] != w1[i]) return false;
        }
        else if (pairing[w1[i]] != digs[i]) return false;
    }


    int newDig = 0;
    for (int i = 0; i < w2.size(); ++i)
    {
        newDig *= 10;
        newDig += pairing[w2[i]];
        if (i == 0 && newDig == 0) return false;
    }
    if (isInt(sqrt(newDig))) {
        max_res = max(max_res, newDig);//Get the maximum new digit
        return true;
    }
    return false; 
}

bool isPalindrome(const string &str1)
{
    for(int i = 0; i<str1.size()/2; ++i)
    {
        if(str1[i] != str1[str1.size()-1-i]) return false;
    }
    return true;
}

int main()
{
    ifstream file("anagrams.txt");

    //Read integers
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

    for(int i = 1; i<=max_square; ++i) squares.push_back(i*i);

    //Go through ever word pair
    for(int i = 0; i<words.size(); ++i)
    {
        for(int j = i+1; j<words.size(); ++j)
        {
            if(are_anagrams(words[i], words[j]))//If they are anagrams
            {
                if(isPalindrome(words[i]) && isPalindrome(words[j])) continue;//Make sure to not include palindromes
                for(auto &x : squares)//Go through all the squares
                {
                    auto temp = num_dig(x);
                    if(temp > words[i].size()) break;//If the number of digits of square is greater than numbers of characters in word
                    else if(temp == words[i].size()) {
                        if(anagram_sq_pairs(words[i], words[j], getDigts(x)))//If it is an anagramic square based on current square x
                        {
                            max_res = max(max_res, x);//Get the maximum square number
                        }
                    }
                }
            }
        }
    }
    cout << max_res << endl;
    return 0;
}