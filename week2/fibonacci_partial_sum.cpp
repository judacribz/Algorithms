#include <iostream>
#include <cassert>

#define LL long long

using namespace std;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}
long get_fib_sum(LL n) {
    if (n <= 1) {
        return n;
    }

    long 
        a = 0,
        b  = 1,
        period = 60, // pisano period is always 60 for mod 10
        sum = 0,
        temp;
        

    for (int i = 0; i < n % period; i++) {
        sum = (sum + b);
        temp = b;
        b = (a + b);
        a = temp;
    }

    return sum;
}

long get_fibonacci_partial_sum_fast(LL from, LL to) {
    return ((from == 0) ? get_fib_sum(to) : (get_fib_sum(to) - get_fib_sum(from - 1))) % 10 ;
}

int main() {
    LL from, to;
    cin >> from >> to;

    assert(from <= to);
    assert(from >= 0 && to >= 0);

    cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
