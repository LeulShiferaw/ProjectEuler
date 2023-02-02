#include <set>
#include <iostream>
#include "../helper.h"

using namespace std;

constexpr int lim0 = 50000000;
int lim1 = pow(lim0, 0.5);
int lim2 = pow(lim0, 1/3.0);
int lim3 = pow(lim0, 0.25);


int main()
{
    seive();
    cout << lim1 << endl;
    cout << lim2 << endl;
    cout << lim3 << endl;
    set<int> nums;
    for(int a = 0; a<pr.size(); ++a)
    {
        if(pr[a] > lim1)
            break;
        for(int b = 0; b<pr.size(); ++b)
        {
            if(pr[b] > lim2)
                break;
            if(pow(pr[a], 2) + pow(pr[b], 3) >= lim0)
                break;
            for(int c = 0; c<pr.size(); ++c)
            {
                long long curr_num = pow(pr[a], 2) + pow(pr[b], 3) + pow(pr[c], 4);
                if(pr[c] > lim3)
                    break;
                if(curr_num >= lim0)
                    break;
                nums.insert(curr_num);
            }
        }
    }
    cout << nums.size() << endl;
    return 0;
}