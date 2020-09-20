#include <algorithm>

using namespace std;

bool is_valid_time(int A, int B, int C, int D)
{
    if (((A * 10 + B) < 24) && (((C * 10) + D) <= 59))
        return true;
    return false;
}

int solution(int A, int B, int C, int D) {
    // write your code in C++14 (g++ 6.2.0)
    //I don't want to spend time to try to figure out how to do the combinatorics with code but it is doable
    int res = 0;
    if (is_valid_time(A, B, C, D))
        res++;
    if (is_valid_time(A, B, D, C))
        res++;
    if (is_valid_time(A, C, B, D))
        res++;
    if (is_valid_time(A, C, D, B))
        res++;
    if (is_valid_time(A, D, B, C))
        res++;
    if (is_valid_time(A, D, C, B))
        res++;
    if (is_valid_time(B, A, C, D))
        res++;
    if (is_valid_time(B, A, D, C))
        res++;
    if (is_valid_time(B, C, A, D))
        res++;
    if (is_valid_time(B, C, D, A))
        res++;
    if (is_valid_time(B, D, A, C))
        res++;
    if (is_valid_time(B, D, C, A))
        res++;
    if (is_valid_time(C, A, B, D))
        res++;
    if (is_valid_time(C, A, D, B))
        res++;
    if (is_valid_time(C, B, A, D))
        res++;
    if (is_valid_time(C, B, D, A))
        res++;
    if (is_valid_time(C, D, A, B))
        res++;
    if (is_valid_time(C, D, B, A))
        res++;
    if (is_valid_time(D, A, B, C))
        res++;
    if (is_valid_time(D, A, C, B))
        res++;
    if (is_valid_time(D, B, A, C))
        res++;
    if (is_valid_time(D, B, C, A))
        res++;
    if (is_valid_time(D, C, A, B))
        res++;
    if (is_valid_time(D, C, B, A))
        res++;

    return res;
}

int main()
{
    
    return 0;
}