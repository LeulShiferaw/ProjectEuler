#include <cmath>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

long long sum_divisors(const int &n)
{
    long long res = 1;
    int delm = sqrt(n);
    for(int i = 2; i<=delm; ++i)
    {
        if(n%i == 0)
        {
            res+=i;
            if((n/i) != i)
                res+=(n/i);
        }
    }

    return res;
}

long long addition(const int &n)
{
    return n*(n+1)/2;
}

int main()
{
    vector<int> abund_nums;
    for(int i = 2; i<=28123; ++i)
    {
        if(sum_divisors(i) > i)
            abund_nums.push_back(i);
    }


    cout << abund_nums.size() << endl;
    int num_abund = 0;
    set<int> sum_abund_nums;
    for(int i = 0; i<abund_nums.size(); ++i)
    {
        for(int j = 0; j<abund_nums.size(); ++j)
        {
            if((abund_nums[i]+abund_nums[j]) <= 28123)
            {
                sum_abund_nums.insert(abund_nums[i] + abund_nums[j]);
            }
        }
    }

    long long sum = 0;
    for(auto it = sum_abund_nums.begin(); it != sum_abund_nums.end(); ++it)
    {
        sum+=(*it);
    }
    cout << addition(28123)-sum << endl;
    return 0;
}
