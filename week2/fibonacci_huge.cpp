#include <iostream>
#include <vector>
#include <time.h>

#define LL long long

using namespace std;

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

int getPisanoPeriod(LL m) {
    int i = 0;
    LL 
        a = 0,
        b  = 1,
        temp;

    do {
        i++;
        temp = b;
        b = (a + b) % m;
        a = temp;
    } while (a != 0 || b != 1);

    // cout << i << " " << a << ", " << b << endl;
    return i;
}

LL get_fibonacci_huge_fast(LL n, LL m) {
    if (n <= 1) {
        return n;
    }

    LL 
        remainder = n % getPisanoPeriod(m),
        a = 0,
        b  = 1,
        temp;
    
    for (int i = 1; i < remainder; ++i) {
        temp = b;
        b = (a + b) % m;
        a = temp;
    }

    return b;
}


LL number = -1;
LL mod;
bool getNumber = false;

LL get_fibonacci_huge_fastest(LL a, LL b, int i) {
    if (a != 0 || b != 1) {
        get_fibonacci_huge_fastest(b, (a + b) % mod, i + 1);
    } else {
		getNumber = true;
		number %= i;
    }

	if (getNumber) {
        if (i == number - 1) {
            number = b;
            getNumber = false;
        }
	}

    return number;
}

LL get_fibonacci_huge_fastest(LL n, LL m) {
    mod = m;
    number = n;
    return get_fibonacci_huge_fastest(1, 1, 1);
}

void timeFunction(LL (*fib)(LL, LL), LL n, LL m) {
    clock_t time_req = clock();
    cout << (*fib)(n, m) << endl;
    cout << clock() - time_req << " ms" << endl;
}


int main() {
    LL n, m;
    cin >> n;
    cin>> m;

    // timeFunction(get_fibonacci_huge_fast, n, m);

    // faster for smaller mods
    // timeFunction(get_fibonacci_huge_fastest, n, m);
    
    cout << get_fibonacci_huge_fastest(n, m) << '\n';
}