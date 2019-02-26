#include <iostream>
#include <time.h>

#define LL long long

using namespace std;

int fibonacci_sum_naive(LL n) {
    if (n <= 1)
        return n;

    LL previous = 0;
    LL current  = 1;
    LL sum      = 1;

    for (int i = 0; i < n - 1; ++i) {
        LL tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}


int fibonacci_sum_fast(LL n) {
    if (n <= 1) {
        return n;
    }

    int 
        a = 0,
        b  = 1,
        period = 60, // pisano period is always 60 for mod 10
        sum = 0,
        temp;
        
    //     do {
    //         period++;
    //         temp = b;
    //         b = (a + b) % 10;
    //         a = temp;

    //         sum = (sum + b) % 10;

    //     } while (a != 0 || b != 1);

    //     if (n < period) {
    //         cout << "Less than period"
    //         sum = 0;
    //     } else {
    //         sum *= n / period;
    //     }
    // cout << sum << endl;
    // a = 0, b = 1;

    for (LL i = 0; i < n % period; i++) {
        sum = (sum + b) % 10;
        temp = b;
        b = (a + b) % 10;
        a = temp;
    }

    return sum;
}


int main() {
    LL n ;
    cin >> n;
    cout << fibonacci_sum_fast(n) << endl;
}
