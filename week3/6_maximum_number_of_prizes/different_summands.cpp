#include <iostream>
#include <vector>

#define LL long long

using namespace std;

vector<int> optimal_summands(int n)
{
  vector<int> summands;
  int
      total = 1,
      i = 2,
      temp;

  summands.push_back(1);

  while (total < n)
  {
    temp = (total + i > n) ? n - total : i;

    while (temp <= summands.back())
    {
      temp = temp + summands.back();
      summands.pop_back();
    }

    summands.push_back(temp);
    total += temp;
    i++;
  }

  return summands;
}

int main()
{
  int n;
  cin >> n;
  vector<int> summands = optimal_summands(n);
  cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i)
  {
    cout << summands[i] << ' ';
  }
  cout << endl;
}
