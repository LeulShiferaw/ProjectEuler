#include <iostream>

long long gcd(long long a, long long b) {
    while (b) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

long long count(long long N) {
    long long result = 0;
    for (long long u = 1; u * u <= N; ++u) {
        for (long long v = 1; v < u; ++v) {
            if ((u + v) % 2 == 1 && gcd(u, v) == 1) {
                long long a = u * u + v * v;
                long long b = u * u - v * v;
                long long c = 2 * u * v;
                long long p = a + b + c;
                if (p <= N) {
                    result += (N - p) / (2 * a) + 1;
                }
            }
        }
    }
    return result;
}

int main() {
    long long N = 100000000;
    long long result = count(N);
    std::cout << "The count of Pythagorean polygons is: " << result << std::endl;
    return 0;
}
