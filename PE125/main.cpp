#include <set>
#include <cmath>
#include <sstream>
#include <iostream>

using namespace std;

bool isPalindrome(const long long &n)
{
    stringstream ss;
    ss << n;
    for(int i = 0; i<ss.str().size()/2; ++i)
    {
        if(ss.str()[i] != ss.str()[ss.str().size()-1-i])
            return false;
    }
    return true;
}

long long sumSq(int n)
{
    return ((long long)n*(long long)(n+1)*(long long)(2*n+1))/6;
}

int main()
{
    set<long long> plnNum;
    long long n = pow(10, 8);
    for(int i = 1; i<=ceil(sqrt(n)); ++i)
    {
        for(int j = 0; j<i-1; ++j)
        {
            long long curr = sumSq(i)-sumSq(j);
            if(curr < n && isPalindrome(curr))
            {
                plnNum.insert(curr);
            }
        }
    }

    long long res = 0;
    for(auto x : plnNum)
        res += x;
    cout << res << endl;
    return 0;
}
