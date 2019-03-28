#include <iostream>
#include <cassert>

#define LL long long

using namespace std;

int fibonacci_sum_squares_naive(long long n)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

LL fibonacci_sum_squares_fast(LL n)
{
    if (n <= 1)
    {
        return n;
    }

    LL
        a = 0,
        b = 1,
        period = 60, // pisano period is always 60 for mod 10
        sum = 0,
        temp;

    for (LL i = 0; i < n % period; i++)
    {
        sum = sum + (b * b) % 10;
        temp = b;
        b = (a + b) % 10;
        a = temp;
    }

    return sum % 10;
}

int main()
{
    LL n = 0;
    cin >> n;
    cout << fibonacci_sum_squares_fast(n) << endl;
}
