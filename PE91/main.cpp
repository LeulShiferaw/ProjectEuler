#include <bits/stdc++.h>

using namespace std;

//m1*m2 == -1. If we use the following inputs for slope 1 and slope 2 then we can get the formula below.
bool are_perpendicular(int chang_x1, int chang_y1, int chang_x2, int chang_y2) {
    long long val1 = chang_y1 * (long long)chang_y2;
    long long val2 = chang_x1 * (long long)chang_x2 * -1;
    return val1 == val2;
}

int main() {
    int N = 50;
    int res = 0;
    for(int x1=0; x1<=N; ++x1) {
        for(int x2 = 0; x2 <= N; ++x2) {
            for(int y1 = 0; y1 <= N; ++y1) {
                for(int y2 =0; y2 <= N; ++y2) {
                    //Special cases if any of the points intersects with eachother or (0, 0)
                    //Then stop
                    if(x1 == 0 && y1 == 0) continue;
                    if(x2 == 0 && y2 == 0) continue;
                    if(x1 == x2 && y1 == y2) continue;
                    //Line1 = (x1, y1) -> (0, 0)
                    //Line2 = (x2, y2) -> (0, 0)
                    //Line3 = (x1, y1) -> (x2, y2)
                    if(are_perpendicular(x1, y1, x2, y2) || are_perpendicular(x1, y1, x1-x2, y1-y2) || are_perpendicular(x2, y2, x1-x2, y1-y2)) {
                        //cout << "(0, 0)" << " " << "(" << x1 << ", " << y1 << ") " << "(" << x2 << ", " << y2 << ")" << endl;
                        ++res;
                    }
                }
            }
        }
    }
    cout << "Answer: " << res/2 << endl; //Divide by two because you can just swap (x1, y1) & (x2, y2) and get the same result.
    return 0;
}