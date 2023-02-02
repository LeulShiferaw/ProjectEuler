#include <set>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

struct Point
{
    int x, y;
    Point() :x(0), y(0) {};
    Point(int a, int b) :x(a), y(b) {};
};

//O is colinear
//1 is Clockwise
//2 is Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

//If the orientation of px, (0, 0), py is the same as the orientation of p1, p2, p3 then (0, 0) is not in the triangle
bool isInterior(const Point& p1, const Point& p2, const Point& p3)
{
    int orien = orientation(p1, p2, p3);
    if (orientation(p1, Point(), p2) == orien || orientation(p2, Point(), p3) == orien || orientation(p3, Point(), p1) == orien)
        return false;
    return true;
}


int main()
{
    ifstream file("triangles.txt");

    vector<vector<Point>> pts;
    for (int i = 0; i < 1000; ++i)
    {
        char c;
        vector<Point> currPts;
        Point x1, x2, x3;
        file >> x1.x >> c >> x1.y >> c >> x2.x >> c >> x2.y >> c >> x3.x >> c >> x3.y;

        currPts.push_back(x1);
        currPts.push_back(x2);
        currPts.push_back(x3);

        pts.push_back(currPts);
    }

    int res = 0;
    for(int i = 0; i<pts.size(); ++i)
    {
        if (isInterior(pts[i][0], pts[i][1], pts[i][2]))
            ++res;
    }
    cout << "Final result: " <<  res << endl;
}
