#include <iostream>
#include <algorithm>

#define LL long long

LL lcm_naive(int a, int b) {
  for (LL l = 1; l <= (LL) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (LL) a * b;
}


LL lcm_fast(int a, int b) {
    int max = std::max(a, b);

    for (LL l = max; l < (LL) a * b; l+=max) {
        if (l % a == 0 && l % b == 0) {
            return l;
        }
    }

    return (LL) a * b;
}

int main() {
  int a, b;

  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;

  return 0;
}