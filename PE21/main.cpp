#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> divisors(const int &n)
{
    vector<int> res;
    res.push_back(1);
    int delm = sqrt(n);
    for(int i = 2; i<=delm; ++i)
    {
        if(n%i == 0)
        {
            res.push_back(i);
            if((n/i) != i)
                res.push_back(n/i);
        }
    }
    return res;
}

void display(const vector<int> &vec)
{
    for(int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int sum(const vector<int> &vec)
{
    int sum_res = 0;
    for(int x : vec)
        sum_res += x;
    return sum_res;
}

int main()
{
    int ami_num[10005];
    for(int i = 2; i < 10000; ++i)
    {
        vector<int> temp = divisors(i);
        int temp1 = sum(temp);
        ami_num[i] = temp1;
    }

    long long res = 0;
    for(int i = 2; i<10000; ++i)
    {
        //d(a) = b && d(b) = a => d(d(a)) = a & a != b where b=d(a)
        if(ami_num[i] < 10000 && i != ami_num[i] && ami_num[ami_num[i]] == i)
        {
            res += ami_num[i];
        }
    }

    cout << res << endl;

    return 0;
}
