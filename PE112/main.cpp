//Most straight forward algorithm
#include <sstream>
#include <iostream>

using namespace std;

bool isBouncy(const long long &n)
{
    stringstream ss;
    ss << n;

    bool less = false;
    for(int i = 0; i<ss.str().size()-1; ++i)
    {
        if((ss.str()[i]-'0')<(ss.str()[i+1]-'0'))
        {
            less = true;
            break;
        }
        else if((ss.str()[i]-'0')>(ss.str()[i+1]-'0'))
        {
            less = false;
            break;
        }
    }

    for(int i = 0; i<ss.str().size()-1; ++i)
    {
        if(less)
        {
            if((ss.str()[i]-'0') > (ss.str()[i+1]-'0'))
                return true;
        }
        else if((ss.str()[i]-'0') < (ss.str()[i+1]-'0'))
            return true;
    }
    return false;
}

int main()
{
    long long total = 0;
    long long num_bouncy = 0;
    long long num = 1;

    while(true)
    {
        if(isBouncy(num))
            ++num_bouncy;
        ++total;
        double ratio = (double)num_bouncy/(double)total;
        if(ratio == 0.99)
        {
            cout << num << endl;
            return 0;
        }
        ++num;
    }
    return 0;
}