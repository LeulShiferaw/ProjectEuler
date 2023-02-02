#include <ctime>
#include <iostream>

using namespace std;

int rand_num(int l, int h)
{
    return rand() % (h-l+1) + l;
}

int roll_peter()
{
    int sum = 0;
    for(int i = 0; i<9; ++i)
        sum += rand_num(1, 4); 
    return sum;
}

int roll_colin()
{
    int sum = 0;
    for(int i = 0; i<6; ++i)
        sum += rand_num(1, 6);
    return sum;
}

int main()
{
    srand(time(NULL));
    int sz = 10000000;
    int num_peter = 0;
    for(int i = 0; i<sz; ++i)
    {
        if(roll_peter() > roll_colin())
            ++num_peter;
    }
    double res = (double)num_peter/sz;
    cout << num_peter << endl;
    cout << res << endl;
    return 0;
}