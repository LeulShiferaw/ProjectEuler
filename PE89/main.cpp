#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

string roman(int n)
{
    string res = "";
    while(n>=1000)
    {
        res += 'M';
        n-=1000;
    }

    if(n>=900)
    {
        res += "CM";
        n-=900;
    }

    bool usedD = false;
    if(n>=500)
    {
        res+='D';
        n-=500;
        usedD = true;
    }

    if(!usedD && n>=400)
    {
        res+="CD";
        n-=400;
        usedD = true;
    }

    while(n>=100)
    {
        res += "C";
        n-=100;
    }

    if(n>=90)
    {
        res += "XC";
        n-=90;
    }

    bool usedL = false;
    if(n>=50)
    {
        res += "L";
        n-=50;
        usedL = true;
    }

    if(!usedL && n>=40)
    {
        res += "XL";
        n-=40;
        usedL = true;
    }

    while(n>=10)
    {
        res += "X";
        n-=10;
    }

    if(n>=9)
    {
        res += "IX";
        n-=9;
    }

    bool usedV = false;
    if(n>=5)
    {
        res+="V";
        n-=5;
        usedV = true;
    }

    if(!usedV && n>=4)
    {
        res += "IV";
        n-=4;
        usedV = true;
    }

    while(n>=1)
    {
        res += "I";
        n-=1;
    }

    return res;
}

int numRoman(string str)
{
    int res = 0;
    for(int i = 0; i<str.size(); ++i)
    {
        switch(str[i])
        {
            case 'I':
            {
                if(i!=str.size()-1)
                {
                    if(str[i+1] == 'V')
                    {
                        res += 4;
                        ++i;
                        break;
                    }
                    else if(str[i+1] == 'X')
                    {
                        res += 9;
                        ++i;
                        break;
                    }
                }
                ++res;
                break;
            }
            case 'X':
            {
                if(i!=str.size()-1)
                {
                    if(str[i+1] == 'L')
                    {
                        res += 40;
                        ++i;
                        break;
                    }
                    else if(str[i+1] == 'C')
                    {
                        res += 90;
                        ++i;
                        break;
                    }
                }
                res += 10;
                break;
            }
            case 'C':
            {
                if(i!=str.size()-1)
                {
                    if(str[i+1] == 'D')
                    {
                        res += 400;
                        ++i;
                        break;
                    }
                    else if(str[i+1] == 'M')
                    {
                        res += 900;
                        ++i;
                        break;
                    }
                }
                res += 100;
                break;
            }
            case 'V':
                res += 5;
                break;
            case 'L':
                res += 50;
                break;
            case 'D':
                res += 500;
                break;
            case 'M':
                res += 1000;
                break;
        }
    }
    return res;
}

int main()
{
    string old_roman;
    ifstream file("romans.txt");
    int res = 0;
    while(file >> old_roman)
    {
        string new_roman = roman(numRoman(old_roman));
        res += abs((int)new_roman.size() - (int)old_roman.size());
    }
    cout << res << endl;
    return 0;
}