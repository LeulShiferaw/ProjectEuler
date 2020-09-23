#include <map>
#include <iostream>

using namespace std;

int num_months[12];



int main()
{

    num_months[0] = 31;
    num_months[1] = 28;
    num_months[2] = 31;
    num_months[3] = 30;
    num_months[4] = 31;
    num_months[5] = 30;
    num_months[6] = 31;
    num_months[7] = 31;
    num_months[8] = 30;
    num_months[9] = 31;
    num_months[10] = 30;
    num_months[11] = 31;
    int curr_day = 2;// 1st 1901 is a tuesday
    int num_sunday = 0;
    for(int i = 1901; i<=2000; ++i)
    {
        for(int j = 0; j < 12; ++j)
        {
            curr_day += num_months[j];
            if(j == 2 && (i%400 == 0))
            {
                curr_day += 1;
            }
            curr_day %= 7;
            if(curr_day == 0)
                ++num_sunday;
        }
    }
    cout << num_sunday << endl;
    return 0;
}
