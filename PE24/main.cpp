#include <iostream>

using namespace std;

vector<string> permutation(const string &input)
{
    if(input.size() == 1)
    {
        vector<string> res;
        res.push_back(input);
        return res;
    }

    vector<string> res;
    string part2 = input.substr(1, input.size());
    vector<string> perm_suffix = premutation(part2);
    for(int i = 0; i < prem_suffix.size(); ++i)
    {
        vector<string> temp = put_everywhere(input[0], )
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
