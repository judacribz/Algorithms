#include <iostream>

using namespace std;

const int COINS[3] = {10, 5, 1};

int get_change(int m, int coinInd)
{
  if (m == 0)
  {
    return 0;
  }

  int coin = COINS[coinInd];

  // in case COINS array does not have 1s
  if (coinInd == sizeof(COINS) / sizeof(coin) - 1)
  {
    return m / coin;
  }

  return m / coin + get_change(m % coin, coinInd + 1);
}

int get_change(int m)
{
  return get_change(m, 0);
}

int main()
{
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}
