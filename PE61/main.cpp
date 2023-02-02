#include <set>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

long long tri(int n)
{
    return (n*(n+1))/2;
}

long long sqr(int n)
{
    return n*n;
}

long long pent(int n)
{
    return (n*(3*n-1))/2;
}

long long hex(int n)
{
    return n*(2*n-1);
}

long long hept(int n)
{
    return (n*(5*n-3))/2;
}

long long oct(int n)
{
    return n*(3*n-2);
}

/*Get the parameter given the result*/
long long trin(int n)
{
    return (sqrt(1+8*n)-1)/2;
}

long long sqrn(int n)
{
    return sqrt(n);
}

long long pentn(int n)
{
    return (1+sqrt(1+24*n))/6;
}

long long hexn(int n)
{
    return (1+sqrt(1+8*n))/4;
}

long long heptn(int n)
{
    return (3+sqrt(9+40*n))/10;
}

long long octn(int n)
{
    return (2+sqrt(4+12*n))/6;
}

//initial two digits to detect cyclic results
//used_fig is used to indicate the figurative numbers that were used: eg. square =  1
//usedN is used to indicate the n values that were already used
//vec is the answer
bool hasCycle(int initial, int n, bool used_fig[6], set<int> &usedN, vector<int> &vec)
{
    int n2 = n%100;//Last two digits
    if(n2 < 10)
        return false; 
    
    bool all_used = true;
    //Go through all the figurative numbers
    for(int i = 1; i<6; ++i)
    {
        switch(i)
        {
            case 1:
            {
                if(used_fig[i])
                    break;
                all_used = false;
                //Approximate the corresponding parameter in the figurative number
                //It should be the corresponding parameter or just add one to it
                int nextN = sqrn(n2*100);
                int nextSeq = sqr(nextN);
                if(nextSeq/100 != n2)
                {
                    ++nextN;
                    nextSeq = sqr(nextN);
                }

                if(nextSeq/100 == n2)
                {
                    if(usedN.find(nextN) != usedN.end())
                        break;
                    usedN.insert(nextN);
                    used_fig[i] = true;
                    vec.push_back(n);

                    //Is there a cycle after you update the used_fig and usedN
                    if(hasCycle(initial, nextSeq, used_fig, usedN, vec))
                        return true;

                    vec.pop_back();
                    used_fig[i] = false;
                    auto nn = usedN.find(nextN);
                    if(nn != usedN.end())
                        usedN.erase(nn);
                }
                break;
            }

            case 2:
            {
                if(used_fig[i])
                    break;

                all_used = false;
                int nextN = pentn(n2*100);
                int nextSeq = pent(nextN);
                if(nextSeq/100 != n2)
                {
                    ++nextN;
                    nextSeq = pent(nextN);
                }

                if(nextSeq/100 == n2)
                {
                    if(usedN.find(nextN) != usedN.end())
                        break;
                    usedN.insert(nextN);
                    used_fig[i] = true;
                    vec.push_back(n);
                    if(hasCycle(initial, nextSeq, used_fig, usedN, vec))
                        return true;
                    vec.pop_back();
                    used_fig[i] = false;
                    auto nn = usedN.find(nextN);
                    if(nn != usedN.end())
                        usedN.erase(nn);
                }
                break;
            }

            case 3:
            {
                if(used_fig[i])
                    break;

                all_used = false;
                int nextN = hexn(n2*100);
                int nextSeq = hex(nextN);
                if(nextSeq/100 != n2)
                {
                    ++nextN;
                    nextSeq = hex(nextN);
                }

                if(nextSeq/100 == n2)
                {
                    if(usedN.find(nextN) != usedN.end())
                        break;
                    usedN.insert(nextN);
                    used_fig[i] = true;
                    vec.push_back(n);
                    if(hasCycle(initial, nextSeq, used_fig, usedN, vec))
                        return true;
                    vec.pop_back();
                    used_fig[i] = false;
                    auto nn = usedN.find(nextN);
                    if(nn != usedN.end())
                        usedN.erase(nn);
                }
                break;
            }

            case 4:
            {
                if(used_fig[i])
                    break;

                all_used = false;
                int nextN = heptn(n2*100);
                int nextSeq = hept(nextN);
                if(nextSeq/100 != n2)
                {
                    ++nextN;
                    nextSeq = hept(nextN);
                }

                if(nextSeq/100 == n2)
                {
                    if(usedN.find(nextN) != usedN.end())
                        break;
                    usedN.insert(nextN);
                    used_fig[i] = true;
                    vec.push_back(n);
                    if(hasCycle(initial, nextSeq, used_fig, usedN, vec))
                        return true;
                    vec.pop_back();
                    used_fig[i] = false;
                    auto nn = usedN.find(nextN);
                    if(nn != usedN.end())
                        usedN.erase(nn);
                }
                break;
            }

            case 5:
            {
                if(used_fig[i])
                    break;

                all_used = false;
                int nextN = octn(n2*100);
                int nextSeq = oct(nextN);
                if(nextSeq/100 != n2)
                {
                    ++nextN;
                    nextSeq = oct(nextN);
                }

                if(nextSeq/100 == n2)
                {
                    if(usedN.find(nextN) != usedN.end())
                        break;
                    usedN.insert(nextN);
                    used_fig[i] = true;
                    vec.push_back(n);
                    if(hasCycle(initial, nextSeq, used_fig, usedN, vec))
                        return true;
                    vec.pop_back();
                    used_fig[i] = false;
                    auto nn = usedN.find(nextN);
                    if(nn != usedN.end())
                        usedN.erase(nn);
                }
                break;
            }
        }
    }

    if(all_used)
    {
        if(n2 == initial)
        {
            int sum = 0;
            vec.push_back(n);
            cout << "Sequence: ";
            for(int x : vec)
            {
                cout << x << " ";
                sum += x;
            }
            cout << endl;
            cout << "Sum: " << sum << endl;
            return true;
        }
        return false;
    }
    return false;
}

int main()
{
    
    set<int> usedN;
    bool used_fig[6];
    for(int i = 0; i<6; ++i)
        used_fig[i] = false;
    vector<int> vec;

    for(int i = 45; i<=140; ++i)
    {
        for(int k= 0; k<6; ++k)
            used_fig[k] = false;

        int curr = tri(i);
        if(hasCycle(curr/100, curr, used_fig, usedN, vec))
        {
            return 0;
        }

        usedN.clear();
    }
    return 0;
}