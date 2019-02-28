#include <iostream>
#include <algorithm>

#define LL long long

using namespace std;

LL lcm_naive(int a, int b)
{
  for (LL l = 1; l <= (LL)a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (LL)a * b;
}

int gcd_fast(int a, int b)
{
  return (b == 0) ? a : gcd_fast(b, a % b);
}

LL lcm_fast(LL a, LL b)
{
  return a * b / gcd_fast(a, b);
}

int main()
{
  LL a, b;

  cin >> a;
  cin >> b;
  cout << lcm_fast(a, b) << endl;

  return 0;
}