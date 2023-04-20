#include "../helper.h"
#include <iostream>

using namespace std;

int num_divisors(int n)
{
    if(!has_seived)
        seive();

    int res = 1;
    int lim = sqrt(n);
    for(int i = 0; i<pr.size(); ++i)
    {
        int cnt = 1;
        while(n%pr[i] == 0)
        {
            ++cnt;
            n/=pr[i];
        }
        res*=cnt;
        if(n == 1)
            break;
    }    
    return res;
}

void SieveOfEratosthenes(int n, bool prime[],
                        int a[])
{
     
    //For more details check out: https://www.geeksforgeeks.org/sieve-of-eratosthenes/
     
    // Create a boolean array "prime[0..n]" and
    // initialize all entries it as true. A value
    // in prime[i] will finally be false if i is
    // Not a prime, else true.
    for (int i = 2; i <= n; i++)
        prime[i] = true;
 
    // Create a boolean array "primesquare[0..n*n+1]"
    // and initialize all entries it as false. A value
    // in squareprime[i] will finally be true if i is
    // square of prime, else false.
 
    // 1 is not a prime number
    prime[1] = false;
 
    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then
        // it is a prime
        if (prime[p] == true) {
            // Update all multiples of p starting from p * p
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    int j = 0;
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            // Storing primes in an array
            a[j] = p;
 
            // Update value in primesquare[p*p],
            // if p is prime.

            j++;
        }
    }
}
 
bool isPerfectSquare(int n)
{
    if((double)sqrt((double)n) - (int)sqrt(n) == 0)
        return true;
    return false;
}

bool global_prime[10000000 + 1];
int a[10000000];
// Function to count divisors
int countDivisors(int n)
{
    // If number is 1, then it will have only 1
    // as a factor. So, total factors will be 1.
    if (n == 1)
        return 1;
 
 
    // Calling SieveOfEratosthenes to store prime
    // factors of n and to store square of prime
    // factors of n
 
    // ans will contain total number of distinct
    // divisors
    int ans = 1;
 
    // Loop for counting factors of n
    for (int i = 0;; i++) {
        // a[i] is not less than cube root n
        if (a[i] * a[i] * a[i] > n)
            break;
 
        // Calculating power of a[i] in n.
        int cnt = 1; // cnt is power of prime a[i] in n.
        while (n % a[i] == 0) // if a[i] is a factor of n
        {
            n = n / a[i];
            cnt = cnt + 1; // incrementing power
        }
 
        // Calculating the number of divisors
        // If n = a^p * b^q then total divisors of n
        // are (p+1)*(q+1)
        ans = ans * cnt;
    }
 
    // if a[i] is greater than cube root of n
 
    const int x = sqrt(n);
    // First case
    if (global_prime[n])
        ans = ans * 2;

    // Second case
    else if (isPerfectSquare(n) && global_prime[x])
        ans = ans * 3;
 
    // Third case
    else if (n != 1)
        ans = ans * 4;
 
    return ans; // Total divisors
}

int main()
{
    SieveOfEratosthenes(10000000, global_prime, a);
    vector<int> num_div(10000000, 0);
    for(int i = 2; i<10000000; ++i)
    {
        int temp = 0;
        if(!global_prime[i])
        {
            temp = countDivisors(i);
        }
        else temp = 2;
        num_div[i] = temp;
    }

    int res = 0;
    for(int i = 3; i<10000000; ++i)
    {
        if(num_div[i] == num_div[i-1])
            ++res;
    }
    cout << res << endl;
    return 0;
}