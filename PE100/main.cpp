#include <cmath>
#include <iostream>

using namespace std;

bool hasIntSol(long long T)
{
    long long U = T*(T-1);
    double discriminant = sqrt(4LL+8LL*U);
    if(discriminant == (long long)discriminant)
    {
        if(((long long)discriminant+2LL)%4 == 0)
            return true;
    }
    return false;
}

int main()
{
	cout << "Hello" << endl;
    long long n;
    while(cin >> n)
    {
        if(hasIntSol(n))
        {
            cout << "It does" << endl;
        }
        else cout << "It doesn't" << endl;
    }
    return 0;
}
