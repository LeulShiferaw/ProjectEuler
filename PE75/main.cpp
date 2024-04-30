#include <bits/stdc++.h>

using namespace std;

/*
    The trick is to use the technique in Putnam and Beyond book for pythagora's diophantine equation
    Use u, v coprime and both not odd at same time to get a = (u*u - v*v), b = (2*u*v), c = (u*u + v*v)
    These will generate the base solutions for pythagoras equation. We will also increment each multiple of these
    equations.
*/
constexpr int L = 1500000;
vector<int> num_solns(L, 0); //Num of solutions for a certain length
vector<int> base_sum_solns;  //The sum of a, b, c, stored to laters get the multiples

void generate_base() {
    int len = ceil(sqrt(L)); //Because the sum 2*u*u + 2*i*j = L at max therefore u is max of about sqrt(L)

    for(int i=1; i<=len; ++i) {
        for(int j=i-1; j>0; j--) {
            if(i%2 ==1 && j%2 == 1) continue; //If both are odd
            if(2*i*i + 2*i*j > L) continue; //The sum of the three terms results in this equation
            if(gcd(i, j) == 1) { //They have to be coprime
                num_solns[2*i*i + 2*i*j]++; //Increment the number of solutions found for this sum
                base_sum_solns.push_back(2*i*i + 2*i*j); //Add them to base_sum_solns
            }
        }
    }
}

int main()
{
    generate_base();

    sort(base_sum_solns.begin(), base_sum_solns.end()); //Sort

    //Go through each and increment all its multiples
    for(int i=0; i<(int)base_sum_solns.size(); ++i) {
        if(i != 0) {
            if(base_sum_solns[i-1] == base_sum_solns[i]) continue;
        }

        for(int j=2*base_sum_solns[i]; j<=L; j+=base_sum_solns[i]) { //2*curr_base, 3*curr_base, 4*curr_base ...
            num_solns[j]++;
        }
    }

    //At the end see how many of them have only 1 number of solutions
    int res = 0;
    for(int i=1; i<=L; ++i) {
        if(num_solns[i] == 1) ++res;
    }
    cout << res << endl;
}
