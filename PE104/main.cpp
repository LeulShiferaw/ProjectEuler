#include <cmath>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
using namespace boost::multiprecision;

constexpr double phi = 1.618033988749;

bool isPan(const string &nstr)
{
    string str = nstr;
    if(str.size() < 9)
        return false;
    sort(str.begin(), str.end());
    for(int i = 0; i<9; ++i)
    {
        if(str[i] != '1'+i)
            return false;
    }
    return true;
}



int main()
{
    cpp_dec_float_50 phinsq5 = phi*phi*phi/sqrt(5);
    long long flst = 1;
    long long fnlst = 2;
    int n = 3;
    while(true)
    {
        phinsq5 *= phi;
        fnlst += flst;
        flst = fnlst-flst;
        ++n;   

        fnlst %=1000000000LL;
        flst  %=1000000000LL;
        string strlst = to_string(fnlst);

        /*
        if(ffst.str().size() > k || fnfst.str().size() > k)
        {
            ffst = cpp_int(ffst.str().substr(0, k));
            fnfst = cpp_int(fnfst.str().substr(0, k));
        }
        */
        int k = 50;
        if(phinsq5.str().size() >= 3*k)
            phinsq5 = cpp_dec_float_50(phinsq5.str().substr(0, k));

        cpp_int fnfst = (cpp_int)(phinsq5+0.5);
        if(n%100000 == 0)
            cout << n << endl;
        string strfst = fnfst.str().substr(0, (fnfst.str().size() > 9) ? 9 : fnfst.str().size());

        if(n%100000 == 0)
            cout << n << '\n';

        if(isPan(strfst) && isPan(strlst))
        {
            cout << n << endl;
            cin.get();
        }
    }
    return 0;
}