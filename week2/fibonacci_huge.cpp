#include <iostream>
#include <vector>

#define LL long long

LL get_fibonacci_huge_naive(LL n, LL m) {
    if (n <= 1)
        return n;

    LL previous = 0;
    LL current  = 1;

    for (LL i = 0; i < n - 1; ++i) {
        LL tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

LL get_fibonacci_huge_fast(LL n, LL m) {
    if (n <= 1) {
        return n;
    }

    LL 
        previous = 0,
        current  = 1;

    if (n%2 == 0) {
        n*=2;
    }
    
    for (LL i = 0; i < n; ++i) {
        LL tmp_previous = previous;
        previous = current;
        current += tmp_previous;
        std::cout << current % m << std::endl;
    }

    return current % m;
}


int main() {
    LL n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}