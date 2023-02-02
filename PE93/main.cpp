#include <vector>
#include <iostream>

using namespace std;

vector<int> num_ways(const vector<int> &digits, int prev_val, char prev_op)
{
    vector<int> res;
    vector<int> temp;
    if(prev_op == 's')
    {
        for(int i = 0; i<digits.size(); ++i)
        {
            for(int j = 1; j<=4; ++i)
            {
                switch(j)
                {
                    case 1:
                        temp = num_ways(digits, digits[i], '+');
                        break;
                    case 2:
                        temp = num_ways(digits, digits[i], '-');
                        break;
                    case 3:
                        temp = num_ways(digits, digits[i], '*');
                        break;
                    case 4:
                        temp = num_ways(digits, digits[i], '/');
                }
            }
        }
    }
}

int main()
{

    return 0;
}